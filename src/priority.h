#ifndef PRIORITY_H
#define PRIORITY_H

#include "list.h"
#include "history.h"
#include <sstream>

template <class T>
class PriorityList: public List<T>
{
    private:
        Task<T>* tail;
        int numTasks;
    public:
        PriorityList();
        ~PriorityList();
        Task<T>* getTail();
        int getNumTasks();
        bool addTask(const Task<T>* toAdd);
        bool removeTask();
        std::string doNTasks(int numTasks);
        std::string doTasks();
};


#endif
#include "priority.cpp"
