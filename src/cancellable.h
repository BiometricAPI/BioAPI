#pragma once

#include <string>
#include <map>
#include <pthread.h>
#include "util.h"
 
#define UNIT_DO_CANCELLABLE(unit, task_name, function) \
{ \
    if (!(unit)->UseStart(task_name) ) \
        return BIOAPI_UNIT_ERROR | BioAPIERR_USER_CANCELLED; \
    BioAPI_RETURN ret = (unit)->function; \
    (unit)->UseEnd(task_name); \
    return ret;\
}

class Cancellable {
protected:
    ///Number of calls to \ref Cancel in progress.
    int cancellable_cancel_count;
    ///Which tasks are currently being executed
    std::map<std::string, int> cancellable_tasks;
    ///Mutex used to identify when tasks are started / terminated
    pthread_mutex_t            cancellable_mutex;
    ///Cond used to receive events when the last task ends.
    pthread_cond_t             cancellable_mutex_cond;
public:
    ///Creates a object whose operations can be cancelled
    Cancellable();
    ///Cancels / waits for pending operations, and finally destroys the object. 
    ///You probably want to call Cancel() as the first thing in your subclass destructor.
    ~Cancellable();
    
    
    ///Checks if operations are currently being cancelled, that is, a call to \ref Cancel is in progress.
    bool IsCancelled();
    ///Cancels and waits for all pending operations. Same as calling \ref CancelAsync and \ref CancelJoin.
    void Cancel();
    
    
    ///Sets this to 'cancelled state' and runs \ref CancelTasksAsync(). Must be followed by \ref CancelJoin().
    void CancelAsync();
    ///Waits until all running tasks are terminated, runs \ref CancelTasksJoin and drops the cancelled state. Must be preceeded by \ref CancelAsync().
    void CancelJoin();
    
    ///Subclass implementation begins to tell tasks to terminate as soon as possible. Must be followed by \ref CancelTasksJoin.
    virtual void CancelTasksAsync();
    ///Subclass implementation waits running tasks to terminate. Must be preceeded by \ref CancelTasksAsync().
    virtual void CancelTasksJoin();

    
    
    ///Mark this object as "in use". returns \a false for the error \a BioAPIERR_USER_CANCELLED.
    bool UseStart(std::string taskName);
    ///Releases an object after it has been used.
    void UseEnd(std::string taskName);
    
    static uint64_t Timestamp();
};
