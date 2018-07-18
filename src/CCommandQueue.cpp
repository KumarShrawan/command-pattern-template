#include <cassert>
#include <algorithm>
#include <iostream>

#include "CCommandQueue.h"

namespace SvcIpc{

CCommandQueue::CCommandQueue()
{
	pthread_mutex_init(&commandQueueLock, NULL);
	pthread_cond_init(&condvar, NULL);
}

CCommandQueue::~CCommandQueue()
{
	pthread_mutex_destroy(&commandQueueLock);
	pthread_cond_destroy(&condvar);
}

ICommand* CCommandQueue::get()
{
	ICommand* command = NULL;
    pthread_mutex_lock(&commandQueueLock);
    //cout << "Element count before removal " << commandQueue.size() << endl;
    // Calling "front" function on an empty container causes undefined behavior.
    while(1){
    	if( commandQueue.size()){
            command = commandQueue.front();
            commandQueue.pop_front();
            assert( 0 != command );
			break;
        }
        else{
        	// Queue is empty, wait for the command to appear (signalled by postEvent).
        	pthread_cond_wait (&condvar, &commandQueueLock);
        }
    }
    //cout << "Element count after removal " << commandQueue.size() << endl;
    pthread_mutex_unlock(&commandQueueLock);
    return command;
}

void CCommandQueue::post(ICommand* command)
{
    pthread_mutex_lock(&commandQueueLock);
    commandQueue.push_back(command);
    pthread_cond_signal (&condvar);
    pthread_mutex_unlock(&commandQueueLock);
}

void CCommandQueue::postFront(ICommand* command)
{
    pthread_mutex_lock(&commandQueueLock);
    commandQueue.push_front(command);
    pthread_cond_signal (&condvar);
    pthread_mutex_unlock(&commandQueueLock);
}

}