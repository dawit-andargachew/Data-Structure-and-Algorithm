/*

A queue uses the FIFO method (First In First Out), by which the first
element that is enqueued will be the first one to be dequeued. 

*/

#include <iostream>
using namespace std;

/* Linked list implementation of Queue with the following methods
   -is_empty()
   -queue_size()
   -enqueue()
   -dequeue()
   -peek()
   
  the above are only the basics, other implementations can also be added.
 */
struct Queue
{
    int num;
    Queue *next;
};
Queue *head = NULL;

bool is__empty()
{
    if (head == NULL)
        return true;
    return false;
}

int queue_size()
{
    int size = 0;
    if (head == NULL)
        return size;
    if (head->next == NULL)
        return 1;

    Queue *last = head;
    while (last->next != NULL)
    {
        size++;
        last = last->next;
    }
    return size + 1;
}

void enqueue(int value)
{
    Queue *temp = new Queue;
    temp->num = value;
    temp->next = NULL;
    if (is__empty())
    {
        head = temp;
        return;
    }
    Queue *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = temp;
}

void dequeue()
{
    if (is__empty())
    {
        cout << "\nQueue is empty";
        return;
    }
    head = head->next;
}

int peek()
{
    if (is__empty())
        return -1;
    return head->num;
}

int main()
{
    // sample data to check the queue
    enqueue(4);
    enqueue(6);
    enqueue(21);
    enqueue(73);
    enqueue(45);

    dequeue(); // removes 4

    cout << "the top element is " << peek();           // since 4 is removed the top element becomes 6
    cout << "\nthe size of queue is " << queue_size(); // queue size is 4

    return 0;
}