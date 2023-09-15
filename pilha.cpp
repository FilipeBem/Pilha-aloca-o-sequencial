#include <iostream>
using namespace std;

const int MAX = 100;

struct Stack {
    int top;
    int elements[MAX];
};

void initialize(Stack& s) {
    s.top = -1;
}

bool isEmpty(Stack& s) {
    return s.top == -1;
}

bool isFull(Stack& s) {
    return s.top == MAX - 1;
}

void push(Stack& s, int value) {
    if (isFull(s)) {
        cout << "Error: the stack is full." << endl;
        return;
    }
    s.elements[++s.top] = value;
}

int pop(Stack& s) {
    if (isEmpty(s)) {
        cout << "Error: the stack is empty." << endl;
        return -1;
    }
    return s.elements[s.top--];
}

int top(Stack& s) {
    if (isEmpty(s)) {
        cout << "Error: the stack is empty." << endl;
        return -1;
    }
    return s.elements[s.top];
}

void menu();

void clear() {
    system("cls");
    menu();
}

int main() {
    Stack s;
    initialize(s);
    menu();
    int option, value;
    do {
        cout << "Select an option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter the value to push: ";
                cin >> value;
                push(s, value);
                break;
            case 2:
                cout << "Popped element: " << pop(s) << endl;
                break;
            case 3:
                cout << "Is the stack empty? " << (isEmpty(s) ? "Yes" : "No") << endl;
                break;
            case 4:
                cout << "Is the stack full? " << (isFull(s) ? "Yes" : "No") << endl;
                break;
            case 5:
                cout << "Top element: " << top(s) << endl;
                break;
            case 6:
                clear();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    } while (option != 0);
    return 0;
}

void menu() {
    cout << "Choose an option:" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Check if the stack is empty" << endl;
    cout << "4. Check if the stack is full" << endl;
    cout << "5. Check the top element" << endl;
    cout << "6. Clear" << endl;
    cout << "0. Exit" << endl;
}