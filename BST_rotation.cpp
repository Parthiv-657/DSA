#include<bits/stdc++.h>
using namespace std;

struct bstnode{
    bstnode* lc = NULL;
    int data;
    bstnode* rc = NULL;
};

typedef struct bstnode* bstptr;

void Construct(bstptr &BT, int a){
    if(BT == NULL){
        BT = new(bstnode);
        BT->data =a ;
        return;
    }
    if(a<BT->data)
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

void shift(bstptr &BT, int a){
    if(BT->data == a)
        return;
    if(a<BT->data){
        shift(BT->lc, a);
        right_rotation(BT);
    }
    else{ 
        shift(BT->rc, a);
        left_rotation(BT);
    }
}

void rotate(bstptr &BT1, bstptr &BT2){
    if(BT1 == NULL || BT2 == NULL)return;
    if(BT1->data != BT2->data)
        shift(BT1, BT2->data);
    rotate(BT1->lc, BT2->lc);
    rotate(BT1->rc, BT2->rc);
}

void Print(bstptr BT){
    if(BT == NULL)return;
    cout<<BT->data<<" ";
    Print(BT->lc);
    Print(BT->rc);
}

int main(){
    freopen64("input.txt", "r", stdin);
    bstptr BT1 = NULL,BT2 = NULL;
    int n;
    while(cin>>n, n!=-1)
        Construct(BT1, n);
    while(cin>>n, n!=-1)
        Construct(BT2, n);
    rotate(BT1, BT2);
    Print(BT1);
}
