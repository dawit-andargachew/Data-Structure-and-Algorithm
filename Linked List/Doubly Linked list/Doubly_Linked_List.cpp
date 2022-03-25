#include <iostream>
using namespace std;

struct node
{
    string name;
    node *next;
    node *prev;
};
node *head = NULL;

/*

 --- Insertion */

void insert_head(string name)
{
    node *temp = new node;
    temp->name = name;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL)
    {
        head = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insert_tail(string name)
{
    node *temp = new node;
    temp->name = name;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL)
    {
        head = temp;
        return;
    }

    node *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = temp;
    temp->prev = last;
    // last = temp;
}

void insert_BeforeElement(string added, string name)
{
    if (head == NULL)
    {
        cout << "the head can't be null";
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->name == name)
        {
            node *last = new node;
            last->name = added;

            last->next = temp->next;
            temp->next->prev = last;

            temp->next = last;
            last->prev = temp;
        }
        temp = temp->next;
    }
}

/*

 --Search element */

bool search_element(string name)
{
    if (head == NULL)
    {
        cout << "the list is empty\n";
        return false;
    }
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->name == name)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

/*

 --- Deletion */

void remove_head()
{
    if (head == NULL)
    {
        cout << "the list in empty\n";
        return;
    }
    if (head->next == NULL)
    {
        head = NULL;
        return;
    }

    head = head->next;
    head->prev = NULL;
}

void remove_tail()
{
    if (head == NULL)
    {
        cout << "the list in empty\n";
        return;
    }

    if (head->next == NULL)
    {
        head = NULL;
        return;
    }

    node *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last = last->prev;
    last->next = NULL;
}

void remove_element(string key) // should be different from head or tail
{
    if (head == NULL)
    {
        cout << "the list is null\n";
        return;
    }

move_again: // if all nodes contains the value, this block runs to remove these elements
    if (head->name == key)
    {
        if (head->next == NULL)
        {
            head = NULL;
            return;
        }
        head = head->next;
    }

    if (head->name == key)
        goto move_again;

    node *temp = head, *before;
    while (temp->next != NULL)
    {
        if (temp->name == key)
        {
            before = temp->prev;
            before->next = temp->next;
            before->next->prev = before;
        }
        temp = temp->next;
    }

    if (temp->name == key)
        temp->prev->next = NULL;
}

/*

 --- Traversing */

void display()
{
    if (head == NULL)
    {
        cout << "the list is empty\n";
    }
    node *last = head;
    while (last != NULL)
    {
        cout << last->name << endl;
        last = last->next;
    }
}

void reverse_list()
{
    if (head == NULL)
    {
        cout << "the list is empty\n";
        return;
    }

    node *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    cout << "the reverse list is\n";
    while (last != NULL)
    {
        cout << last->name << endl;
        last = last->prev;
    }
}

int main()
{
    // Insertion
    insert_tail("Zero");
    insert_tail("One");
    insert_tail("Two");
    insert_tail("Three");
    insert_tail("Four");
    insert_tail("Five");
    insert_tail("Seven");
    insert_head("Minus One");
    insert_head("Minus Two");

    insert_BeforeElement("Six", "Five");

    // Deletion
    remove_head();         // removes minus Two
    remove_tail();         // removes Seven
    remove_element("One"); // removes One
    remove_tail();         // removes six
    remove_tail();         // removes fix

    // Traversing
    cout << endl;
    display(); // displays Minus One, Zero, Two, Three, Four

    cout << endl;
    reverse_list(); // displays Four, Three, Two, Zero, Minus One
}