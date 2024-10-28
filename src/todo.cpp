#ifndef TODO_CPP
#define TODO_CPP

#include "todo.h"

template <typename T>
Todo<T>::Todo() {

}

template <typename T>
Todo<T>::~Todo() {

}

template <typename T>
Task<T>* Todo<T>::getTail() {

}

template <typename T>
bool Todo<T>::addTask(const Task<T>* toAdd) {

}

template <typename T>
bool Todo<T>::removeTask(Task<T>* toRemove) {

}

template <typename T>
Task<T>* Todo<T>::findTask(int priority) {

}

template <typename T>
Task<T>* Todo<T>::findTask(std::string description) {

}

template <typename T>
std::string Todo<T>::doTasks() {

}

#endif