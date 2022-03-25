#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack
{
private:
	int static const size = 100;
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

// checks wheather the data is number or not
template <typename T>
bool isNumber(T c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		return false;
	else
		return true;
}

// checks wheather the character is operator or ont
bool isOperator(char c)
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
	Stack<char> s;
	string postfix;
	for (int i = 0; i < infix.length(); i++) // loop
	{
		// 1
		if (isNumber(infix[i]))
		{
			postfix += infix[i]; // string append
		}
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

// converts opetands to there exact value since they are treated as character  like char '5' to int 5 for postfix evaluation
int val(char c)
{
	return (c - '0');
}


// evalute the postfix expression
int postfix__evaluator(string expression)
{
	Stack<int> stack;

	for (char c : expression)
	{
		// if the current character is an operand, push it into the stack
		if (c >= '0' && c <= '9')
		{
			stack.push(c - '0');
		}

		else
		{
			int x = stack.top();
			stack.pop();

			int y = stack.top();
			stack.pop();

			if (c == '+')
			{
				stack.push(y + x);
			}
			else if (c == '-')
			{
				stack.push(y - x);
			}
			else if (c == '*')
			{
				stack.push(y * x);
			}
			else if (c == '/')
			{
				stack.push(y / x);
			}
		}
	}

	return stack.top();
}

int main()
{

	string infix_exp, postfix_exp;

	cout << "Enter a Infix Expression :" << endl;
	cin >> infix_exp;

	cout << "INFIX EXPRESSION: " << infix_exp << endl;
	postfix_exp = InfixToPostfix(infix_exp);
	cout << "POSTFIX EXPRESSION: " << postfix_exp;

	cout << "\nThe postfix after evalutation is : " << postfix__evaluator(postfix_exp);

	return 0;
}
