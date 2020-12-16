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


struct cstack{
	int top;
	char elements[100];
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

	char pop()
	{
		if(!isEmpty())
		{
			return elements[top--];
		}
	}

	void push(char a)
	{
		if(!isFull())
		{
			elements[++top] = a;
		}
	}

	char peek()
	{
		if(!isEmpty())
			return elements[top];
	}
};

int value(char a){
    if(a == '(' || a == ')')
        return 0;
    if(a == '+' || a== '-')
        return 1;
    else if(a == '*' || a == '/')
        return 2;
}

bool Digit(char a){
    if(int(a)>=48 && int(a)<=57)
        return true;
    return false;
}

int Evaluate(int b, int a, char c){
    switch(c){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
    }
}

int main(){
    string str = "100*(2+12)";
    stack s1;s1.top = -1;
    cstack s2;s2.top = -1;
    for(int i=0; i<str.size(); i++){
        if(str[i] == '(')
            s2.push(str[i]);
        else if(Digit(str[i])){
            int val = 0;
            while(Digit(str[i])){
                val = val*10;
                val += str[i]-'0';
				i++;
            }
            s1.push(val);
            i--;
        }
        else if(str[i] == ')'){
            while(s2.peek()!='(')
				s1.push(Evaluate(s1.pop(),s1.pop(),s2.pop()));
            s2.pop();
        }else{
            if(value(str[i])>= value(s2.peek())){
                s2.push(str[i]);
            }else{
                while(!s2.isEmpty() && value(str[i]) < value(s2.peek()))
					s1.push(Evaluate(s1.pop(),s1.pop(),s2.pop()));
            }
        }
    }
    while(!s2.isEmpty())
		s1.push(Evaluate(s1.pop(),s1.pop(),s2.pop()));
    cout<<s1.pop()<<endl;
}