/********************Happiness is Not something you postpone For the future;
It is something you design  For the present.*************************/


#include<iostream>
using namespace std;

struct bstnode{
    struct bstnode *lc;
    int data;
    struct bstnode *rc;
};

typedef struct bstnode * bstptr;

void Insert(bstptr &T, int a)
{
    if(T == NULL)
    {
        T = new(bstnode);
        T->data = a;
        T->lc = T->rc =  NULL;
        return;
    }
    if(a<T->data)
    Insert(T->lc, a);
    else
    Insert(T->rc, a);
}

void Print(bstptr BT)
{
    if(BT == NULL)
    return;
    Print(BT->lc);
    cout<<BT->data<<" ";
    Print(BT->rc);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    bstptr BT1= NULL, BT2 = NULL;
    int n;
    while(cin>>n, n != -1)
        Insert(BT1,n);
    while(cin>>n, n!=-1)
        Insert(BT2,n);
    Print(BT1);cout<<endl;
    Print(BT2);cout<<endl;
}
