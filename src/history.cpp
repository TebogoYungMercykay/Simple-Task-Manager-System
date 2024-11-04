#ifndef HISTORY_CPP
#define HISTORY_CPP

#include "history.h"

template <typename T>
History<T>::History() : List<T>() {
    this->numTasks = 0;
}

template <typename T>
History<T>::~History() {
    if (this->head != NULL) {
        Task<T>* doDelete = NULL;
        for (Task<T>* current = this->head; this->head != NULL; ) {
            this->head = this->head->getNext();
            delete current;
            current = NULL;
        }
    }

    this->numTasks = 0;
}

template <typename T>
bool History<T>::addTask(const Task<T>* toAdd) {
    if (toAdd != NULL) {
        Task<T>* newTask = new Task<T>(*toAdd);

        newTask->setNext(this->head);
        this->head = newTask;
        
        this->numTasks++;
        return true;
    }

    return false;
}

template <typename T>
Task<T>* History<T>::removeTask() {
    if (this->head == NULL) {
        return NULL;
    }
    
    Task<T>* removedTask = this->head;
    
    this->head = this->head->getNext();
    removedTask->setNext(NULL);
    
    this->numTasks--;
    return removedTask;
}

template <typename T>
std::string History<T>::undoLatest() {
    Task<T>* task = removeTask();
    if (task == NULL) {
        return "";
    }
    
    std::string result;
    std::stringstream ss;

    ss << "Task: " << task->getDescription() << " Priority: ";
    ss << task->getPriority() << " Data: " << task->getData() << " UNDID\n";
    
    delete task;
    return ss.str();
}

template <typename T>
std::string History<T>::doTasks() {
    std::string result;
    std::stringstream ss;
    
    while (this->head != NULL) {
        Task<T>* task = removeTask();
        
        ss << "Task: " << task->getDescription() << " Priority: ";
        ss << task->getPriority() << " Data: " << task->getData() << " UNDID\n";

        delete task;
    }
   
   return ss.str();
}

#endif
