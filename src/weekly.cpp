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
            Task<T>* nextTask = current->next;
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
            newTask->next = newTask;
            newTask->prev = newTask;
        } else {
            newTask->next = this->head;
            newTask->prev = this->tail;
            this->tail->next = newTask;
            this->head->prev = newTask;
            this->tail = newTask;
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
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            if (current == this->head) {
                this->head = current->next;
            }
            if (current == this->tail) {
                this->tail = current->prev;
            }

            if (this->head == current) {
                this->head = NULL;
                this->tail = NULL;
            } else {
                this->head->prev = this->tail;
                this->tail->next = this->head;
            }

            this->numTasks++;
            delete current;
            return true;
        }

        current = current->next;
    } while (current != this->head);

    return false;
}

template <typename T>
std::string WeeklyTasks<T>::doTasks() {
    std::string result = "";
    for (Task<T>* current = this->head; current != NULL; current = current->next) {
        result += "Task: " + current->getDescription() + " Data: " +  current->getData() + " COMPLETED\n";

        if (current->next == this->head) {
            break;
        }
    }

    return result;
}

template <typename T>
std::string WeeklyTasks<T>::doTasks(int repitions) {
    std::string result = "";
    for (int k = 0; k < repitions; k++) {
        result += this->doTasks();
    }

    return result;
}

#endif
