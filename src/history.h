#ifndef HISTORY_H
#define HISTORY_H

#include "list.h"
#include <sstream>

template <class T>
class History: public List<T> {
    private:
        int numTasks;
    public:
        History();
        ~History();
        int getNumTasks();
        bool addTask(const Task<T>* newTask);
        Task<T>* removeTask();
        std::string undoLatest();
        std::string doTasks();
};

#endif
#include "history.cpp"
