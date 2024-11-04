#ifndef WEEKLY_CPP
#define WEEKLY_CPP

#include "weekly.h"

template <typename T>
WeeklyTasks<T>::WeeklyTasks() : List<T>() {
    this->tail = NULL;
    this->numTasks = 0;
}

template <typename T>
WeeklyTasks<T>::~WeeklyTasks() {
    if (this->head != NULL) {
        Task<T>* current = this->head;
        Task<T>* nextTask;

        do {
            nextTask = current->getNext();
            delete current;
            current = nextTask;
        } while (current != this->head);

        this->head = NULL;
        this->tail = NULL;
        this->numTasks = 0;
    }
}

template <typename T>
Task<T>* WeeklyTasks<T>::getTail() {
    return this->tail;
}

template <typename T>
int WeeklyTasks<T>::getNumTasks() {
    return this->numTasks;
}

template <typename T>
bool WeeklyTasks<T>::addTask(const Task<T>* toAdd) {
    if (toAdd != NULL) {
        Task<T>* newTask = new Task<T>(*toAdd);

        if (this->tail == NULL) {
            this->head = newTask;
            this->tail = newTask;
            this->head->setNext(this->tail);
            this->tail->setNext(this->head);
            this->numTasks++;
            return true;
        } else if (newTask->getDescription() <= this->head->getDescription()) {
            newTask->setNext(this->head);
            this->tail->setNext(newTask);
            this->head = newTask;
            this->numTasks++;
            return true;
        } else if (newTask->getDescription() > this->tail->getDescription()) {
            this->tail->setNext(newTask);
            newTask->setNext(this->head);
            this->tail = newTask;
            this->numTasks++;
            return true;
        } else {
            Task<T>* current = this->head;
            Task<T>* previous = this->tail;

            do {
                if (newTask->getDescription() <= current->getDescription()) {
                    newTask->setNext(current);
                    previous->setNext(newTask);
                    this->numTasks++;
                    return true;
                }

                previous = current;
                current = current->getNext();
            } while (current != this->head);
        }
    }

    return false;
}

template <typename T>
bool WeeklyTasks<T>::removeTask(Task<T>* toRemove) {
    if (toRemove == NULL || this->tail == NULL) {
        return false;
    }

    Task<T>* current = this->head;
    Task<T>* previous = this->tail;

    do {
        if (*current == *toRemove) {
            if (this->numTasks == 1) {
                this->tail = NULL;
                this->head = NULL;

                delete current;
                this->numTasks--;
                return true;
            } else {
                if (current == this->head) {
                    this->head = current->getNext();
                    this->tail->setNext(this->head);
                } else if (current == this->tail) {
                    this->tail = previous;
                    this->tail->setNext(this->head);
                } else {
                    previous->setNext(current->getNext());
                }

                delete current;
                this->numTasks--;
                return true;
            }
        }
        previous = current;
        current = current->getNext();
    } while (current != this->head);

    return false;
}

template <typename T>
std::string WeeklyTasks<T>::doTasks() {
    if (this->head == NULL) {
        return "";
    }

    std::string result = "";
    if (this->head != NULL) {
        Task<T>* current = this->head;

        do {
            std::stringstream ss;
            ss << "Task: " << current->getDescription() << " Data: " << current->getData() << " COMPLETED\n";
            result += ss.str();

            current = current->getNext();
        } while (current != this->head);
    }

    return result;
}

template <typename T>
std::string WeeklyTasks<T>::doTasks(int repetitions) {
    if (repetitions <= 0 || this->tail == NULL) {
        return "";
    }
    
    std::string result = "";
    for (int i = 0; i < repetitions; i++) {
        result += this->doTasks();
    }
    
    return result;
}

#endif
