#ifndef TODO_CPP
#define TODO_CPP

#include "todo.h"

template <typename T>
Todo<T>::Todo() : List<T>() {
    this->tail = NULL;
}

template <typename T>
Todo<T>::~Todo() {
    Task<T>* current = this->head;
    while (current != NULL) {
        Task<T>* next = current->getNext();
        delete current;
        current = next;
    }

    this->head = NULL;
    this->tail = NULL;
}

template <typename T>
Task<T>* Todo<T>::getTail() {
    return this->tail;
}

template <typename T>
bool Todo<T>::addTask(const Task<T>* toAdd) {
    if (toAdd != NULL) {
        Task<T>* newTask = new Task<T>(*toAdd);

        if (this->head == NULL) {
            this->head = newTask;
            this->tail = newTask;
        } else {
            this->tail->setNext(newTask);
            newTask->setPrev(this->tail);
            this->tail = newTask;
        }

        return true;
    }

    return false;
}

template <typename T>
bool Todo<T>::removeTask(Task<T>* toRemove) {
    if (toRemove != NULL && this->head != NULL) {
        for (Task<T>* current = this->head; current != NULL; current = current->getNext()) {
            if (*current == *toRemove) {
                if (current->getPrev() == NULL) {
                    this->head = current->getNext();
                } else {
                    current->getPrev()->setNext(current->getNext());
                }

                if (current->getNext() == NULL) {
                    this->tail = current->getPrev();
                } else {
                    current->getNext()->setPrev(current->getPrev());
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
    for (Task<T>* current = this->head; current != NULL; current = current->getNext()) {
        if (current->getPriority() == priority) {
            return current;
        }
    }

    return NULL;
}

template <typename T>
Task<T>* Todo<T>::findTask(std::string description) {
    for (Task<T>* current = this->head; current != NULL; current = current->getNext()) {
        if (current->getDescription() == description) {
            return current;
        }
    }

    return NULL;
}

template <typename T>
std::string Todo<T>::doTasks() {
    std::string result = "";
    for (Task<T>* current = this->head; current != NULL; current = current->getNext()) {
        result += current->getDescription() + "\n";
    }

    return result;
}

#endif
