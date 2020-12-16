#include<iostream>
using namespace std;

struct queue{
    int size;
    int f;
    int r;
    int elements[100];
};

struct node{
    int data;
    struct node* next = NULL;
};

struct node mlnode{
    int data;
    struct node * down = NULL;
    struct mlnode* next = NULL;
};

typedef struct node* lptr;
typedef struct mlnode* mlptr;

bool isQEmpty(struct queue &q)
{
    if(q.f == -1&&q.r == -1)
        return true;
    return false;
}

bool isQFull(struct queue &q)
{
    if((q.r+1)%q.size == q.f)
        return true;
    return false;
}

void EnQueue(struct queue &q,int a){
    if(!isQFull)
    {
        if(q.f == -1)
        {
            q.f = 0;
            q.r = 0;
            q.elements[q.r] = a;
        }else{
            q.r = (q.r+1)%q.size;
            q.elements[q.r] = a;
        }
    }else{
        cout<<"FULL"<<endl;
        //return -100;
    }
}

int DeQueue( struct queue &q)
{
    if(!isQEmpty)
    {
        if(q.f == q.r)
        {
            int t= q.elements[q.f];
            q.f = -1;
            q.r = -1;
            return t;
        }else{
            int t = q.elements[q.f];
            q.f = (q.f+1)%q.size;
            return t;
        }
    }
}

void HelpInsert(lptr &L)
{
    int n; lptr l;
    while(cin>>n,n!=-1)
    {
        lptr temp = new(node);
        temp->data = n;
        if(L == NULL)
        {
            L = temp;
            l = L;
        }else{
            l->next = temp;
            l = l->next;
        }
    }
}

void Insert(mlptr &ML)
{
    int n,m;mpltr ml;
    while(cin>>n,n!=-2)
    {
        cin>>m;
        mlptr temp = new(mlnode);
        temp->data = n;
        if(ML == NULL)
        {
            ML = temp;
            ml = ML;
        }else{
            ml->next = temp;
            ml = ml->next;
        }
        if(m==1)
        HelpInsert(ML);
    }
}

int main()
{
    mlptr ML = NULL;
    Insert(ML);
}