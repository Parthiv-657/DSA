#include<iostream>
using namespace std;

struct btnode {
    struct btnode* lc = NULL;
    char data;
    struct btnode* rc = NULL;
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

void Construct(btptr &BT, char c)
{
    BT = new(btnode);
    BT->data = c;
    cin>>c;
    if(c!='#')
        Construct(BT->lc,c);
    cin>>c;
    if(c!= '#')
        Construct(BT->rc,c);
}

void Assign_X(btptr BT, int a[],int &x)
{
    if(BT == NULL)
        return;
    Assign_X(BT->lc,a,x);
    a[int(BT->data)-65] = x;
    x += 1;
    Assign_X(BT->rc,a,x);
}

void Help_Print(struct queue q, int a[])
{
    if(q.isEmpty())
    return;
    struct queue q1,q2;
    int b = 0;
    q2 = q;
    while(!q.isEmpty())
    {
        btptr t = q.DeQueue();
        if(t->lc)
        q1.EnQueue(t->lc);
        if(t->rc)
        q1.EnQueue(t->rc);
        for(int i=1; i<a[int(t->data)-65]-b; i++)
        cout<<" ";
        b = a[int(t->data)-65];
        cout<<t->data;
    }cout<<endl;
    bool flag = 0;
    b = 0;
    if(!q1.isEmpty()){
    while(!q2.isEmpty())
    {
        btptr t = q2.DeQueue();
        if(flag == 0)
        for(int i = 2; i<a[int(t->data)-65]-b; i++)
        cout<<" ";
        else
        {
            for(int i =3 ; i<a[int(t->data)-65]-b; i++)
                cout<<" ";
        }
        if(t->lc)cout<<"(";
        cout<<" ";
        if(t->rc)cout<<")";else cout<<" ";
        b = a[int(t->data)-65];
        flag = 1;
    }cout<<endl;}
    Help_Print(q1, a);
}

void Print_BT(btptr BT)
{
    int a[26]={0};int b = 1;
    Assign_X(BT, a, b);
    struct queue q;
    q.EnQueue(BT);
    Help_Print(q,a);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char c;
    cin>>c;
    //cout<<c<<endl;
    btptr BT = NULL;
    BT->data = 0;
    Construct(BT,c);
    Print_BT(BT);
}