#include<iostream>
using namespace std;

struct btnode
{
    struct btnode* lc;
    int data;
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

int Max_Finder(btptr BT,btptr &t)
{
    if(BT->lc == NULL && BT->rc == NULL)
    {
        t = BT;
        return BT->data;
    }else return Max_Finder(BT->rc);
}

int Min_Finder(btptr BT, btptr &t)
{
    if(BT->lc == NULL && BT->rc == NULL){
    t = BT;return BT->data;}
    else return Min_Finder(BT->lc);
}

btptr Find(btptr BT, int a)
{
    if(BT->data == a)
    return BT;
    if(BT->lc &&BT->data<a)
    Find(BT->rc,a);
    else if(BT->rc && BT->data>a)
    Find(BT->lc,a);
}

int main()
{
    btptr BT = NULL;
    int a;
    cin>>a;
    Construct(BT,a);
    int n;
    cin>>n;
    btptr BT1 = Find(BT,n);

}