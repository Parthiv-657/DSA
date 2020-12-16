#include<iostream>
using namespace std;

struct bstnode
{
    struct bstnode* lc;
    int data;
    struct bstnode* rc;
};

typedef struct bstnode* bstptr;

void Construct(bstptr &BT, int a)
{
    if(BT == NULL)
    {
        BT = new(bstnode);
        BT->data = a;
        BT->lc = BT->rc = NULL;
    }
    if(BT->data < a)
        Construct(BT->lc, a);
    else
        Construct(BT->rc, a);
}

int main()
{
    bstptr BT = NULL;
    int a;
    while(cin>>a, a!=-1){
        Construct(BT,a);
    }
}