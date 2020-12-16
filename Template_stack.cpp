#include<iostream>
using namespace std;

struct stack{
	int top;
	int elements[100];
	bool isFull()
	{
		if(top == 100)
			return true;
		return false;
	}

	bool isEmpty()
	{
		if(top == -1)
			return true;
		return false;
	}

	int pop()
	{
		if(!isEmpty())
		{
			return elements[top--];
		}
	}

	void push(int a)
	{
		if(!isFull())
		{
			elements[++top] = a;
		}
	}

	int peek()
	{
		if(!isEmpty())
			return elements[top];
	}
};

