#include <iostream>
#include <string>
using namespace std;

const int Max_Tasks = 150;      // Maximum number of tasks allowed in the program.

struct Task 
{
    string descpt;
    bool done; 
};

class ToDoList {
    private:
        Task task[Max_Tasks];   // Array to store all tasks.
        int numOfTaks;         // Number of tasks currently stored in the list.

    public:
        ToDoList() : numOfTaks(0) {}     // Default constructor for empty list.

        void addTask (const string &descpt){           // Function to  add a new task to the list.
            if (numOfTaks < Max_Tasks) {
                task[numOfTaks].descpt = descpt;       // Assigning description to the current task.
                task[numOfTaks].done = false;          // Marking it as not completed yet.
                numOfTaks++;                           // Increasing the number of tasks by one.
                cout << "Task added successfully." << endl;
            }
            else {
                cout << "Error! The list is  full!" << endl;
            }
        }

        void viewTask () {
            cout << "Tasks: " << endl;
            for (int i = 0; i < numOfTaks; ++i) {
                cout <<  "\t" << i + 1 << ". ";
                if (task[i].done)
                    cout << "[X] ";
                else
                    cout << "[ ] ";

                cout << task[i].descpt << endl;
            }
        }

        void markAsDone (int index) {              // Function to mark a specific task as done.
            if (index >= 0 && index < numOfTaks) {
                task[index].done = true;             // Marking the task at given index as done.
                cout << "Task marked as done." << endl;
            }
            else {
                cout << "Invalid Index!" << endl;      // If the user provides an invalid index.
            }
        }

        void removeTask (int index) {               // Function to delete a task from the list.
            if (index >= 0 && index <  numOfTaks) {   // Checking whether the provided index is valid or not.
                for (int i = index; i < numOfTaks - 1; ++i) {
                    task[i] = task[i + 1];              // Shifting all the elements one step upward.
                }
                numOfTaks--;
                cout << "Task removed." << endl;
            }
            else {
                cout << "Invalid Index!" << endl;       // If the user provides an invalid index.
            }
        }
};

// Driver code.

int main ()
{
    ToDoList list;
    int choice;
    string  desc;
    int taskIndex;
    cout << "-----------To-Do-List-----------" << endl;
    do {
        cout << "Menu:\n";
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task as completed\n4. Remove Task\n5. Exit\n";
        cout << "Enter the choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the Task: ";
            cin.ignore();
            getline(cin,desc);
            list.addTask(desc);
            break;
        
        case 2:
            list.viewTask();
            break;

        case 3:
            cout << "Enter index of the task to be marked as completed: ";
            cin >> taskIndex;
            list.markAsDone(taskIndex - 1);
            break;
        
        case 4:
            cout << "Enter index of the task to remove: ";
            cin >> taskIndex;
            list.removeTask(taskIndex - 1);
            break;

        case 5:
            cout << "Exiting the Program..." << endl;
            break;

        default:
            cout << "Invalid Choice! Try Again.\n";
            break;
        }
    }
    while (choice != 5);
    
    return 0;

}
