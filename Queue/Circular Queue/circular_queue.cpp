/*

Circular Queue is a linear data structure in which the operations are performed
based on FIFO (First In First Out) principle and the last position is connected back
to the first position to make a circle

*/
#include <iostream>
using namespace std;

/* Array based Circular Queue implementation with the following methods
   -is__empty()
   -is__full()
   -enqueue()
   -dequeue()
   -get_size()
   -get_front()
   -get_rear()
   
  the above are only the basics, other implementations can also be added.
  */

int const Max_size = 100; // circular queue size is 100
int queue[Max_size];
int rear = -1;
int front = -1;
int size = 0;

bool is__empty()
{
    if (front == -1 && rear == -1 || size == 0)
        return true;
    return false;
}

bool is__full()
{
    if ((front == 0 && rear == Max_size - 1) && size == Max_size)
        return true;
    return false;
}

void enqueue(int value)
{
    if (front == -1)
    {
        front = 0;
    }

    if (!is__full())
    {
        if (rear < Max_size - 1)
        {
            rear++;
            size++;
            queue[rear] = value;
            return;
        }

        if (rear == Max_size - 1 && front > 0)
        {
            rear = 0;
            size++;
            queue[rear] = value;
            return;
        }
        if (rear < front - 1) // rear  < front-1
        {
            rear++;
            size++;
            queue[rear] = value;
            return;
        }
    }

    cout << "\nthe queue is full";
}

void dequeue()
{
    if (!is__empty())
    {
        if (front <= rear)
        {
            front++;
            size--;
            return;
        }
        else if (front == Max_size - 1 && !is__full())
        {
            front = 0;
            size--;
            return;
        }
        else
            front++;
    }
    else
        cout << "\nQueue is empty";
}

int get_size()
{
    return size;
}

// returns the first item
int get_front()
{
    if (!is__empty())
        return queue[front];
    return -1;
}

// returns the rear item item
int get_rear()
{
    if (!is__empty())
        return queue[rear];
    return -1;
}

int main()
{
    // sample data to check the queue
    enqueue(1); //  1,2,3,4,5,6,7,   // then remove 4 items and put 8,9,10,11
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);

    dequeue(); // removes 1
    dequeue(); // removes 2
    dequeue(); // removes 3
    dequeue(); // remove 4   _ _ _ _ 5 6 7

    enqueue(8);  // 8 _ _ _ 5 6 7
    enqueue(9);  // 8 9 _ _ 5 6 7
    enqueue(10); // 8 9 10 _ 5 6 7
    enqueue(11); // 8 9 10 11 5 6 7 rear = 11, front 5

    dequeue(); // removes 1
    dequeue(); // removes 2
    dequeue(); // removes 3

    cout << "\nFront is :" << get_front() << endl;
    cout << "Rear is : " << get_rear() << endl;
    cout << "The size is :" << get_size();

    return 0;
}