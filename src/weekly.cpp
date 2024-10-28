#ifndef WEEKLY_CPP
#define WEEKLY_CPP

#include "weekly.h"

template <typename T>
WeeklyTasks<T>::WeeklyTasks() : List<T>() {
    this->tail = NULL;
    this->numTasks = 0;
}

template <typename T>
WeeklyTasks<T>::~WeeklyTasks() {
    if (this->head != NULL) {
        Task<T>* current = this->head;
        do {
            Task<T>* nextTask = current->getNext();
            delete current;
            current = nextTask;
        } while (current != this->head);

        this->head = NULL;
        this->tail = NULL;
        this->numTasks = 0;
    }
}

template <typename T>
Task<T>* WeeklyTasks<T>::getTail() {
    return this->tail;
}

template <typename T>
int WeeklyTasks<T>::getNumTasks() {
    return this->numTasks;
}

template <typename T>
bool WeeklyTasks<T>::addTask(const Task<T>* toAdd) {
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
            newTask->setNext(newTask);
            newTask->setPrev(newTask);
        } else {
            Task<T>* current = this->head;
            do {
                if (newTask->getDescription() <= current->getDescription()) {
                    newTask->setNext(current);
                    newTask->setPrev(current->getPrev());
                    current->prev->setNext(newTask);
                    current->setPrev(newTask);
                    
                    if (current == this->head) {
                        this->head = newTask;
                    }
                    break;
                }
                current = current->getNext();
                
                if (current == this->head) {
                    newTask->setNext(this->head);
                    newTask->setPrev(this->tail);
                    this->tail->setNext(newTask);
                    this->head->setPrev(newTask);
                    this->tail = newTask;
                    break;
                }
            } while (true);
        }

        this->numTasks++;
        return true;
    }
    return false;
}

template <typename T>
bool WeeklyTasks<T>::removeTask(Task<T>* toRemove) {
    if (toRemove == NULL || this->head == NULL) {
        return false;
    }

    Task<T>* current = this->head;
    do {
        if (current == toRemove) {
            if (this->numTasks == 1) {
                this->head = NULL;
                this->tail = NULL;
            } else {
                current->prev->setNext(current->next);
                current->next->setPrev(current->getPrev());
                
                if (current == this->head) {
                    this->head = current->getNext();
                }
                if (current == this->tail) {
                    this->tail = current->getPrev();
                }
            }
            
            delete current;
            this->numTasks--;
            return true;
        }
        current = current->getNext();
    } while (current != this->head);

    return false;
}

template <typename T>
std::string WeeklyTasks<T>::doTasks() {
    if (this->head == NULL) {
        return "";
    }
    
    std::string result = "";
    Task<T>* current = this->head;
    do {
        result += "Task: " + current->getDescription() + " Data: " + current->getData() + " COMPLETED\n";
        current = current->getNext();
    } while (current != this->head);

    return result;
}

template <typename T>
std::string WeeklyTasks<T>::doTasks(int repetitions) {
    if (repetitions <= 0 || this->head == NULL) {
        return "";
    }
    
    std::string result = "";
    for (int i = 0; i < repetitions; i++) {
        result += this->doTasks();
    }
    
    return result;
}

#endif
