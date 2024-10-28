#ifndef LIST_H
#define LIST_H

#include "task.h"

template <class T>
class List
{
    protected:
        Task<T>* head;
    public:
        List();
        virtual ~List();
        Task<T>* getHead();
        virtual std::string doTasks() = 0;
};

#endif
#include "list.cpp"