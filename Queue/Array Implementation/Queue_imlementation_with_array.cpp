/*

A queue uses the FIFO method (First In First Out), by which the first
element that is enqueued will be the first one to be dequeued. 

*/

#include <iostream>
using namespace std; 

/*  Array based Queque implementation with the following methods
     -is__empty()
     -is__full()
     -getSize()
     -enqueue()
     -dequeue()
     -display_queue()
     -peek()

  the above are only the basics, other implementations can also be added.
 */

int const size = 100; // queue size = 100
int queue[size];

int front = -1;
int rear = -1;

bool is__empty()
{
    if ((front < 0) || front > rear) // or ---> ((front == -1 && rear == -1) || front > rear)
        return true;
    return false;
}

bool is__full()
{
    if (rear == size - 1)
        return true;
    return false;
}

int getSize()
{
    if (!is__empty())
        return rear - front + 1;
    return 0;
}

void enqueue(int num)
{
    if (!is__full())
    {
        if (front == -1)
            front++;

        rear++;
        queue[rear] = num;
        return;
    }
    cout << "\nQueue overflow, it is full";
}

void dequeue()
{
    if (!is__empty() && front <= rear)
    {
        front++;
        return;
    }
    cout << "Queue overflow, it is empty";
}

void display_queue()
{
    if (!is__empty())
    {
        for (int i = front; i <= rear; i++)
            cout << queue[i] << endl;
    }
    else
        cout << "\nQueue overflow, it is empty";
}

int peek()
{
    if (!is__empty())
        return queue[front];
    return -1;
}

int main()
{
    // sample data to check the queue
    enqueue(6);
    enqueue(55);
    enqueue(33);
    enqueue(9);
    enqueue(8);

    dequeue();// removes 6

    display_queue();
    return 0;
}