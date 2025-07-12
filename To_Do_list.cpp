#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

// Function to display the menu
void showMenu() {
    cout << "\n===== TO-DO LIST MANAGER =====" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
}

// Function to add a task
void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter task description: ";
    cin.ignore();  // clear newline
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully." << endl;
}

// Function to view tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks in the list." << endl;
        return;
    }

    cout << "\n--- Your Tasks ---\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description;
        cout << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& tasks) {
    int taskNum;
    cout << "Enter task number to mark as completed: ";
    cin >> taskNum;

    if (taskNum < 1 || taskNum > tasks.size()) {
        cout << "Invalid task number." << endl;
    } else {
        tasks[taskNum - 1].completed = true;
        cout << "Task marked as completed." << endl;
    }
}

// Function to remove a task
void removeTask(vector<Task>& tasks) {
    int taskNum;
    cout << "Enter task number to remove: ";
    cin >> taskNum;

    if (taskNum < 1 || taskNum > tasks.size()) {
        cout << "Invalid task number." << endl;
    } else {
        tasks.erase(tasks.begin() + taskNum - 1);
        cout << "Task removed." << endl;
    }
}

// Main function
int main() {
    vector<Task> tasks;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting To-Do List Manager. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option! Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
