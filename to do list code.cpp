#include <bits/stdc++.h>
struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class ToDoListManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& task) {
        tasks.emplace_back(task);
        std::cout << "Task added: " << task << std::endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks in the list." << std::endl;
        } else {
            std::cout << "\nTo-Do List:" << std::endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". " << tasks[i].description << " - "
                          << (tasks[i].completed ? "Completed" : "Pending") << std::endl;
            }
        }
    }

    void markTaskCompleted(size_t taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].completed = true;
            std::cout << "Task " << taskNumber << " marked as completed." << std::endl;
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }

    void removeTask(size_t taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            std::cout << "Task removed: " << tasks[taskNumber - 1].description << std::endl;
            tasks.erase(tasks.begin() + taskNumber - 1);
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }

    void run() {
        while (true) {
            std::cout << "\nTo-Do List Manager" << std::endl;
            std::cout << "1. Add Task" << std::endl;
            std::cout << "2. View Tasks" << std::endl;
            std::cout << "3. Mark Task as Completed" << std::endl;
            std::cout << "4. Remove Task" << std::endl;
            std::cout << "5. Exit" << std::endl;

            int choice;
            std::cout << "Enter your choice (1-5): ";
            std::cin >> choice;

            if (choice == 1) {
                std::cin.ignore(); // Clear newline character from input buffer
                std::string task;
                std::cout << "Enter the task: ";
                std::getline(std::cin, task);
                addTask(task);
            } else if (choice == 2) {
                viewTasks();
            } else if (choice == 3) {
                size_t taskNumber;
                std::cout << "Enter the task number to mark as completed: ";
                std::cin >> taskNumber;
                markTaskCompleted(taskNumber);
            } else if (choice == 4) {
                size_t taskNumber;
                std::cout << "Enter the task number to remove: ";
                std::cin >> taskNumber;
                removeTask(taskNumber);
            } else if (choice == 5) {
                std::cout << "Exiting To-Do List Manager. Goodbye!" << std::endl;
                break;
            } else {
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }
    }
};

int main() {
    ToDoListManager manager;
    manager.run();
    return 0;
}
