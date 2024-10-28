#ifndef WEEKLY_H
#define WEEKLY_H

#include "list.h"
#include <sstream>

template <class T>
class WeeklyTasks: public List<T> {
    private:
        Task<T>* tail;
        int numTasks;
    public:
        WeeklyTasks();
        ~WeeklyTasks();
        Task<T>* getTail();
        int getNumTasks();
        bool addTask(const Task<T>* toAdd);
        bool removeTask(Task<T>* toRemove);
        std::string doTasks();
        std::string doTasks(int repitions);
};

#endif
#include "weekly.cpp"
