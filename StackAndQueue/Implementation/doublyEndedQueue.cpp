#include <bits/stdc++.h>
using namespace std;

// Deque (Double-Ended Queue) Implementation using Circular Array
// Allows insertion and deletion from both ends in O(1) time
class Deque {
    int* arr;        // Array to store elements
    int front;       // Index of the front element
    int rear;        // Index of the rear element
    int size;        // Total capacity of the deque

public:
    // Constructor: Initialize deque with given capacity
    Deque(int n) {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    // Check if deque is full
    // Circular array is full when: front at 0 and rear at size-1, OR front = rear+1
    bool isFull() {
        return (front == 0 && rear == size - 1) || (front == rear + 1);
    }

    // Check if deque is empty
    bool isEmpty() {
        return front == -1;
    }

    // Insert element at the front of deque
    void pushFront(int x) {
        if (isFull()) {
            cout << "Deque is Full\n";
            return;
        }

        if (isEmpty()) {
            // First element - set both front and rear
            front = rear = 0;
        }
        else if (front == 0) {
            // Wrap around to the end in circular manner
            front = size - 1;
        }
        else {
            // Move front pointer backward
            front--;
        }

        arr[front] = x;
    }

    // Insert element at the back of deque
    void pushBack(int x) {
        if (isFull()) {
            cout << "Deque is Full\n";
            return;
        }

        if (isEmpty()) {
            // First element - set both front and rear
            front = rear = 0;
        }
        else if (rear == size - 1) {
            // Wrap around to the beginning in circular manner
            rear = 0;
        }
        else {
            // Move rear pointer forward
            rear++;
        }

        arr[rear] = x;
    }

    // Remove element from the front of deque
    void popFront() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        if (front == rear) {
            // Only one element - deque becomes empty
            front = rear = -1;
        }
        else if (front == size - 1) {
            // Wrap around to the beginning
            front = 0;
        }
        else {
            // Move front pointer forward
            front++;
        }
    }

    // Remove element from the back of deque
    void popBack() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        if (front == rear) {
            // Only one element - deque becomes empty
            front = rear = -1;
        }
        else if (rear == 0) {
            // Wrap around to the end
            rear = size - 1;
        }
        else {
            // Move rear pointer backward
            rear--;
        }
    }

    // Get the front element without removing
    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    // Get the rear element without removing
    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }

    // Display all elements in the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        // Traverse from front to rear using circular array logic
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;  // Circular wrap-around
        }
        cout << endl;
    }
};

// Test the Deque implementation
int main() {
    // Create a deque with capacity 5
    Deque dq(5);

    // Insert elements at front and back
    dq.pushBack(10);
    dq.pushBack(20);
    dq.pushFront(5);
    dq.pushFront(2);

    // Display all elements
    cout << "Deque elements: ";
    dq.display();

    // Display front and rear elements
    cout << "Front: " << dq.getFront() << endl;
    cout << "Rear: " << dq.getRear() << endl;

    // Remove elements from both ends
    dq.popFront();
    dq.popBack();

    // Display after removing
    cout << "After popping front and rear:\n";
    dq.display();

    return 0;
}