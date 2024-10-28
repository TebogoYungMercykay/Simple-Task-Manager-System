#ifndef TODO_CPP
#define TODO_CPP

#include "todo.h"

template <typename T>
Todo<T>::Todo() : List<T>() {
    this->tail = NULL;
}

template <typename T>
Todo<T>::~Todo() {
    if (this->head != NULL) {
        Task<T>* nextTask = NULL;
        for (Task<T>* current = this->head; current != NULL; current = nextTask) {
            nextTask = current->next;
            delete current;
        }

        this->head = NULL;
        this->tail = NULL;
    }
}

template <typename T>
Task<T>* Todo<T>::getTail() {
    return this->tail;
}

template <typename T>
bool Todo<T>::addTask(const Task<T>* toAdd) {
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
        } else {
            this->tail->next = newTask;
            newTask->prev = this->tail;
            this->tail = newTask;
        }

        return true;
    }

    return false;
}

template <typename T>
bool Todo<T>::removeTask(Task<T>* toRemove) {
    if (toRemove != NULL && this->head != NULL) {
        for (Task<T>* current = this->head; current != NULL; current = current->next) {
            if (current == toRemove) {
                if (current->prev == NULL) {
                    this->head = current->next;
                } else {
                    current->prev->next = current->next;
                }

                if (current->next == NULL) {
                    this->tail = current->prev;
                } else {
                    current->next->prev = current->prev;
                }

                delete current;
                return true;
            }
        }
    }

    return false;
}

template <typename T>
Task<T>* Todo<T>::findTask(int priority) {
    for (Task<T>* current = this->head; current != NULL; current = current->next) {
        if (current->getPriority() == description) {
            return current;
        }
    }

    return NULL;
}

template <typename T>
Task<T>* Todo<T>::findTask(std::string description) {
    for (Task<T>* current = this->head; current != NULL; current = current->next) {
        if (current->getDescription() == description) {
            return current;
        }
    }

    return NULL;
}

template <typename T>
std::string Todo<T>::doTasks() {
    std::string result = "";
    for (Task<T>* current = this->head; current != NULL; current = current->next) {
        result += current->getDescription() + "\n";
    }

    return result;
}

#endif
