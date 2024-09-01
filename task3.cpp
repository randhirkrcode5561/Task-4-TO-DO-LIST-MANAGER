// Program for TO-DO LIST Manager using C++ programming language.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void displayMenu() 
{
    cout << "\nTo-Do List Manager\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Delete Task\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}

void addTask(vector<string>& tasks) 
{
    cout << "Enter a new task: ";
    string task;
    cin.ignore(); // Ignore leftover newline character
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added successfully.\n";
}

void viewTasks(const vector<string>& tasks) 
{
    if (tasks.empty()) 
    {
        cout << "No tasks available.\n";
        return;
    }

    cout << "Your Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) 
    {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

void deleteTask(vector<string>& tasks) 
{
    viewTasks(tasks);
    if (tasks.empty()) return;

    cout << "Enter the task number to delete: ";
    int taskNumber;
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) 
    {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task deleted successfully.\n";
    }
     else 
    {
        cout << "Invalid task number.\n";
    }
}

int main() 
{
    vector<string> tasks;
    int choice;

    while (true) 
    {
        displayMenu();
        cin >> choice;

        switch (choice) 
        {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }
}