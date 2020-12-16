#include<iostream>
using namespace std;

struct btnode
{
    struct btnode* lc;
    int data;
    int at;
    int dt;
    struct btnode* rc;
};

typedef struct btnode* btptr;

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

void AT_DT(btptr BT, int &t)
{
    BT->at = t;
    t+=1;
    if(BT->lc)
    AT_DT(BT->lc, t);
    if(BT->rc)
    AT_DT(BT->rc, t);
    BT->dt = t;
    t++;
}

int main()
{
    freopen("input.txt","r",stdin);
    btptr BT = NULL;
    int a;
    cin>>a;
    Construct(BT,a);
    int t=0;
    AT_DT(BT, t);
}