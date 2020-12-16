#include<iostream>
using namespace std;

struct bstnode{
    struct bstnode* lc = NULL;
    int data;
    struct bstnode* rc = NULL;
};

typedef struct bstnode* bstptr;

struct queue{
    int size=100;
    int f=-1;
    int r=-1;
    bstptr elements[100];
    int max[100];
    int min[100];

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

    void EnQueue(bstptr a,int max_, int min_){
        if(!isFull())
        {   
            if(f == -1)
            {
                f = 0;
                r = 0;
                elements[r] = a;
                max[r] = max_;
                min[r] = min_;
            }else{
                r = (r+1)%size;
                elements[r] = a;
                max[r] = max_;
                min[r] = min_;
            }
        }else{
            cout<<"FULL"<<endl;
            //return -100;
        }
    }

    bstptr DeQueue(int &max_, int &min_)
    {
        if(!isEmpty())
        {
            if(f == r)
            {
                bstptr t = elements[f];
                max_ = max[f];
                min_ = min[f];
                f = -1;
                r = -1;
                return t;
            }else{
                bstptr t = elements[f];
                max_ = max[f];
                min_ = min[f];
                f = (f+1)%size;
                return t;
            }
        }
    }

    bstptr pop()
    {
        if(!isEmpty())
        {
            if(f == r)
            {
                bstptr t = elements[f];
                f = -1;
                r = -1;
                return t;
            }else{
                bstptr t = elements[r];
                r = (r-1)%size;
                return t;
            }
        }
    }
    bstptr peek()
    {
        if(!isEmpty())
            return elements[f];
    }
};

void Construct (int a[], int i, int size, struct queue q)
{
    if(q.isEmpty())
    return;
    if(i>=size)return; 
    struct queue q2; 
    while(!q.isEmpty())
    {
        if(i==size)
        return;
        int min,max;
        bstptr t = q.DeQueue(max,min);
        if(a[i]>min && a[i]<t->data){
            t->lc = new(bstnode);
            t->lc->data = a[i];
            i++;
            q2.EnQueue(t->lc,t->data,min);
        }
        if(i == size)
        return;
        if(a[i]<max && a[i]>t->data){
            t->rc = new(bstnode);
            t->rc->data = a[i];
            i++;
            q2.EnQueue(t->rc, max, t->data);
        }
    }
    Construct(a, i, size, q2);
}

void Print(struct queue q)
{
    if(q.isEmpty())
    return;
    struct queue q2;
    while(!q.isEmpty())
    {
        int min,max;
        bstptr t = q.DeQueue(min,max);
        cout<<t->data<<" ";
        if(t->lc)q2.EnQueue(t->lc,0,0);
        if(t->rc)q2.EnQueue(t->rc,0,0);
    }cout<<endl;
    Print(q2);
}

int main()
{
    freopen("input.txt","r",stdin);
    int a[100];
    int size = 0;int n;
    while(cin>>n,n!=-1)
    {a[size]= n;size++;}
    bstptr BT = NULL;
    BT = new(bstnode);
    BT->data = a[0];
    struct queue q;
    q.EnQueue(BT,999,-999);size += 1;
    Construct(a ,1, size, q);
    struct queue q2;
    q2.EnQueue(BT,0,0);
    Print(q2);
}