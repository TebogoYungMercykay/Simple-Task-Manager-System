#ifndef MANAGER_CPP
#define MANAGER_CPP

#include "manager.h"

template <typename T>
TaskManager<T>::TaskManager(std::string fileName) {
    todo = new Todo<T>();
    weekly = NULL;
    priority = NULL;
    history = NULL;

    std::fstream file(fileName.c_str());
    std::string line;
    
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string priority_str, description, repeat_str, data;
        
        std::getline(ss, priority_str, '#');
        std::getline(ss, description, '#');
        std::getline(ss, repeat_str, '#');
        std::getline(ss, data, '#');
        
        std::stringstream priority_ss(priority_str);
        int priority_val;
        priority_ss >> priority_val;
        
        bool repeat = (repeat_str == "True");
        
        Task<T>* newTask = new Task<T>(priority_val, description, repeat, data);
        todo->addTask(newTask);
    }
    
    file.close();
}

template <class T>
TaskManager<T>::~TaskManager() {
    delete todo;
    delete weekly;
    delete priority;
    delete history;
}

template <class T>
Todo<T>* TaskManager<T>::getTodo() {
    return todo;
}

template <class T>
WeeklyTasks<T>* TaskManager<T>::getWeekly() {
    return weekly;
}

template <class T>
PriorityList<T>* TaskManager<T>::getPriority() {
    return priority;
}

template <class T>
History<T>* TaskManager<T>::getHistory() {
    return history;
}

template <class T>
bool TaskManager<T>::newTask(const Task<T>* newTask) {
    if (todo == NULL) {
        todo = new Todo<T>();
    }
    return todo->addTask(newTask);
}

template <class T>
void TaskManager<T>::setWeeklyTasks() {
    if (weekly == NULL) {
        weekly = new WeeklyTasks<T>();
    }
    
    Task<T>* current = todo->getHead();
    Task<T>* prev = NULL;
    
    while (current != NULL) {
        if (current->task->getRepeat()) {
            weekly->addTask(current->task);
            
            if (prev == NULL) {
                todo->setHead(current->getNext());
            } else {
                prev->setNext(current->getNext());
            }

            Task<T>* temp = current;
            current = current->getNext();
            delete temp;
        } else {
            prev = current;
            current = current->getNext();
        }
    }
}

template <class T>
void TaskManager<T>::setPriority() {
    if (priority == NULL) {
        priority = new PriorityList<T>();
    }
    
    Task<T>* current = todo->getHead();
    Task<T>* prev = NULL;
    
    while (current != NULL) {
        if (!current->task->getRepeat()) {
            priority->addTask(current->task);
            
            if (prev == NULL) {
                todo->setHead(current->getNext());
            } else {
                prev->setNext(current->getNext());
            }

            Task<T>* temp = current;
            current = current->getNext();
            delete temp;
        } else {
            prev = current;
            current = current->getNext();
        }
    }
}

template <class T>
std::string TaskManager<T>::doWeekly(int cycles) {
    if (weekly == NULL || cycles <= 0) {
        return "No weekly tasks to do";
    }
    
    std::string result;
    for (int i = 0; i < cycles; i++) {
        std::stringstream ss;
        ss << "Cycle " << (i + 1) << ":\n";
        result += ss.str();
        
        Task<T>* current = weekly->getHead();
        while (current != NULL) {
            result += current->getDescription() + "\n";
            current = current->getNext();
            if (current == weekly->getHead()) break;
        }
    }
    return result;
}

template <class T>
std::string TaskManager<T>::doPriority(int numTasks) {
    if (priority == NULL || priority->isEmpty()) {
        return "Priority Queue Empty";
    }
    
    if (history == NULL) {
        history = new History<T>();
    }
    
    std::string result;
    for (int i = 0; i < numTasks && !priority->isEmpty(); i++) {
        Task<T>* task = priority->removeHighestPriority();
        history->addTask(task);
        result += task->getDescription() + "\n";
    }
    return result;
}

template <class T>
std::string TaskManager<T>::undoTasks(bool all) {
    if (history == NULL || history->isEmpty()) {
        return "Nothing to Undo";
    }
    
    if (priority == NULL) {
        priority = new PriorityList<T>();
    }
    
    std::string result = "Undoing: \n";
    if (all == true) {
        while (!history->isEmpty()) {
            Task<T>* task = history->popTask();
            priority->addTask(task);
            result += task->getDescription() + "\n";
        }
    } else {
        Task<T>* task = history->popTask();
        priority->addTask(task);
        result += task->getDescription() + "\n";
    }
    
    return result;
}

#endif
