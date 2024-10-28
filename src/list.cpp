#ifndef LIST_CPP
#define LIST_CPP

#include "list.h"

template <class T>
List<T>::List() {
    this->head = NULL;
}

template <class T>
List<T>::~List() {

}

template <class T>
Task<T>* List<T>::getHead() {
    return this->head;
}

#endif
