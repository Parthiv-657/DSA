#include<iostream>
using namespace std;

struct btnode{
    struct btnode* lc=NULL;
    int data;
    struct btnode* rc = NULL;
};

typedef struct btnode* btptr;

struct stack{
	int top = -1;
	btptr elements[100];
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

	btptr pop()
	{
		if(!isEmpty())
		{
			return elements[top--];
		}
	}

	btptr push(btptr a)
	{
		if(!isFull())
		{
			elements[++top] = a;
		}
	}

	btptr peek()
	{
		if(!isEmpty())
			return elements[top];
	}
};

void Construct(btptr &BT, int a)
{
    BT = new(btnode);
    BT->data = a;
    BT->lc = BT->rc = NULL;
    cin>>a;
    if(a)Construct(BT->lc,a);
    cin>>a;
    if(a)Construct(BT->rc,a);
}

void ReversePrint(stack s)
{ 
    while(!s.isEmpty()){
        cout<<s.pop()->data<<" ";
    }cout<<endl;
}

void Search(stack s1, stack s2, int a)
{
    while(!s2.isEmpty())
    {
        btptr t = s2.pop();
        cout<<t->data<<endl;
        if(t->data == a){
        ReversePrint(s1);return;}
        if(t->rc == NULL && t->lc == NULL){
            while(s1.peek()->lc != s2.peek() && s1.peek()->rc != s2.peek()){
                s1.pop();
            }
        }
        else{
            if(t->rc)
            s2.push(t->rc);
            if(t->lc)
            s2.push(t->lc);
            s1.push(t);
        } 
    }
    cout<<" Not Dound"<<endl;
}

int main()
{
    freopen("input.txt","r",stdin);
    btptr BT = NULL;
    int a;
    cin>>a;
    Construct(BT, a);
    cin>>a;
    stack s1, s2;
    s2.push(BT);
    Search(s1,s2, a);
}
