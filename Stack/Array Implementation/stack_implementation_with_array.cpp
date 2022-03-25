/*

A stack is a linear data structure that follows the principle of Last In First Out (LIFO).
This means the last element inserted inside the stack is removed first.

Here is the array based implementation of stack

*/

#include <iostream>
using namespace std;

/* stack implementation with the following methods
     -is_empty()
     -is__full()
     -push()
     -pop()
     -top()

  the above are only the basics, other implementations can also be added.

 */
const int size = 1000; // maximum stack size = 1000
int arr[size];
int head = -1;

bool is__empty()
{
    if (head == -1)
        return true;
    return false;
}

bool is__full()
{
    if (head == size - 1)
        return true;
    return false;
}

void push(int num)
{
    if (!is__full())
    {
        head++;
        arr[head] = num;
        return;
    }
    cout << "\nthe stack is full";
}

void pop()
{
    if (!is__empty())
    {
        head--;
        return;
    }
    cout << "\nthe stack is empty";
}

int top()
{
    if (is__empty())
        return -1;
    return arr[head];
}

int main()
{
    // sample data to check the stack
    push(3);
    push(3);
    push(4444);

    cout << top() << endl;
    cout << is__full();
}