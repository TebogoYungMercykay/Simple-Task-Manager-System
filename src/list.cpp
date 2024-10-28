#ifndef LIST_CPP
#define LIST_CPP

#include "list.h"

template <typename T>
List<T>::List() {
    this->head = NULL;
}

template <typename T>
List<T>::~List() {

}

template <typename T>
Task<T>* List<T>::getHead() {
    return this->head;
}

#endif
