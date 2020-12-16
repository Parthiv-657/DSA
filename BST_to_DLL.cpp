#include<iostream>
using namespace std;

struct bstnode
{
    struct bstnode* lc;
    int data;
    struct bstnode* rc;
};

typedef struct bstnode* dptr;

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

void Add_DLL(bstptr BT, dptr &head, dptr &tail){
    if(head != NULL){
        head->lc = BT;
        BT->rc = head;
        head = BT;
    }else{
        head = tail = BT;
    }
}

void BST_DLL_Conversion(bstptr BT, dptr &head, dptr &tail){
    if(BT == NULL)return;
    BST_DLL_Conversion(BT->rc, head, tail);
    Add_DLL(BT, head, tail);
    BST_DLL_Conversion(BT->lc, head, tail);
}

void Print(dptr head){
    if(head == NULL)return;
    cout<<head->data<<" ";
    Print(head->rc);
}

int main()
{
    freopen64("input.txt","r",stdin);
    bstptr BT = NULL;
    int a;
    while(cin>>a, a!=-1){
        Construct(BT,a);
    }
    dptr head = NULL, tail = NULL;
    BST_DLL_Conversion(BT, head, tail);
    Print(head);
}