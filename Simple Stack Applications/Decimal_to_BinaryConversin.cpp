#include <bits/stdc++.h>
using namespace std;

const int size = 100;
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

void deci_to_bin(int num) //
{
    while (num > 0) // devide the number by 2 and push remainder to stack;
    {
        int remainder = num % 2;
        num = num / 2;
        push(remainder);
    }

    while (!is__empty())
    {
        cout << top();
        pop();
    }
}

int main()
{
    int num;
    cout << "\nThis program coverts decimal to binary \n please enter a number ...";
    cin >> num;
    cout << "\nThe binary equivalent of " << num << " is ";
    (deci_to_bin(num));
    cout << "\n\n";
}