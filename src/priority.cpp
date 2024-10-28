#ifndef PRIORITY_CPP
#define PRIORITY_CPP

#include "priority.h"

template <typename T>
PriorityList<T>::PriorityList() : List<T>() {
    this->tail = NULL;
    this->numTasks = 0;
}

template <typename T>
PriorityList<T>::~PriorityList() {
    Task<T>* current = this->head;
    while (current != NULL) {
        Task<T>* next = current->getNext();
        delete current;
        current = next;
    }

    this->head = NULL;
    this->tail = NULL;
    this->numTasks = 0;
}

template <typename T>
Task<T>* PriorityList<T>::getTail() {
    return this->tail;
}

template <typename T>
int PriorityList<T>::getNumTasks() {
    return this->numTasks;
}

template <typename T>
bool PriorityList<T>::addTask(const Task<T>* toAdd) {
    if (toAdd != NULL) {
        Task<T>* newTask = new Task<T>(
            toAdd->getPriority(),
            toAdd->getDescription(),
            toAdd->getRepeat(),
            toAdd->getData()
        );
        
        if (this->head == NULL) {
            this->head = newTask;
            this->tail = newTask;
            newTask->setNext(NULL);
            newTask->setPrev(NULL);
        } else {
            newTask->setNext(this->head);
            newTask->setPrev(NULL);
            this->head->setPrev(newTask);
            this->head = newTask;
        }
        
        this->numTasks++;
        return true;
    }
    return false;
}

template <typename T>
bool PriorityList<T>::removeTask() {
    if (this->tail == NULL) {
        return false;
    }
    
    Task<T>* toRemove = this->tail;
    
    if (this->head == this->tail) {
        this->head = NULL;
        this->tail = NULL;
    } else {
        this->tail = this->tail->getPrev();
        this->tail->setNext(NULL);
    }
    
    delete toRemove;
    this->numTasks--;
    return true;
}

template <typename T>
std::string PriorityList<T>::doNTasks(int numTasksToProcess) {
    if (numTasksToProcess <= 0 || this->tail == NULL) {
        return "";
    }
    
    std::string result;
    std::stringstream ss;

    for (int i = 0; i < numTasksToProcess && this->tail != NULL; i++) {
        ss << "Task: " << this->tail->getDescription() << " Priority: ";
        ss << this->tail->getPriority() << " Data: " << this->tail->getData() << " COMPLETED\n";
        
        removeTask();
    }
    
    return ss.str();
}

template <typename T>
std::string PriorityList<T>::doTasks() {
    std::string result;
    std::stringstream ss;
    
    while (this->tail != NULL) {
        ss << "Task: " << this->tail->getDescription() << " Priority: ";
        ss << this->tail->getPriority() << " Data: " << this->tail->getData() << " COMPLETED\n";
        
        removeTask();
    }
    
    return ss.str();
}

#endif