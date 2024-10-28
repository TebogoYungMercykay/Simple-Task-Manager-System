#ifndef TODO_H
#define TODO_H

#include "list.h"

template <class T>
class Todo: public List<T>
{
    private:
        Task<T>* tail;
    public:
        Todo();
        ~Todo();
        Task<T>* getTail();
        bool addTask(const Task<T>* toAdd);
        bool removeTask(Task<T>* toRemove);
        Task<T>* findTask(int priority);
        Task<T>* findTask(std::string description);
        std::string doTasks();
};

#endif
#include "todo.cpp"
