#include "Queue.h"
#include <iostream>
using namespace std;

::Queue::Queue() {
    capacity = 10;
    arr = new int[capacity];
    front = 0;
    rear = -1;
    size = 0;
}

void ::Queue::resize() {
    int newCapacity = capacity * 2;
    int* newArr = new int[newCapacity];

    for (int i = 0; i < size; i++) {
        newArr[i] = arr[(front + i) % capacity];
    }

    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
    front = 0;
    rear = size - 1;
}

void ::Queue::enqueue(int x) {
    if (size == capacity) resize();
    rear = (rear + 1) % capacity;
    arr[rear] = x;
    size++;
}

void ::Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is Empty\n";
        return;
    }
    front = (front + 1) % capacity;
    size--;
}

int ::Queue::peek() const {
    if (isEmpty()) {
        cout << "Queue is Empty" << endl;
        return -1;
    }
    return arr[front];
}

bool ::Queue::isEmpty() const {
    return size == 0;
}

int ::Queue::getSize() const {
    return size;
}

void ::Queue::display() const {
    if (isEmpty()) {
        cout << "Queue is Empty" << endl;
        return;
    }
    cout << "Queue: ";
    for (int i = 0; i < size; i++) {
        cout << arr[(front + i) % capacity] << " ";
    }
    cout << endl;
}
