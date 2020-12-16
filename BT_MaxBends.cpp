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

void Construct(btptr &T, int a)
{
    T = new(btnode);
    T->data = a;
    cin>>a;
    if(a)Construct(T->lc,a);
    cin>>a;
    if(a)Construct(T->rc,a);
}

void Print(struct queue q)
{
    if(q.isEmpty()){
    cout<<endl;return;}
    cout<<q.DeQueue()->data<<" ";
    Print(q);
}

void Find_count(btptr BT, struct queue q, int &max_len, int tag, int len)
{
    if(tag == 0)
    {
        if(BT->lc){
            q.EnQueue(BT->lc);
            Find_count(BT->lc, q, max_len, 1, len+1);
            q.DeQueue1();
        }
        if(BT->rc){
            q.EnQueue(BT->rc);
            Find_count(BT->rc, q, max_len, 2, len+1);
            q.DeQueue1();
        }
    }
    else if(tag == 1)
    {
        if(BT->lc){
            q.EnQueue(BT->lc);
            Find_count(BT->lc, q, max_len, 1, len);
            q.DeQueue1();
        }
        if(BT->rc){
            q.EnQueue(BT->rc);
            Find_count(BT->rc, q, max_len, 2, len+1);
            q.DeQueue1();
        }
    }else{
        if(BT->lc){
            q.EnQueue(BT->lc);
            Find_count(BT->lc, q, max_len, 1, len+1);
            q.DeQueue1();
        }
        if(BT->rc){
            q.EnQueue(BT->rc);
            Find_count(BT->rc, q, max_len, 2, len);
            q.DeQueue1();
        }
    }
    if(BT->lc == NULL && BT->rc == NULL)
        if(len>max_len)
            max_len = len;
}

void Print_Max_Bend(btptr BT, struct queue q, int &max_len, int tag, int len)
{
    if(tag == 0)
    {
        if(BT->lc){
            q.EnQueue(BT->lc);
            Print_Max_Bend(BT->lc, q, max_len, 1, len+1);
            q.DeQueue1();
        }
        if(BT->rc){
            q.EnQueue(BT->rc);
            Print_Max_Bend(BT->rc, q, max_len, 2, len+1);
            q.DeQueue1();
        }
    }
    else if(tag == 1)
    {
        if(BT->lc){
            q.EnQueue(BT->lc);
            Print_Max_Bend(BT->lc, q, max_len, 1, len);
            q.DeQueue1();
        }
        if(BT->rc){
            q.EnQueue(BT->rc);
            Print_Max_Bend(BT->rc, q, max_len, 2, len+1);
            q.DeQueue1();
        }
    }else{
        if(BT->lc){
            q.EnQueue(BT->lc);
            Print_Max_Bend(BT->lc, q, max_len, 1, len+1);
            q.DeQueue1();
        }
        if(BT->rc){
            q.EnQueue(BT->rc);
            Print_Max_Bend(BT->rc, q, max_len, 2, len);
            q.DeQueue1();
        }
    }
    if(len ==  max_len&&BT->lc == NULL&&BT->rc == NULL){
        Print(q);}
}

void PrintQ(struct queue q)
{
    if(q.isEmpty())
    return;
    struct queue q1;
    while(!q.isEmpty())
    {
        btptr t = q.DeQueue();
        if(t){
        cout<<t->data<<" ";
        if(t->lc)
        q1.EnQueue(t->lc);
        if(t->rc)
        q1.EnQueue(t->rc);}
    }
    cout<<endl;
    PrintQ(q1);
}

int main()
{
    cout<<"haha"<<endl;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    btptr BT = NULL;
    int a;
    cin>>a;
    Construct(BT, a);
    struct queue q;
    q.EnQueue(BT);
    //PrintQ(q);
    int max_len = 0;
    Find_count(BT, q, max_len, 0, 1);
    Print_Max_Bend(BT, q, max_len, 0 , 1);
}