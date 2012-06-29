#include "common.h"

#include <cstring>
#include <cstdlib>





#if defined BIOAPI_MEM_DEBUG
static std::map<void*, std::string> biospi_managed_memory;
static pthread_mutex_t              biospi_managed_memory_mutex = PTHREAD_MUTEX_INITIALIZER;
#endif //defined BIOAPI_MEM_DEBUG





void* BioSPI_Malloc  (
    int Lenght, 
    const char* PtrName)
{
    if (Lenght<=0)
        return NULL;
    
    void* mem = malloc(Lenght);

#if defined BIOAPI_MEM_DEBUG
    pthread_mutex_lock(&biospi_managed_memory_mutex);
    biospi_managed_memory[mem] = PtrName;
    pthread_mutex_unlock(&biospi_managed_memory_mutex);
#endif //defined BIOAPI_MEM_DEBUG
    
    return mem;
}





BioAPI_RETURN BioSPI_Free (
    void* Ptr)
{
    if (Ptr == NULL) 
        return BioAPI_OK;
    
#if defined BIOAPI_MEM_DEBUG
    pthread_mutex_lock(&biospi_managed_memory_mutex);
    if (biospi_managed_memory.find(Ptr) == biospi_managed_memory.end()) {
        pthread_mutex_unlock(&biospi_managed_memory_mutex);
        return BioAPIERR_INVALID_POINTER;
    }
    biospi_managed_memory.erase(Ptr);
    pthread_mutex_unlock(&biospi_managed_memory_mutex);
#endif //defined BIOAPI_MEM_DEBUG
    
    free(Ptr);
    return BioAPI_OK;
}





BioAPI_RETURN BioSPI_DebugMemory ()
{
#if defined BIOAPI_MEM_DEBUG
    const char* task_name = "BioSPI_DebugMemory";
    pthread_mutex_lock(&biospi_managed_memory_mutex);
    BioUtil_Log(task_name, "Unreleased pointers:\n");
    for (std::map<void*, std::string>::iterator it=biospi_managed_memory.begin(); it!=biospi_managed_memory.end(); it++) {
        BioUtil_Log(task_name, " - %p - %s\n", it->first, it->second.c_str());
    }
    pthread_mutex_unlock(&biospi_managed_memory_mutex);
    return BioAPI_OK;
#else //defined BIOAPI_MEM_DEBUG    
    return BioAPIERR_FUNCTION_NOT_SUPPORTED;
#endif //defined BIOAPI_MEM_DEBUG    
}
