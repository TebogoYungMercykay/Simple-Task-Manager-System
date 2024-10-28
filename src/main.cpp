#include <iostream>
#include "manager.h"

void testTodo();
void testTask();
void testWeekly();
void testPriority();
void testHistory();
void testTaskManager();
void printTask(Task<int>* task, bool moreLines = false);

int main() {
    // testTask();
    // testTodo();
    testWeekly();
    // testPriority();
    // testHistory();
    // testTaskManager();

    return 0;
}

void testTask() {
    Task<int> task1(1, "Task 1", false, 23);
    Task<int> task2(2, "Task 2", true, 33);
    Task<int> task3(3, "Task 3", false, 43);

    std::cout << "Description: " << task1.getDescription() << ", Priority: "
              << task1.getPriority() << ", Repeat: " << task1.getRepeat() << ", Data: "
              << task1.getData() << std::endl;

    std::cout << "Description: " << task2.getDescription() << ", Priority: "
              << task2.getPriority() << ", Repeat: " << task2.getRepeat() << ", Data: "
              << task2.getData() << std::endl;

    std::cout << "Description: " << task3.getDescription() << ", Priority: "
              << task3.getPriority() << ", Repeat: " << task3.getRepeat() << ", Data: "
              << task3.getData() << std::endl;

    Task<int> task4(4, "Task 4", false, 23);
    Task<int> task5(4, "Task 4", false, 23);

    std::cout << "Tasks Equal: " << ((task1 == task2) ? "True" : "False") << std::endl << std::endl;
    std::cout << "Tasks Equal: " << ((task4 == task5) ? "True" : "False") << std::endl << std::endl;
    std::cout << "Tasks Equal: " << ((task3 == task5) ? "True" : "False") << std::endl << std::endl;
}

void printTask(Task<int>* task, bool moreLines) {
    if (task == NULL) {
        std::cout << "Task is NULL" << std::endl;
        return;
    } else {
        std::string prevDescription = (task->getPrev() != NULL) ? task->getPrev()->getDescription() : "NULL";
        std::string currDescription = task->getDescription();
        std::string nextDescription = (task->getNext() != NULL) ? task->getNext()->getDescription() : "NULL";

        std::cout << prevDescription << " -> " << currDescription << " -> " << nextDescription << std::endl;
    }

    if (moreLines) {
        std::cout << std::endl;
    }
}

void testPriority() {
    TaskManager<std::string> taskManager("tasks.txt");

    PriorityList<std::string>* priority = taskManager.getPriority();
    Task<std::string>* current = priority->getHead();

    current = priority->getHead();
    std::cout << "Priority List:" << std::endl;
    while (current != NULL) {
        std::cout << "Priority: " << current->getPriority() << ", Description: " << current->getDescription() << std::endl;
        current = current->getNext();
        if (current == priority->getHead()) break;
    }
}

void testHistory() {
    TaskManager<std::string> taskManager("tasks.txt");

    History<std::string>* history = taskManager.getHistory();
    Task<std::string>* current = history->getHead();

    current = history->getHead();
    std::cout << "History:" << std::endl;
    while (current != NULL) {
        std::cout << "Priority: " << current->getPriority() << ", Description: " << current->getDescription() << std::endl;
        current = current->getNext();
        if (current == history->getHead()) break;
    }
}

void testTaskManager() {
    TaskManager<std::string> taskManager("tasks.txt");

    Todo<std::string>* todo = taskManager.getTodo();
    Task<std::string>* current = todo->getHead();
    std::cout << "Todo List:" << std::endl;
    while (current != NULL) {
        std::cout << "Priority: " << current->getPriority() << ", Description: " << current->getDescription() << std::endl;
        current = current->getNext();
        if (current == todo->getHead()) break;
    }
}
