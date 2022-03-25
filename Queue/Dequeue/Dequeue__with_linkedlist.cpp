/*

A Double Ended Queue [abbreviated to Deque] is a generalized version of Queue
data structure that allows insert and delete at both ends.

Mainly the following four basic operations are performed on queue:
        insertFront(): Adds an item at the front of Deque.
        insertLast(): Adds an item at the rear of Deque.
        deleteFront(): Deletes an item from front of Deque.
        deleteLast(): Deletes an item from rear of Deque.

*/

#include <iostream>
using namespace std;

/* Linked list implementation of Dequeue with the following methods
   -enqueueFront()
   -enqueueRear()
   -dequeueFront()
   -dequeueRear()
   -display()
   
  the above are only the basics, other implementations can also be added.
 */
struct Dequeue
{
    int value;
    Dequeue *next;
    Dequeue *previos;
};
Dequeue *head = NULL;

void enqueueFront(int value)
{
    Dequeue *temp = new Dequeue;
    temp->value = value;
    temp->next = NULL;
    temp->previos = NULL;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    temp->next = head;
    head->previos = temp;
    head = temp;
}

void enqueueRear(int value)
{
    Dequeue *temp = new Dequeue;
    temp->value = value;
    temp->next = NULL;
    temp->previos = NULL;

    if (head == NULL)
    {
        head = temp;
        return;
    }
    Dequeue *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = temp;
    temp->previos = last;
}

void dequeueFront()
{
    if (head == NULL)
    {
        cout << "\nDequeue overflow, it is empty";
        return;
    }
    head = head->next;
}

void dequeueRear()
{
    if (head == NULL)
    {
        cout << "\nDequeue oveflow, it is empty";
        return;
    }

    if (head->next == NULL)
    {
        head = NULL;
        return;
    }

    Dequeue *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp = temp->previos;
    temp->next = NULL;
}

void display()
{
    if (head == NULL)
    {
        cout << "\nDequeue overflow, it is empty";
        return;
    }
    Dequeue *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << ",  ";
        temp = temp->next;
    }
}

int main()
{
    // sample data to check the Dequeue
    // add element at the front
    enqueueFront(2); // 2
    enqueueFront(3); // 3,2
    enqueueFront(5); // 5,3,2
    enqueueFront(6); // 6,5,3,2

    // add element at the end
    enqueueRear(8);  // 6,5,3,2,8
    enqueueRear(77); // 6,5,3,2,8,77
    enqueueRear(55); // 6,5,3,2,8,77,55

    // removes element at the front
    dequeueFront(); // 5,3,2,8,77,55
    dequeueFront(); // 3,2,8,77,55

    // removes element at the end
    dequeueRear(); // 3,2,8,77
    dequeueRear(); // 3,2,8

    display(); // displays  3,2,8

    return 0;
}