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

void testTodo() {
    std::cout << "\n=== Testing The Basics ===\n" << std::endl;
    Task<int> task1(1, "Task 1", false, 23);
    Task<int> task2(2, "Task 2", true, 33);
    Task<int> task3(3, "Task 3", false, 43);
    Task<int> task4(4, "Task 4", false, 23);
    Task<int> task5(5, "Task 5", false, 23);

    Todo<int> myTodo;

    std::cout << "Tail: " << myTodo.getHead() << " - " << " Head: " << myTodo.getTail() << std::endl;
    Task<int>* myTask1 = myTodo.findTask(1);
    std::cout << ((myTask1) ? myTask1->getDescription() : "NULL") << std::endl;
    Task<int>* myTask2 = myTodo.findTask("Task 1");
    std::cout << ((myTask2) ? myTask2->getDescription() : "NULL") << std::endl;
    std::cout << myTodo.doTasks() << std::endl;

    myTodo.addTask(&task1);
    std::cout << "Tail: " << myTodo.getHead() << " - " << " Head: " << myTodo.getTail() << std::endl;
    myTask1 = myTodo.findTask(1);
    std::cout << ((myTask1) ? myTask1->getDescription() : "NULL") << std::endl;
    myTask2 = myTodo.findTask("Task 1");
    std::cout << ((myTask2) ? myTask2->getDescription() : "NULL") << std::endl;
    std::cout << myTodo.doTasks() << std::endl;

    myTodo.addTask(&task2);
    std::cout << "Tail: " << myTodo.getHead() << " - " << " Head: " << myTodo.getTail() << std::endl;
    std::cout << myTodo.doTasks() << std::endl;

    myTodo.addTask(&task3);
    myTodo.addTask(&task4);
    std::cout << "Tail: " << myTodo.getHead() << " - " << " Head: " << myTodo.getTail() << std::endl;
    std::cout << myTodo.doTasks() << std::endl;

    myTodo.addTask(&task5);
    std::cout << "Tail: " << myTodo.getHead() << " - " << " Head: " << myTodo.getTail() << std::endl;
    myTask1 = myTodo.findTask(1);
    std::cout << ((myTask1) ? myTask1->getDescription() : "NULL") << std::endl;
    myTask2 = myTodo.findTask("Task 5");
    std::cout << ((myTask2) ? myTask2->getDescription() : "NULL") << std::endl;
    std::cout << myTodo.doTasks() << std::endl;

    std::cout << "\n=== Now Checking Structure ===\n" << std::endl;

    Task<int>* tail = myTodo.getTail();
    Task<int>* head = myTodo.getHead();

    printTask(head, false);
    printTask(tail, false);

    printTask(myTodo.findTask("Task 1"), false);
    printTask(myTodo.findTask("Task 2"), false);
    printTask(myTodo.findTask("Task 3"), false);
    printTask(myTodo.findTask("Task 4"), false);
    printTask(myTodo.findTask("Task 5"), false);

    std::cout << "\n=== Now Testing Delete ===\n" << std::endl;

    myTodo.removeTask(&task5);
    myTask2 = myTodo.findTask("Task 5");
    std::cout << ((myTask2) ? myTask2->getDescription() : "NULL") << std::endl;
    std::cout << myTodo.doTasks() << std::endl;

    myTodo.removeTask(&task4);
    myTask2 = myTodo.findTask("Task 4");
    std::cout << ((myTask2) ? myTask2->getDescription() : "NULL") << std::endl;
    std::cout << myTodo.doTasks() << std::endl;

    myTodo.removeTask(&task3);
    myTask2 = myTodo.findTask("Task 3");
    std::cout << ((myTask2) ? myTask2->getDescription() : "NULL") << std::endl;
    std::cout << myTodo.doTasks() << std::endl;

    myTodo.removeTask(&task2);
    myTask2 = myTodo.findTask("Task 2");
    std::cout << ((myTask2) ? myTask2->getDescription() : "NULL") << std::endl;
    std::cout << myTodo.doTasks() << std::endl;

    myTodo.removeTask(&task1);
    myTask2 = myTodo.findTask("Task 1");
    std::cout << ((myTask2) ? myTask2->getDescription() : "NULL") << std::endl;
    std::cout << myTodo.doTasks() << std::endl;

    myTodo.removeTask(&task1);
    myTask2 = myTodo.findTask("Task 1");
    std::cout << ((myTask2) ? myTask2->getDescription() : "NULL") << std::endl;
    std::cout << myTodo.doTasks() << std::endl;

    myTodo.removeTask(&task5);
    myTask2 = myTodo.findTask("Task 1");
    std::cout << ((myTask2) ? myTask2->getDescription() : "NULL") << std::endl;
    std::cout << myTodo.doTasks() << std::endl;
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

void testWeekly() {
    std::cout << "\n=== Testing The Basics ===\n" << std::endl;
    Task<int> task1(1, "Task 1", false, 23);
    Task<int> task2(2, "Task 2", true, 33);
    Task<int> task3(3, "Task 3", false, 43);
    Task<int> task4(4, "Task 4", false, 23);
    Task<int> task5(5, "Task 5", false, 23);

    WeeklyTasks<int> myWeeklyTasks;

    std::cout << "Tail: " << myWeeklyTasks.getHead() << " - " << " Head: " << myWeeklyTasks.getTail() << std::endl;
    std::cout << myWeeklyTasks.doTasks(3) << std::endl;

    myWeeklyTasks.addTask(&task1);
    std::cout << "Tail: " << myWeeklyTasks.getHead() << " - " << " Head: " << myWeeklyTasks.getTail() << std::endl;
    std::cout << myWeeklyTasks.doTasks(3) << std::endl;

    myWeeklyTasks.addTask(&task2);
    std::cout << "Tail: " << myWeeklyTasks.getHead() << " - " << " Head: " << myWeeklyTasks.getTail() << std::endl;
    std::cout << myWeeklyTasks.doTasks(3) << std::endl;

    myWeeklyTasks.addTask(&task3);
    myWeeklyTasks.addTask(&task4);
    std::cout << "Tail: " << myWeeklyTasks.getHead() << " - " << " Head: " << myWeeklyTasks.getTail() << std::endl;
    std::cout << myWeeklyTasks.doTasks(3) << std::endl;

    myWeeklyTasks.addTask(&task5);
    std::cout << "Tail: " << myWeeklyTasks.getHead() << " - " << " Head: " << myWeeklyTasks.getTail() << std::endl;
    std::cout << myWeeklyTasks.doTasks(3) << std::endl;

    std::cout << "\n=== Now Checking Structure ===\n" << std::endl;

    Task<int>* tail = myWeeklyTasks.getTail();
    Task<int>* head = myWeeklyTasks.getHead();

    printTask(head, true);
    printTask(tail, true);

    std::cout << "\n=== Now Testing Delete ===\n" << std::endl;

    bool deleted = myWeeklyTasks.removeTask(&task1);
    std::cout << myWeeklyTasks.doTasks() << std::endl;
    std::cout << myWeeklyTasks.getNumTasks() << std::endl;
    tail = myWeeklyTasks.getTail();
    head = myWeeklyTasks.getHead();
    printTask(head, true);
    printTask(tail, true);
    printTask(tail->getNext(), true);
    std::cout << "Detete Successful: " << ((deleted) ? "TRUE" : "FALSE") << std::endl << std::endl;

    deleted = myWeeklyTasks.removeTask(&task3);
    std::cout << myWeeklyTasks.doTasks() << std::endl;
    std::cout << myWeeklyTasks.getNumTasks() << std::endl;
    tail = myWeeklyTasks.getTail();
    head = myWeeklyTasks.getHead();
    printTask(head, true);
    printTask(tail, true);
    printTask(tail->getNext(), true);
    std::cout << "Detete Successful: " << ((deleted) ? "TRUE" : "FALSE") << std::endl << std::endl;

    deleted = myWeeklyTasks.removeTask(&task5);
    std::cout << myWeeklyTasks.doTasks() << std::endl;
    std::cout << myWeeklyTasks.getNumTasks() << std::endl;
    tail = myWeeklyTasks.getTail();
    head = myWeeklyTasks.getHead();
    printTask(head, true);
    printTask(tail, true);
    printTask(tail->getNext(), true);
    std::cout << "Detete Successful: " << ((deleted) ? "TRUE" : "FALSE") << std::endl << std::endl;

    deleted = myWeeklyTasks.removeTask(&task2);
    std::cout << myWeeklyTasks.doTasks() << std::endl;
    std::cout << myWeeklyTasks.getNumTasks() << std::endl;
    tail = myWeeklyTasks.getTail();
    head = myWeeklyTasks.getHead();
    printTask(head, true);
    printTask(tail, true);
    std::cout << "Detete Successful: " << ((deleted) ? "TRUE" : "FALSE") << std::endl << std::endl;

    deleted = myWeeklyTasks.removeTask(&task4);
    std::cout << myWeeklyTasks.doTasks() << std::endl;
    std::cout << myWeeklyTasks.getNumTasks() << std::endl;
    tail = myWeeklyTasks.getTail();
    head = myWeeklyTasks.getHead();
    printTask(head, true);
    printTask(tail, true);
    std::cout << "Detete Successful: " << ((deleted) ? "TRUE" : "FALSE") << std::endl << std::endl;

    deleted = myWeeklyTasks.removeTask(&task1);
    std::cout << myWeeklyTasks.doTasks() << std::endl;
    std::cout << myWeeklyTasks.getNumTasks() << std::endl;
    tail = myWeeklyTasks.getTail();
    head = myWeeklyTasks.getHead();
    printTask(head, true);
    printTask(tail, true);
    std::cout << "Detete Successful: " << ((deleted) ? "TRUE" : "FALSE") << std::endl << std::endl;

    deleted = myWeeklyTasks.removeTask(&task5);
    std::cout << myWeeklyTasks.doTasks() << std::endl;
    std::cout << myWeeklyTasks.getNumTasks() << std::endl;
    tail = myWeeklyTasks.getTail();
    head = myWeeklyTasks.getHead();
    printTask(head, true);
    printTask(tail, true);
    std::cout << "Detete Successful: " << ((deleted) ? "TRUE" : "FALSE") << std::endl << std::endl;
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
