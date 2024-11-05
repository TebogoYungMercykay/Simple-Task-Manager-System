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
        std::string priorityString, descriptionValue, repeatString, dataValue;
        
        std::getline(ss, priorityString, '#');
        std::getline(ss, descriptionValue, '#');
        std::getline(ss, repeatString, '#');
        std::getline(ss, dataValue, '#');
        
        std::stringstream priorityStream(priorityString);
        int priorityValue;
        priorityStream >> priorityValue;
        bool repeatValue = (repeatString == "True");

        T data;
        std::stringstream dataStream(dataValue);
        dataStream >> data;

        Task<T>* newTask = new Task<T>(priorityValue, descriptionValue, repeatValue, data);
        todo->addTask(newTask);
        delete newTask;
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
    Task<T>* next = NULL;
    
    while (current != NULL) {
        next = current->getNext();
        
        if (current && current->getRepeat()) {
            weekly->addTask(current);
            todo->removeTask(current);
        }
        
        current = next;
    }
}

template <class T>
void TaskManager<T>::setPriority() {
    if (priority == NULL) {
        priority = new PriorityList<T>();
    }

    Task<T>* current = todo->getHead();
    
    while (current != NULL) {
        Task<T>* next = current->getNext();

        if (!current->getRepeat()) {
            priority->addTask(current);
            todo->removeTask(current);
        }

        current = next;
    }
}

template <class T>
std::string TaskManager<T>::doWeekly(int cycles) {
    std::string result = weekly->doTasks(cycles);
    return result;
}

template <class T>
std::string TaskManager<T>::doPriority(int numTasks) {
    if (priority == NULL || priority->getHead() == NULL) {
        return "Priority Queue Empty";
    }
    
    if (history == NULL) {
        history = new History<T>();
    }
    
    std::string result;
    for (int i = 0; i < numTasks && priority->getTail() != NULL; i++) {
        Task<T>* task = priority->getTail();
        history->addTask(task);
        result += priority->doNTasks(1);
    }

    return result;
}

template <class T>
std::string TaskManager<T>::undoTasks(bool all) {
    if (history == NULL || history->getHead() == NULL) {
        return "Nothing to Undo";
    }
    
    if (priority == NULL) {
        priority = new PriorityList<T>();
    }
    
    std::string result = "";
    if (all == true) {
        while (history->getHead() != NULL) {
            Task<T>* task = history->getHead();
            priority->addTask(task);
            result += history->undoLatest();
        }
    } else {
        Task<T>* task = history->getHead();
        priority->addTask(task);
        return history->undoLatest();
    }
    
    return result;
}

#endif
