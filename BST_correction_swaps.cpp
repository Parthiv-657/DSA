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
    int tag[100] = {0};

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

    void EnQueue(bstptr a,int tag1){
        if(!isFull())
        {   
            if(f == -1)
            {
                f = 0;
                r = 0;
                elements[r] = a;
                tag[r] = tag1;
            }else{
                r = (r+1)%size;
                elements[r] = a;
                tag[r] = tag1;
            }
        }else{
            cout<<"FULL"<<endl;
            //return -100;
        }
    }

    bstptr DeQueue(int &tag1)
    {
        if(!isEmpty())
        {
            if(f == r)
            {
                bstptr t = elements[f];
                tag1 = tag[f];
                f = -1;
                r = -1;
                return t;
            }else{
                bstptr t = elements[f];
                tag1 = tag[f];
                f = (f+1)%size;
                return t;
            }
        }
    }
};

void Construct(bstptr &T, int a)
{
    if(T == NULL)
    {
        T = new(bstnode);
        T->data = a;
        T->lc = T->rc =  NULL;
    }
    cin>>a;
    if(a!=0)
    Construct(T->lc,a);
    cin>>a;
    if(a!=0)
    Construct(T->rc,a);
}

bool check(struct queue q, int t, bstptr &s)
{
    while(!q.isEmpty())
    {
        int tag;
        bstptr T = q.DeQueue(tag);
        cout<<T->data<<" ";
        if(t==0 && t>T->data){
            s = T;
            return true;
        }
        if(t==1 && t<T->data){
            s = T;
            return true;
        }
    }cout<<endl;
    return false;
}

void Check(bstptr T, struct queue q, bool &gamechanger, bstptr &a, bstptr &b)
{
    if(gamechanger == false||T == NULL)
        return;
    if(check(q,T->data,a))
    {
        b = T;
        gamechanger = false;
    }
    int tag;
    cout<<T->data<<" a"; 
    q.EnQueue(T, 0);
    Check(T->lc, q, gamechanger, a, b);
    q.DeQueue(tag);
    q.EnQueue(T, 1);
    Check(T->rc, q, gamechanger, a, b);
    q.DeQueue(tag);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    bstptr T = NULL;
    int a;
    cin>>a;
    Construct(T,a);
    bstptr s1,s2;
    struct queue q;
    bool gamechanger = true;
    Check(T,q,gamechanger,s1,s2);
    cout<<s1->data<<" "<<s2->data<<endl;
}