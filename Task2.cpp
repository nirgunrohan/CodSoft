#include <iostream>
using namespace std;

class Calculator {
public:
    float add(float a, float b) {
        return a + b;
    }

    float subtract(float a, float b) {
        return a - b;
    }

    float multiply(float a, float b) {
        return a * b;
    }

    float divide(float a, float b) {
        if (b != 0)
            return a / b;
        else {
            cout << "Error: Division by zero\n";
            return 0;
        }
    }
};

int main() {
    Calculator calc;
    int choice;
    float num1, num2;
    cout << "------ CALCULATOR ------" << endl;
    do {
        cout << "Menu:\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << calc.add(num1, num2) << endl;
                break;
            case 2:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << calc.subtract(num1, num2) << endl;
                break;
            case 3:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << calc.multiply(num1, num2) << endl;
                break;
            case 4:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << calc.divide(num1, num2) << endl;
                break;
            case 5:
                cout << "Exiting Program...";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}
