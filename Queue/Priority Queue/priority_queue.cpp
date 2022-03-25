/*

A priority queue is a special type of queue in which each element is associated
with a priority value. And, elements are served on the basis of their priority.
That is, higher priority elements are served first.

*/

#include <iostream>
using namespace std;

/*
Linked list Priority Queqe implementation and students who are 'F'
have higher priority of being deleted first.

*/

struct Queue
{
    string name;
    char priotity; // individual sex serve as a priotity

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

void enqueue(string name, char priority)
{
    Queue *temp = new Queue;
    temp->name = name;
    temp->priotity = priority;
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

void priority_dequeue()
{
    if (is__empty())
    {
        cout << "\nQueue is empty";
        return;
    }

    Queue *temp = head, *prev;

    while (temp->next != NULL)
    {
        if (head->priotity == 'F')
        {
            prev = head;
            head = prev->next;
            return;
        }

        prev = temp;
        temp = temp->next;
        if (temp->priotity == 'F')
        {
            prev->next = temp->next;
            return;
        }
    }
    dequeue();
}

string peek()
{
    if (is__empty())
        return " ";
    return head->name;
}

// displays the queue
void show()
{
    if (head == NULL)
    {
        cout << "The queue is empty";
        return;
    }

    Queue *temp = head;
    while (temp != NULL)
    {
        cout << temp->name + "\t" + temp->priotity << endl;
        temp = temp->next;
    }
}

int main()
{

    // sample data
    enqueue("Aster", 'F');
    enqueue("Abenezer", 'M');
    enqueue("Dawit", 'M');
    enqueue("Birtuka", 'F');
    enqueue("Jerry", 'F');
    enqueue("Kaleab", 'M');
    enqueue("Kal", 'M');
    enqueue("Meron", 'F');

    // 'F' students have higher priority than 'M', so they removed first
    // removing 'M' students began after get rid of all 'F' students
    priority_dequeue();
    priority_dequeue();
    priority_dequeue(); // 3 'F' students are removed

    show();

    return 0;
}