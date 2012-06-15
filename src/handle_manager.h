#pragma once

#include <pthread.h>
#include <map>
#include <set>
#include <string>
#include <iostream>

template<class T> 
struct HandleEntry 
{
  T* data;
  std::string handleName;
  std::map<std::string, int> references;
  bool free;
};

template<class H, class T> 
class HandleManager 
{
    std::map<H, HandleEntry<T>*> allocatedHandles;
    std::set<H> freeHandles;
    pthread_mutex_t mutex;
    void (*FREE)(T*);
    
public:
  
  
  
    HandleManager( void (*FREE)(T*) ) 
    {
        this->FREE = FREE;
        pthread_mutex_init(&mutex, NULL);
    }

    
    
    ~HandleManager() 
    {
        pthread_mutex_destroy(&mutex);
    }
    
    
    
    H put(T* data, const char* handleName) 
    {
        if (data == NULL)
            return -1;
        
        pthread_mutex_lock(&mutex);
        H new_handle;
        if (freeHandles.size()) {
            new_handle = *(freeHandles.begin());
            freeHandles.erase(new_handle);
        } else if (allocatedHandles.size()) {
            new_handle = (freeHandles.end()-1)->first + 1;
        } else {
            new_handle = 1;
        }
        
        HandleEntry<T>* entry = allocatedHandles[new_handle] = new HandleEntry<T>();
        entry->data = data;
        entry->handleName = handleName;
        entry->free = false;
        
        pthread_mutex_unlock(&mutex);
    }
    
    
    
    T* get(H handle, const char* taskName) {
        pthread_mutex_lock(&mutex);
        
        if (allocatedHandles.find(handle) == allocatedHandles.end()) {
            std::cerr << "Handle Manager/" << taskName << ": Cannot read unknown handle #" 
                      << handle << std::endl;
            pthread_mutex_unlock(&mutex);
            return NULL;
        }
        
        HandleEntry<T>* entry = allocatedHandles[handle];
        if (entry->free) {
            std::cerr << "Handle Manager/" << taskName << ": Cannot read handle marked for removal #" 
                      << handle << " (" << entry->handleName << ")" << std::endl;
            pthread_mutex_unlock(&mutex);
            return NULL;
        }
        
        entry->references[taskName]++;
       
        T* ret = entry->data;
        pthread_mutex_unlock(&mutex);
        return ret;
    }
    
    
    
    void release(H handle, const char* taskName, bool remove=false) {
        pthread_mutex_lock(&mutex);
        
        if (allocatedHandles.find(handle) == allocatedHandles.end()) {
            std::cerr << "Handle Manager/" << taskName << ": Cannot release unknown handle #" 
                      << handle << std::endl;
            pthread_mutex_unlock(&mutex);
            return;
        }
        
        HandleEntry<T>* entry = allocatedHandles[handle];
        int references = --entry->references[taskName];
        
        if (references <  0) {
            std::cerr << "Handle Manager/" << taskName << ": release() without get() on handle #" 
                      << handle << " (" << entry->handleName << ")" << std::endl;
            pthread_mutex_unlock(&mutex);
            return;
        }
        
        if (references <= 0) 
            entry->references.erase(taskName);
        
        if (remove) 
            entry->free = true;
        
        if (entry->free) {
            if  (entry->references.size()==0) {
                FREE(entry->data);
                allocatedHandles.erase(handle);
                freeHandles.insert(handle);
                delete entry;
            } else {
                std::cerr << "Handle Manager/" << taskName << ": postponing removal of busy handle #" 
                      << handle << " (" << entry->handleName << ")" << std::endl;
            }
        }
        
        pthread_mutex_unlock(&mutex);
    }
    
    
    
    bool remove(H handle, const char* taskName) {
        pthread_mutex_lock(&mutex);
        
        if (allocatedHandles.find(handle) == allocatedHandles.end()) {
            std::cerr << "Handle Manager/" << taskName << ": Cannot remove unknown handle #" 
                      << handle << std::endl;
            pthread_mutex_unlock(&mutex);
            return false;
        }
        
        HandleEntry<T>* entry = allocatedHandles[handle];
        
        entry->free = true;
        if  (entry->references.size()==0) {
            FREE(entry->data);
            allocatedHandles.erase(handle);
            freeHandles.insert(handle);
            delete entry;
        } else {
            std::cerr << "Handle Manager/" << taskName << ": postponing removal of busy handle #" 
                  << handle << " (" << entry->handleName << ")" << std::endl;
        }
        
        pthread_mutex_unlock(&mutex);
        return true;
    }
};
