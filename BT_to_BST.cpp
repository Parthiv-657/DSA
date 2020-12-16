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

void Add_Root(btptr BT, btptr root){
    if(BT==NULL)return;
    Add_Root(BT->lc, root);
    if(BT->data>root->data){
        BT->data += root->data;
        root->data = BT->data - root->data;
        BT->data = BT->data - root->data;
    }
    Add_Root(BT->rc, root);
}

void Add_Right(btptr BT, btptr R){
    if(R->lc)Add_Right(BT, R->lc);
    Add_Root(BT, R);
    if(R->rc)Add_Right(BT, R->rc);
}

void InOrder(btptr BT){
    if(BT == NULL)return;
    InOrder(BT->lc);
    InOrder(BT->rc);
    if(BT->lc)Add_Root(BT->lc, BT);
    if(BT->rc)Add_Right(BT, BT->rc);
}

void Print(btptr BT){
    if(BT->lc)Print(BT->lc);
    cout<<BT->data<<" ";
    if(BT->rc)Print(BT->rc);
}

int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    btptr BT = NULL;
    int a;
    cin>>a;
    Construct(BT,a);
    InOrder(BT);
    Print(BT);
}