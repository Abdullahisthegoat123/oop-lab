#include <iostream>
#include <stdexcept>

using namespace std;

class QueueOverflowException : public exception
{
};

class QueueUnderflowException : public exception
{
};

template <typename T>
class Queue
{
private:
    T *data;
    int capacity;
    int front;
    int rear;
    int size;

public:
    Queue(int cap) : capacity(cap), front(0), rear(-1), size(0)
    {
        data = new T[capacity];
    }

    ~Queue()
    {
        delete[] data;
    }

    void enqueue(T value)
    {
        if (size == capacity)
        {
            throw QueueOverflowException();
        }
        rear = (rear + 1) % capacity;
        data[rear] = value;
        size++;
    }

    T dequeue()
    {
        if (size == 0)
        {
            throw QueueUnderflowException();
        }
        T value = data[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    bool isFull() const
    {
        return size == capacity;
    }

    void display() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++)
        {
            cout << data[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main()
{
    try
    {
        Queue<int> queue(3);

        cout << "Attempting to enqueue to a full queue..." << endl;
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);
        queue.display();

        queue.enqueue(40);
    }
    catch (const QueueOverflowException &e)
    {
        cout << "Caught QueueOverflowException - what(): " << e.what() << endl;
    }

    try
    {
        Queue<int> queue(3);

        cout << "Attempting to dequeue from an empty queue..." << endl;

        queue.dequeue();
    }
    catch (const QueueUnderflowException &e)
    {
        cout << "Caught QueueUnderflowException - what(): " << e.what() << endl;
    }

    return 0;
}