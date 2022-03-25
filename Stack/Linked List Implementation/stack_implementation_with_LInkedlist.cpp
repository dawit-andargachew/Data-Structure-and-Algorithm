/* 

A stack is a linear data structure that follows the principle of Last In First Out (LIFO).
This means the last element inserted inside the stack is removed first.

Here is Linked list based implementation of stack

*/

#include <iostream>
using namespace std;

/* Here is the linked list implementation of stack with the
   following method
   -is_empty()
   -is_full()
   -push()
   -pop()
   -top()

   the above are only the basics, other implementations can also be added.

*/
struct stack
{
    int num;
    stack *next;
};
stack *head = NULL;

bool is__emtpy()
{
    if (head == NULL)
        return true;
    return false;
}

void push(int num)
{
    stack *temp = new stack;
    temp->num = num;
    temp->next = NULL;
    if (is__emtpy())
    {
        head = temp;
        return;
    }
    stack *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = temp;
}

void pop()
{
    if (is__emtpy())
    {
        cout << "\bThe stack is empty";
        return;
    }
    if (head->next == NULL)
    {
        head->next = NULL;
        return;
    }
    stack *last = head, *prev;
    while (last->next != NULL)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
}

int top()
{
    if (is__emtpy())
        return -1;
    if (head->next == NULL)
        return head->num;

    stack *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    return last->num;
}

int main()
{
    // sample data to check the stack
    push(3);
    push(7);
    push(88888);
    push(44);
    push(37);
    push(6);

    cout << top();
}