/****************“Perhaps the most valuable result of an education is 
the ability to make yourself Do the thing you have to Do, 
when it ought to be done, whether you like it Or Not.”– Thomas Huxley*************/

#include<iostream>
using namespace std;

struct btnode{
    struct btnode* lc = NULL;
    int data;
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

    btptr DeQueue1()
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
                if(r==0)
                r = 99;
                else
                r = r-1;
                return t;
            }
        }
    }

    btptr peek()
    {
        if(!isEmpty())
            return elements[f];
    }
    btptr peek1()
    {
        if(!isEmpty()){
            cout<<r<<"      yeeee"<<endl;
            return elements[r];}
    }
};

void Construct(btptr &T,int a)
{
    if(T==NULL){
    T = new(btnode);
    T->data = a;}
    cin>>a;
    if(a)
    Construct(T->lc,a);
    cin>>a;
    if(a)
    Construct(T->rc,a);
}


void Print(btptr T)
{
    if(T == NULL){
    return;}
    Print(T->lc);
    cout<<T->data<<" ";
    Print(T->rc);
}

void Max_Finder(struct queue q1, struct queue q2)
{
    int a = 0;
    while(q1.peek()->data == q2.peek()->data)
    {
        btptr q = q2.DeQueue();
        a = q->data;
    }
    while(!q1.isEmpty())
    {
        int b = q1.DeQueue()->data;
        if(!q1.isEmpty()){
        if(a<b)
        a = b;}
    }
    while(!q2.isEmpty())
    {
        int b = q2.DeQueue()->data;
        if(!q2.isEmpty()){
        if(a<b)
        a = b;}
    }
    cout<<a<<" ";
}

void Path_Finder(btptr BT, struct queue &q1,struct queue q, int a)
{
    if(BT->data == a){
        q1 = q;;return;}
    if(BT->lc){
        //cout<<BT->lc->data<<endl;
        q.EnQueue(BT->lc);
        Path_Finder(BT->lc, q1,q, a);
        q.DeQueue1();
    }
    if(BT->rc){
        //cout<<BT->rc->data<<endl;
        q.EnQueue(BT->rc);
        Path_Finder(BT->rc, q1,q, a);
        q.DeQueue1();
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    btptr BT = NULL;
    int a;
    cin>>a;
    Construct(BT,a);
    //cout<<BT->data<<endl;
    //Print(BT);
    struct queue q1,q2;
    int b;
    cin>>a>>b;
    //cout<<a<<" "<<b<<endl;
    q1.EnQueue(BT);
    q2.EnQueue(BT);
    Path_Finder(BT,q1,q1,a);
    Path_Finder(BT,q2,q2,b);
    Max_Finder(q1,q2);
    cin>>a>>b;
    q1.r = 0;
    q1.f = 0;
    q2.r = 0;
    q2.f = 0;
    //cout<<a<<" "<<b<<endl;
    Path_Finder(BT,q1,q1,a);
    Path_Finder(BT,q2,q2,b);
    Max_Finder(q1,q2);
    cin>>a>>b;
    q1.r = 0;
    q1.f = 0;
    q2.r = 0;
    q2.f = 0;
    //cout<<a<<" "<<b<<endl;
    Path_Finder(BT,q1,q1,a);
    Path_Finder(BT,q2,q2,b);
    Max_Finder(q1,q2);
}

