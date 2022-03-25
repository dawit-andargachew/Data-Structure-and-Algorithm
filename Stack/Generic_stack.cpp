/* 

A stack is a linear data structure that follows the principle of Last In First Out (LIFO).
This means the last element inserted inside the stack is removed first.

Here is a generic OOP implementation of stack which can store any data type we want.
And we should specify the data type when we declare the stack like this
      Stack<int> list1;       // stores int
      Stack<string> list2     // stores string

*/
#include <iostream>
using namespace std;

/* Here is a generic stack implementation follwing methods
     -is__empty()
     -is__empty()
     -push()
     -pop()
     -top()
  
  the above are only the basics, other implementations can also be added.
  
 */

template <typename T>
class Stack
{
private:
    int static const size = 1000; // maximum stack size = 1000
    T arr[size];
    int head = -1;
    // push pop top is__empty is__full
public:
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

    void push(T num)
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
        cout << "\nThe stack is empty";
    }

    T top()
    {
        if (!is__empty())
            return arr[head];
        cout << "\nthe stack is empty";
    }
};

int main()
{
    // sample data to check the stack
    Stack<int> stack; // store int
    stack.push(4);
    stack.push(88);
    stack.push(7);
    stack.push(96);
    stack.push(85);

    cout << stack.top() << endl;

    Stack<string> str_stack; // store string
    str_stack.push("one");
    str_stack.push("two");
    str_stack.push("three");
    str_stack.pop();

    cout << str_stack.top();
}