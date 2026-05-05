#pragma once

class Queue {
    private:
        int* arr;
        int capacity;
        int front;
        int rear;
        int size;

        void resize();

    public:
        Queue();

        void enqueue(int x);

        void dequeue();

        int peek() const;

        bool isEmpty() const;

        int getSize() const;

        void display() const;
};