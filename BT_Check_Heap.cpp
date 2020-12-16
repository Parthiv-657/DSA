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

bool Check_Heap(btptr BT)
{
    if(BT == NULL)return true;
    if(BT->lc){
        if(BT->data<BT->lc->data)
        return true*Check_Heap(BT->lc);
        else
        return false;
    }
    if(BT->rc){
        if(BT->data<BT->rc->data)
        return true*Check_Heap(BT->rc);
        else
        return false;
    }
}

bool Check_Complete(struct queue q)
{
    if(q.isEmpty())return true;
    struct queue q1;
    bool flag = 0;
    btptr t;
    while(!q.isEmpty())
    {
        btptr t = q.DeQueue();
        if(t->lc)
        q1.EnQueue(t->lc);
        else{
        break;flag = 0;}
        if(t->rc)
        q1.EnQueue(t->rc);
        else {
        break;flag =1;}
    }
    if(flag == 0)
    if(t->rc!=NULL)
    return false;
    while(!q.isEmpty())
    {
        t = q.DeQueue();
        if(t->lc == NULL&& t->rc == NULL)
        ;else return false;
    }
    return true;
}

int main()
{   
    freopen("input.txt","r",stdin);
    btptr BT = NULL;
    int a;
    cin>>a;
    Construct(BT,a);
    struct queue q;
    q.EnQueue(BT);
    if(Check_Complete(q))
    cout<<Check_Heap(BT)<<endl;
    else
    {
        cout<<"Not a complete Tree"<<endl;
    }
    
}