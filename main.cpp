#include <iostream>

using namespace std;

// Node class definition
class Node {
public:
    Node* next;
    int data;

    // Constructor to initialize node with value
    Node(int v) : data{v} {
        next = nullptr;
    }
};

// Queue implementation
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    // Function to add an element to the end of the queue
    void Enqueue(int v) {
        Node* newNode = new Node(v);
        if (front == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to remove an element from the front of the queue
    void Dequeue() {
        if (front->next != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Function to display the elements of the queue
    void Display() {
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Function to calculate the sum of all elements in the queue
    int Sum() {
        int sum = 0;
        Node* current = front;
        while (current != nullptr) {
            sum += current->data;
            current = current->next;
        }
        cout << endl;
        return sum;
    }

    // Function to check if a certain value exists in the queue
    bool Includes(int v) {
        bool includes = false;
        Node* current = front;
        while (current != nullptr) {
            if (current->data == v) {
                return true;
            }
            current = current->next;
        }
        cout << endl;
        return includes;
    }
};

// Stack implementation
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Function to push an element onto the top of the stack
    void push(int v) {
        Node* newNode = new Node(v);
        newNode->next = top;
        top = newNode;
    }

    // Function to pop an element from the top of the stack
    void pop() {
        if (top->next != nullptr) {
            Node* temp = top->next;
            delete top;
            top = temp;
        }
    }

    // Function to pop multiple elements from the top of the stack
    void operator-=(int amount) {
        int i = 0;
        while (i < amount) {
            if (top->next != nullptr) {
                Node* temp = top->next;
                delete top;
                top = temp;
            }
            i++;
        }
    }

    // Function to get the size of the stack
    int size() {
        int counter = 0;
        Node* current = top;
        while (current != nullptr) {
            counter++;
            current = current->next;
        }
        return counter;
    }

    // Function to display the elements of the stack
    void display() {
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }
};

int main() {

    cout << "Stack" << endl;
    Stack S;
    S.push(4);
    S.push(5);
    S.push(8);

    S.display();
    cout << "size:";
    cout << S.size() << endl;
    cout << "====== \n -=2 - remove two elements from stack" << endl;
    S -= 2;
    
    S.display();

    cout << "Queue FIFO" << endl;
    Queue Q;
    Q.Enqueue(5);
    Q.Enqueue(2);
    Q.Enqueue(7);

    Q.Display();

    Q.Dequeue();

    Q.Display();

    cout << Q.Sum() << endl;
    cout << Q.Includes(7) << endl;

    return 0;
}
