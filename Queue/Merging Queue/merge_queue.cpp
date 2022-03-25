#include <bits/stdc++.h>
using namespace std;

/* Linked list implementation of Merging two queues 
*/

struct Queue1
{
    string name;
    char priotity; // individual sex serve as a priotity

    Queue1 *next;
};

Queue1 *head1 = NULL;

bool is__empty1()
{
    if (head1 == NULL)
        return true;
    return false;
}

int queue_size1()
{
    int size = 0;
    if (head1 == NULL)
        return size;
    if (head1->next == NULL)
        return 1;

    Queue1 *last = head1;
    while (last->next != NULL)
    {
        size++;
        last = last->next;
    }
    return size + 1;
}

void enqueue1(string name, char priority)
{
    Queue1 *temp = new Queue1;
    temp->name = name;
    temp->priotity = priority;
    temp->next = NULL;
    if (is__empty1())
    {
        head1 = temp;
        return;
    }
    Queue1 *last = head1;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = temp;
}

void dequeue1()
{
    if (is__empty1())
    {
        cout << "\nQueue is empty";
        return;
    }
    head1 = head1->next;
}

string peek1()
{
    if (is__empty1())
        return " ";
    return head1->name;
}

// displays the queue
void show1()
{
    if (head1 == NULL)
    {
        cout << "The queue is empty";
        return;
    }

    Queue1 *temp = head1;
    while (temp != NULL)
    {
        cout << temp->name << "\t\t\t\t" << temp->priotity << endl;
        temp = temp->next;
    }
}

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
        cout << temp->name << "\t\t\t\t" << temp->priotity << endl;
        temp = temp->next;
    }
}

void merge()
{
    if (head1 == NULL && head == NULL)
    {
        cout << "No queue to merge\n";
        return;
    }

    Queue1 *last = head1;
    while (last != NULL)
    {
        enqueue(last->name, last->priotity);
        last = last->next;
    }
}
int main()
{
    enqueue1("Jerry", 'F');
    enqueue1("Liam", 'M');
    enqueue1("Tom", 'M');
    enqueue1("Oliva", 'F');
    enqueue1("Emma", 'F');
    enqueue1("William", 'M');
    enqueue1("Lucas", 'M');
    enqueue1("Sophia", 'F');

    cout << "\nFirst stack is this\n";
    show1();
    cout << "\nSecond stakc is this\n";
    enqueue("David", 'D');
    enqueue("Charry", 'F');
    enqueue("Elijah", 'M');
    enqueue("Noah", 'M');
    enqueue("James", 'M');
    enqueue("Ben", 'M');
    enqueue("Amelia", 'F');
    show();

    merge();
    cout << "\nAfter merge it looks like this\n";
    show();

    // merge

    return 0;
}