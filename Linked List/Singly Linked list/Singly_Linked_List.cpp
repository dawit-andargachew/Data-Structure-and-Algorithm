#include <iostream>
using namespace std;

struct node
{
    string name;
    node *next;
};
node *head = NULL;

/*
  -- Insertion */
void insert_head(string data)
{
    node *newnode = new node;
    newnode->name = data;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        return;
    }

    newnode->next = head;
    head = newnode;
}

void insert_tail(string data)
{
    node *newnode = new node;
    newnode->name = data;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}

void insert_before(string data, string old)
{

    if (head == NULL)
    {
        cout << "\nlist is empty \n";
        return;
    }

    node *newnode = new node;
    newnode->name = data;
    newnode->next = NULL;

    node *last = head, *before;

    if (head->name == old)
    {
        newnode->next = head;
        head = newnode;
        return;
    }

    while (last->next != NULL)
    {
        before = last;
        last = last->next;

        if (last->name == old)
        {
            before->next = newnode;
            newnode->next = last;
            return;
        }
    }
}

/*
  -- Deletion */
void delete_head()
{
    if (head == NULL)
    {
        cout << "\nlist is empty\n";
        return;
    }

    head = head->next;
}

void delete_tail()
{
    if (head == NULL)
    {
        cout << "\nlist is empty\n";
        return;
    }

    if (head->next == NULL)
    {
        head = NULL;
        return;
    }

    node *temp = head, *before;
    while (temp->next != NULL)
    {
        before = temp;
        temp = temp->next;
    }
    before->next = NULL;
    delete temp;
}

void delete_element(string key)
{
    if (head == NULL)
    {
        cout << "\nList is empty\n";
        return;
    }

move_again:
    if (head->name == key)
    {
        if (head->next == NULL)
        {
            head = NULL;
            return;
        }
        head = head->next;
    }

    if (head->name == key) // if the head node contains the key 'move_agin' segment is executed
        goto move_again;   // when all nodes have similar key this helps us to remove all of them

    node *temp = head, *before; /* ,*before_before */

    while (temp->next != NULL)
    {
        before = temp;
        temp = temp->next;
        if (temp->name == key)
        {
            before->next = temp->next;
            temp = before;
        }
    }

    if (temp->name == key) // checks weather the last node contains the key
        before->next = NULL;
}

/*
  --Searching */
bool search_element(string key)
{
    if (head == NULL)
    {
        cout << "\nList is empty\n";
        return false;
    }
    if (head->next == NULL && head->name == key)
        return true;

    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->name == key)
            return true;
        temp = temp->next;
    }

    return false;
}

/*
   -- Traversing */
void display_forward()
{
    if (head == NULL)
    {
        cout << "\nLinked list is empty.\n";
        return;
    }

    node *last = head;
    while (last != NULL)
    {
        cout << last->name << endl;
        last = last->next;
    }
}

void reverse_traversal()
{
    node *current = head;
    node *prev = NULL, *next = NULL;

    while (current != NULL)
    {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;

    display_forward();
}

int main()
{
    // insertion
    insert_tail("one");
    insert_tail("two");
    insert_tail("three");
    insert_tail("four");
    insert_tail("six");

    insert_before("five", "six");

    insert_head("zero");
    insert_head("Minus one");
    insert_head("Minus two");

    // deletion
    delete_tail(); // removes six
    delete_head(); // removes Minus two

    delete_element("one"); // removes one

    cout << endl;
    // displays Minus one, zero, two,three,four,five
    display_forward();
    cout << endl;

    // reverse travese
    reverse_traversal();

    return 0;
}