#ifndef MANAGER_H
#define MANAGER_H

#include "list.h"
#include "todo.h"
#include "weekly.h"
#include "priority.h"
#include "history.h"

#include <string>
#include <fstream>
#include <sstream>

template <class T>
class TaskManager {
    private:
        Todo<T>* todo;
        WeeklyTasks<T>* weekly;
        PriorityList<T>* priority;
        History<T>* history;
    public:
        TaskManager(std::string fileName);
        ~TaskManager();
        Todo<T>* getTodo();
        WeeklyTasks<T>* getWeekly();
        PriorityList<T>* getPriority();
        History<T>* getHistory();
        bool newTask(const Task<T>* newTask);
        void setWeeklyTasks();
        void setPriority();
        std::string doWeekly(int cycles);
        std::string doPriority(int numTasks);
        std::string undoTasks(bool all);
};

#endif
#include "manager.cpp"
