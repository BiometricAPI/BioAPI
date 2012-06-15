#include "cancellable.h"
#include <ctime>

Cancellable::Cancellable() {
    pthread_mutex_init(&cancellable_mutex, NULL);
    pthread_cond_init(&cancellable_mutex_cond, NULL);
    cancellable_cancel_count=0;
}

Cancellable::~Cancellable() {
    Cancel();
    pthread_mutex_destroy(&cancellable_mutex);
    pthread_cond_destroy(&cancellable_mutex_cond);
}

bool Cancellable::IsCancelled() {
    return cancellable_cancel_count != 0;
}

bool Cancellable::UseStart(std::string taskName) {
    pthread_mutex_lock(&cancellable_mutex);
    if (cancellable_cancel_count != 0) {
        pthread_mutex_unlock(&cancellable_mutex);
        return false;
    }
    cancellable_tasks[taskName]++;
    pthread_mutex_unlock(&cancellable_mutex);
    return true;
}

void Cancellable::UseEnd(std::string taskName) {
    pthread_mutex_lock(&cancellable_mutex);
    if (--cancellable_tasks[taskName] == 0) {
        cancellable_tasks.erase(taskName);
    }
    if (cancellable_cancel_count != 0 && cancellable_tasks.size() == 0) {
        pthread_cond_broadcast(&cancellable_mutex_cond);
    }
    pthread_mutex_unlock(&cancellable_mutex);
}



void Cancellable::Cancel() {
  CancelAsync();
  CancelJoin();
}



void Cancellable::CancelAsync() {
  pthread_mutex_lock(&cancellable_mutex);
  //Sets this to "Cancelled" state
  cancellable_cancel_count++;
  pthread_mutex_unlock(&cancellable_mutex);
  CancelTasksAsync();
}
   
  
void Cancellable::CancelJoin() {
  pthread_mutex_lock(&cancellable_mutex);
  
  //Wait until all tasks are done
  while (cancellable_tasks.size() != 0) {
    pthread_cond_wait(&cancellable_mutex_cond, &cancellable_mutex);
  }
  
  CancelTasksJoin();
  
  //Done!
  cancellable_cancel_count--;
  pthread_mutex_unlock(&cancellable_mutex);
}


void Cancellable::CancelTasksAsync() {
  //Default implementation does nothing.
  //User implementations may override here to cancel running tasks.
}


void Cancellable::CancelTasksJoin() {
  //Default implementation does nothing.
  //User implementations to wait until operations started by CancelTasksAsync are over.
}


uint64_t Cancellable::Timestamp() {
  struct timespec now;
  clock_gettime(CLOCK_MONOTONIC, &now);
  
  return now.tv_sec*(uint64_t)1000 + now.tv_nsec/(uint64_t)1000000;
}
