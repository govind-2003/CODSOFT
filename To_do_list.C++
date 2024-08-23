#include <bits/stdc++.h> 
using namespace std;

void showMenu() {
    cout << "\nTo-Do List Manager\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Delete Task\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    vector<string> tasks;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter the task: ";
                cin.ignore(); 
                string task;
                getline(cin, task);
                tasks.push_back(task);
                cout << "Task added.\n";
                break;
            }
            case 2: {
                if (tasks.empty()) {
                    cout << "No tasks available.\n";
                } else {
                    cout << "To-Do List:\n";
                    for (size_t i = 0; i < tasks.size(); i++) {
                        cout << i + 1 << ". " << tasks[i] << "\n";
                    }
                }
                break;
            }
            case 3: {
                if (tasks.empty()) {
                    cout << "No tasks to delete.\n";
                } else {
                    cout << "Enter the task number to delete: ";
                    int taskNumber;
                    cin >> taskNumber;
                    if (taskNumber > 0 && taskNumber <= tasks.size()) {
                        tasks.erase(tasks.begin() + taskNumber - 1);
                        cout << "Task deleted.\n";
                    } else {
                        cout << "Invalid task number.\n";
                    }
                }
                break;
            }
            case 4: {
                cout << "Exiting the program. Goodbye!\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice != 4);

    return 0;
}
