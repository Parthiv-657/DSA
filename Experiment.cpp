#include<iostream>
using namespace std;

struct bstnode
{
    struct bstnode* lc = NULL;
    int data;
    struct bstnode* rc = NULL;
};

typedef struct bstnode* bstptr;

void Construct(bstptr &BT, int a)
{
    if(BT == NULL)
    {
        BT = new(bstnode);
        BT->data = a;
        BT->lc = BT->rc = NULL;
        return;
    }
    if(BT->data < a)
        Construct(BT->lc, a);
    else
        Construct(BT->rc, a);
}

void left_rotation(bstptr &BT){
    bstptr r = BT->rc;
    BT->rc = r->lc;
    r->lc = BT;
    BT = r;
}

void right_rotation(bstptr &BT){
    bstptr l = BT->lc;
    BT->lc = l->rc;
    l->rc = BT;
    BT = l;
}

void Rrotate(bstptr &BT, int a){
    if(BT->data == a){
        left_rotation(BT);
        return;
    }
    if(a<BT->data)
        Rrotate(BT->lc, a);
    else 
        Rrotate(BT->rc, a);
}

void Print(bstptr T){
    if(T = NULL)return;
    cout<<T->data<<" ";
    Print(T->lc);
    Print(T->rc);
}

int main(){
    int n;
    int m;
    bstptr BT = NULL;
    while(cin>>m, m!=-1){
        Construct(BT, m);
        while(cin>>n,n!=0){
            Construct(BT, n);
        }
        cin>>n;
        Rrotate(BT, n);
    } 
    Print(BT);
}