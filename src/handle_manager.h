#pragma once

#include "common.h"

template<class T> 
struct HandleEntry 
{
    T* data;
    int references;
    bool free;
#if defined BIOAPI_HANDLE_DEBUG
    std::string handleName;
#endif //defined BIOAPI_HANDLE_DEBUG
};

template<class H, class T> 
class HandleManager 
{
public:
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
        //Releases forgotten handles
        for (typename std::map<H, HandleEntry<T>*>::iterator it=allocatedHandles.begin(); it!=allocatedHandles.end(); it++) {
            HandleEntry<T>* entry = it->second;
#if defined BIOAPI_HANDLE_DEBUG
            BioUtil_Log("%s: Releasing forgotten handle #%i (%s) - references=%i, releasing=%s\n", 
                        "~HandleManager", (int)it->first, entry->handleName.c_str(), entry->references, entry->free?"true":"false");
#endif //defined BIOAPI_HANDLE_DEBUG
            FREE(entry->data);
            delete entry;
        }
        
        pthread_mutex_destroy(&mutex);
    }

    
    
    
    
    H Put(T* data, const char* handleName, H new_handle=-1) 
    {
        if (data == NULL)
            return -1;
        
        pthread_mutex_lock(&mutex);
        if (new_handle >= 0) {
          //User provided a Handle! Yay!
        } else if (freeHandles.size()) {
            new_handle = *(freeHandles.begin());
            freeHandles.erase(new_handle);
        } else if (allocatedHandles.size()) {
            new_handle = (freeHandles.end()-1)->first + 1;
        } else {
            new_handle = 1;
        }
        
        if (allocatedHandles.find(new_handle) != allocatedHandles.end()) {
            BioUtil_Log("Tried to overwrite Handle #%i (%s)\n", (int) new_handle, handleName);
            exit(1);
        }
        
        HandleEntry<T>* entry = allocatedHandles[new_handle] = new HandleEntry<T>();
        entry->data = data;
#if defined BIOAPI_HANDLE_DEBUG
        entry->handleName = handleName;
#endif //defined BIOAPI_HANDLE_DEBUG
        entry->references = 0;
        entry->free = false;
        
        pthread_mutex_unlock(&mutex);
    }
    
    
    
    T* Get(H handle, const char* taskName) {
        pthread_mutex_lock(&mutex);
        
        if (allocatedHandles.find(handle) == allocatedHandles.end()) {
#if defined BIOAPI_HANDLE_DEBUG
            BioUtil_Log("%s: Cannot read unknown handle #%i\n", taskName, (int)handle); 
#endif //defined BIOAPI_HANDLE_DEBUG
            pthread_mutex_unlock(&mutex);
            return NULL;
        }
        
        HandleEntry<T>* entry = allocatedHandles[handle];
        if (entry->free) {
#if defined BIOAPI_HANDLE_DEBUG
            BioUtil_Log("%s: Cannot read removed handle #%i (%s)\n", taskName, (int)handle, entry->handleName.c_str() ); 
#endif //defined BIOAPI_HANDLE_DEBUG
            pthread_mutex_unlock(&mutex);
            return NULL;
        }

        entry->references++;
       
        T* ret = entry->data;
        pthread_mutex_unlock(&mutex);
        return ret;
    }
    
    
    
    void Release(H handle, const char* taskName, bool remove=false) {
        pthread_mutex_lock(&mutex);
        
        if (allocatedHandles.find(handle) == allocatedHandles.end()) {
#if defined BIOAPI_HANDLE_DEBUG
            BioUtil_Log("%s: Cannot release unknown handle #%i\n", taskName, (int)handle); 
#endif //defined BIOAPI_HANDLE_DEBUG
            pthread_mutex_unlock(&mutex);
            return;
        }
        
        HandleEntry<T>* entry = allocatedHandles[handle];
        entry->references--;
        
        if (entry->references <  0) {
#if defined BIOAPI_HANDLE_DEBUG
            BioUtil_Log("%s: Release() without Get() on handle #%i (%s)\n", taskName, (int)handle, entry->handleName.c_str() ); 
#endif //defined BIOAPI_HANDLE_DEBUG
            entry->references = 0;
            pthread_mutex_unlock(&mutex);
            return;
        }
        
        if (remove) 
            entry->free = true;
        
        if (entry->free) {
            if  (entry->references==0) {
                FREE(entry->data);
                allocatedHandles.erase(handle);
                freeHandles.insert(handle);
                delete entry;
            } else {
#if defined BIOAPI_HANDLE_DEBUG
                BioUtil_Log("%s: postponing removal of busy handle #%i (%s)\n", taskName, (int)handle, entry->handleName.c_str() );
#endif //defined BIOAPI_HANDLE_DEBUG
            }
        }
        
        pthread_mutex_unlock(&mutex);
    }
    
    
    
    bool Remove(H handle, const char* taskName) {
        pthread_mutex_lock(&mutex);
        
        if (allocatedHandles.find(handle) == allocatedHandles.end()) {
#if defined BIOAPI_HANDLE_DEBUG
                BioUtil_Log("%s: Cannot remove unknown handle #%i\n", taskName, (int)handle );
#endif //defined BIOAPI_HANDLE_DEBUG
            pthread_mutex_unlock(&mutex);
            return false;
        }
        
        HandleEntry<T>* entry = allocatedHandles[handle];
        
        entry->free = true;
        if  (entry->references==0) {
            FREE(entry->data);
            allocatedHandles.erase(handle);
            freeHandles.insert(handle);
            delete entry;
        } else {
#if defined BIOAPI_HANDLE_DEBUG
                BioUtil_Log("%s: postponing removal of busy handle #%i (%s)\n", taskName, (int)handle, entry->handleName.c_str() );
#endif //defined BIOAPI_HANDLE_DEBUG
        }
        
        pthread_mutex_unlock(&mutex);
        return true;
    }
};
