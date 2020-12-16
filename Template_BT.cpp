#include<iostream>
using namespace std;

struct btnode
{
    struct btnode* lc;
    int data;
    struct btnode* rc;
};

int height(btnode* T){
    if(T == NULL)return -1;
    else return 1+max(height(T->lc), height(T->rc));
}

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

int main()
{
    btptr BT = NULL;
    int a;
    cin>>a;
    Construct(BT,a);
}