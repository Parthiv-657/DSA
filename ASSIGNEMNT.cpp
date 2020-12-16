#include<iostream>
using namespace std;

struct bstnode{
    struct bstnode *lc;
    int data;
    struct bstnode *rc;
};

typedef struct bstnode * bstptr;

struct queue{
    int size=100;
    int f=-1;
    int r=-1;
    bstptr elements[100];
};

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

void EnQueue(struct queue &q,bstptr a){
    if(!isQFull(q))
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

bstptr DeQueue( struct queue &q)
{
    if(!isQEmpty(q))
    {
        if(q.f == q.r)
        {
            bstptr t= q.elements[q.f];
            q.f = -1;
            q.r = -1;
            return t;
        }else{
            bstptr t = q.elements[q.f];
            q.f = (q.f+1)%q.size;
            return t;
        }
    }
}

void Construct(bstptr &T, int a[], int l, int h)
{
    if(l>h)
    return;
    if(l == h)
    {
        T= new(bstnode);
        T->data = a[h];
        T->lc = T->rc = NULL;
        return;
    }
    int b = a[h];
    int i = 0;
    for(i= l; i<h; i++)
    {
        if(a[i]>a[h])
        break;
    }
    T = new(bstnode);
    T->data = a[h];
    T->lc = T->rc = NULL;
    if(l<=i-1)
    Construct(T->lc,a,l,i-1);
    if(i<=h)
    Construct(T->rc,a,i,h-1);
}

void PrintBTR(struct queue &q)
{
    if(isQEmpty(q))
    return;
    struct queue s2;
    while(!isQEmpty(q))
    {
        bstptr t = DeQueue(q);
        cout<<t->data<<" ";
        if(t->lc)
        EnQueue(s2,t->lc);
        if(t->rc)
        EnQueue(s2,t->rc);
    }
    cout<<endl;
    PrintBTR(s2);
}

int main()
{
    freopen("input.txt", "r", stdin); 
    // Printing the Output to output.txt file 
    freopen("output.txt", "w", stdout);  
    int a[100]={0};
    int n;
    int count = 0;
    while(cin>>n, n!=-1)
    {
        a[count] = n;
        count++;
    }
    bstptr T = NULL;
    Construct(T,a,0,count-1);
    struct queue s;
    EnQueue(s,T);
    PrintBTR(s);
}






