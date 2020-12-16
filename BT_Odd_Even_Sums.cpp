#include<iostream>
using namespace std;

struct btnode
{
    struct btnode* lc;
    int data;
    struct btnode* rc;
};

typedef struct btnode* btptr;

struct queue{
    int size=100;
    int f=-1;
    int r=-1;
    btptr elements[100];

    bool isEmpty()
    {
        if(f == -1&&r == -1)
            return true;
        return false;
    }

    bool isFull()
    {
        if((r+1)%size == f)
            return true;
        return false; 
    }

    void EnQueue(btptr a){
        if(!isFull())
        {   
            if(f == -1)
            {
                f = 0;
                r = 0;
                elements[r] = a;
            }else{
                r = (r+1)%size;
                elements[r] = a;
            }
        }else{
            cout<<"FULL"<<endl;
            //return -100;
        }
    }

    btptr DeQueue()
    {
        if(!isEmpty())
        {
            if(f == r)
            {
                btptr t = elements[f];
                f = -1;
                r = -1;
                return t;
            }else{
                btptr t = elements[f];
                f = (f+1)%size;
                return t;
            }
        }
    }

    btptr pop()
    {
        if(!isEmpty())
        {
            if(f == r)
            {
                btptr t = elements[f];
                f = -1;
                r = -1;
                return t;
            }else{
                btptr t = elements[r];
                r = (r-1)%size;
                return t;
            }
        }
    }
    btptr peek()
    {
        if(!isEmpty())
            return elements[f];
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

void Odd_Even_Sum(struct queue q, int &even, int &odd, bool flag)
{
    if(q.isEmpty())
        return;
    struct queue q2;
    int sum = 0;
    while(!q.isEmpty())
    {
        btptr t = q.DeQueue();
        sum+= t->data;
        if(t->lc)q2.EnQueue(t->lc);
        if(t->rc)q2.EnQueue(t->rc);
    }
    if(flag)
    {
        if(sum>even)
        even = sum;
        Odd_Even_Sum(q2,even,odd,false);
    }
    else
    {
        if(sum>odd)
        odd = sum;
        Odd_Even_Sum(q2,even,odd,true);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    btptr BT = NULL;
    int a;
    cin>>a;
    Construct(BT,a);
    int even = 0,odd = 0;
    struct queue q;
    q.EnQueue(BT);
    Odd_Even_Sum(q,even,odd,true);
    cout<<even<<" "<<odd<<endl;
}