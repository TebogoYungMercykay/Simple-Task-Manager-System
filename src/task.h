#ifndef TASK_H
#define TASK_H

#include <string>

template <class T>
class Task
{
    private:
        Task<T>* next;
        Task<T>* prev;
        int priority;
        std::string description;
        bool repeat;
        T data;
    public:
        Task(int priority, std::string description, bool repeat, T data);
        Task(const Task<T>& toCopy);
        ~Task();
        int getPriority();
        std::string getDescription();
        bool getRepeat();
        T getData();
        Task<T>* getNext();
        Task<T>* getPrev();
        bool setNext(Task<T>* nextTask);
        bool setPrev(Task<T>* prevTask);
        bool operator==(const Task<T>& other);
};


#endif
#include "task.cpp"
