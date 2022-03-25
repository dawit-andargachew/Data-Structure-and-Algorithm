#include<bits/stdc++.h>
#include <iostream>
using namespace std;
 
template <typename T>
class stack_ // generic stack which can take any data type
{
	int const static size = 100;
	T arr[size];
	int rear = -1;

public:
	bool is_full()
	{
		if (rear == size - 1)
			return true;
		return false;
	}
	bool is__empty()
	{
		if (rear == -1)
			return true;
		return false;
	}

	void push(T n)
	{
		if (!is_full())
		{
			rear++;
			arr[rear] = n;
			return;
		}
		cout << "\n the stack is full";
	}

	void pop()
	{
		if (!is__empty())
		{
			rear--;
			return;
		}
		cout << "the stack is empty";
	}

	T top()
	{
		if (!is__empty())
			return arr[rear];
		cout << "\nthe stack is emtpy";
	}
};

// checks wheather the character is operator or ont
bool isOperator(char c) //
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		return true;
	else
		return false;
}

// assigns the precedence of operators
int precedence(char c)
{
	if (c == '^') // higher 3    ^, * /, + -
		return 3;
	else if (c == '*' || c == '/') // 2
		return 2;
	else if (c == '+' || c == '-') // 1
		return 1;
	else
		return -1;
}

// infix to postfix conversion takes place here
string InfixToPostfix(string infix)
{
	string postfix;
	stack_<char> s;
	for (int i = 0; i < infix.length(); i++) // loop
	{
		// 1
		if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
		{
			postfix += infix[i]; // string append
		}						 // done step 1
		// 2
		else if (infix[i] == '(')
		{
			s.push(infix[i]);
		} // step 2 is done

		// 3
		else if (infix[i] == ')')
		{
			while ((s.top() != '(') && (!s.is__empty())) // T
			{
				char temp = s.top();
				postfix += temp; // postfic = postfic + s.top()
				s.pop();
			}
			if (s.top() == '(') // pop the element "(" since ")" is already occures
			{					//(+-(+/ ")" then we should remove this (+-_(_
				s.pop();
			}
		}
		// 4
		else if (isOperator(infix[i])) // ^,* /, - +
		{
			// 1 if stack is empty
			if (s.is__empty())
			{
				s.push(infix[i]);
			}

			else // if stack is not empity
			{
				// 1 if precedence of infix[i] is larger than stack.top()
				if (precedence(infix[i]) > precedence(s.top()))
				{
					s.push(infix[i]);
				}

				// 2 if precedence is equal and '^'
				else if ((precedence(infix[i]) == precedence(s.top())) && (infix[i] == '^'))
				{
					s.push(infix[i]); // needs some clarification, why???????
				}

				else
				{ // otherwise the precedence is smaller so append to postfix and pop the stack
					while ((!s.is__empty()) && (precedence(infix[i]) <= precedence(s.top())))
					{
						postfix += s.top();
						s.pop();
					}
					s.push(infix[i]);
				}
			}
		}
	}
	while (!s.is__empty())
	{
		postfix += s.top();
		s.pop();
	}

	return postfix;
}

// A+B*C+(D*E+F)*G
int main()
{

	string infix_exp, postfix_exp;

	cout << "\nEnter a Infix Expression \n \t[ enter character expressions like (A + B)D + C   .... but not (1 + 2) *3 ]  :" << endl;
	cin >> infix_exp;

	cout << "INFIX EXPRESSION: " << infix_exp << endl;
	postfix_exp = InfixToPostfix(infix_exp);

	cout << "POSTFIX EXPRESSION: " << postfix_exp;

	return 0;
}
