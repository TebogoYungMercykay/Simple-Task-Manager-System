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
    this->priority = toCopy.getPriority();
    this->description = toCopy.getDescription();
    this->repeat = toCopy.getRepeat();
    this->data = toCopy.getData();

    // Pointers 
    this->prev = NULL;
    this->next = NULL;
}

template <typename T>
Task<T>::~Task() {

}

template <typename T>
int Task<T>::getPriority() const {
    return this->priority;
}

template <typename T>
std::string Task<T>::getDescription() const {
    return this->description;
}

template <typename T>
bool Task<T>::getRepeat() const {
    return this->repeat;
}

template <typename T>
T Task<T>::getData() const {
    return this->data;
}

template <typename T>
Task<T>* Task<T>::getNext() const {
    return this->next;
}

template <typename T>
Task<T>* Task<T>::getPrev() const {
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
        this->priority == other.getPriority() &&
        this->description == other.getDescription() &&
        this->repeat == other.getRepeat() &&
        this->data == other.getData()
    );
}

#endif
