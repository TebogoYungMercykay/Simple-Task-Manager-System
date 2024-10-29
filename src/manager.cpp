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
        
        std::stringstream priorityStream(priority_str);
        int priorityValue;
        priorityStream >> priorityValue;
        
        bool repeatValue = (repeatString == "True");
        
        Task<T>* newTask = new Task<T>(priorityValue, descriptionValue, repeatValue, dataValue);
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
        
        if (current->task && current->task->getRepeat()) {
            weekly->addTask(current->task);
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
    std::string result = weekly->doTasks(cycles);
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
    for (int i = 0; i < numTasks && priority->getTail() != NULL; i++) {
        Task<T>* task = priority->getTail();
        result += doNTasks(1);
        history->addTask(task);
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
    
    std::string result = "";
    if (all == true) {
        while (!history->getHead() != NULL) {
            Task<T>* task = history->getHead();
            result += history->undoLatest();
            priority->addTask(task);
        }
    } else {
        Task<T>* task = history->getHead();
        priority->addTask(task);
        return history->undoLatest();
    }
    
    return result;
}

#endif
