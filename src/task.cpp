#ifndef TASK_CPP
#define TASK_CPP
#include "task.h"

template <class T>
Task<T>::Task(int priority, std::string description, bool repeat, T data) {
    this->priority = priority;
    this->description = description;
    this->repeat = repeat;
    this->data = data;

    // Pointers 
    this->prev = NULL;
    this->next = NULL;
}

template <class T>
Task<T>::Task(const Task<T>& toCopy) {
    this->priority = toCopy.getPriority();
    this->description = toCopy.getDescription();
    this->repeat = toCopy.getRepeat();
    this->data = toCopy.getData();

    // Pointers 
    this->prev = NULL;
    this->next = NULL;
}

template <class T>
Task<T>::~Task() {

}

template <class T>
int Task<T>::getPriority() {
    return 0;
}

template <class T>
std::string Task<T>::getDescription() {
    return "";
}

template <class T>
bool Task<T>::getRepeat() {
    return false;
}

template <class T>
T Task<T>::getData() {
    return new T();
}

template <class T>
Task<T>* Task<T>::getNext() {
    return NULL;
}

template <class T>
Task<T>* Task<T>::getPrev() {
    return NULL;
}

template <class T>
bool Task<T>::setNext(Task<T>* nextTask) {
    return false;
}

template <class T>
bool Task<T>::setPrev(Task<T>* prevTask) {
    return false;
}

template <class T>
bool Task<T>::operator==(const Task<T>& other) {
    return false;
}

#endif
