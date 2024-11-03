#ifndef TASK_CPP
#define TASK_CPP

#include "task.h"

template <typename T>
Task<T>::Task(int priority, std::string description, bool repeat, T data) {
    this->priority = priority;
    this->description = description;
    this->repeat = repeat;
    this->data = data;

    // Pointers 
    this->prev = NULL;
    this->next = NULL;
}

template <typename T>
Task<T>::Task(const Task<T>& toCopy) {
    this->priority = toCopy.priority;
    this->description = toCopy.description;
    this->repeat = toCopy.repeat;
    this->data = toCopy.data;

    // Pointers 
    this->prev = NULL;
    this->next = NULL;
}

template <typename T>
Task<T>::~Task() {

}

template <typename T>
int Task<T>::getPriority() {
    return this->priority;
}

template <typename T>
std::string Task<T>::getDescription() {
    return this->description;
}

template <typename T>
bool Task<T>::getRepeat() {
    return this->repeat;
}

template <typename T>
T Task<T>::getData() {
    return this->data;
}

template <typename T>
Task<T>* Task<T>::getNext() {
    return this->next;
}

template <typename T>
Task<T>* Task<T>::getPrev() {
    return this->prev;
}

template <typename T>
bool Task<T>::setNext(Task<T>* nextTask) {
    this->next = nextTask;
    return true;
}

template <typename T>
bool Task<T>::setPrev(Task<T>* prevTask) {
    this->prev = prevTask;
    return true;
}

template <typename T>
bool Task<T>::operator==(const Task<T>& other) {
    return (
        this->priority == other.priority &&
        this->description == other.description &&
        this->repeat == other.repeat &&
        this->data == other.data
    );
}

#endif
