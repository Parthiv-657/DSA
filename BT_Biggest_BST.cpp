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

bool Check_BST(btptr BT, int min, int max )
{
    if(BT == NULL)
        return true;
    if(BT->data <max && BT->data >min)
    {
        return true*Check_BST(BT->lc, min, BT->data)*Check_BST(BT->rc, BT->data, max);
    }else
    {
        return false;
    }
    
}

int Count_BT(btptr BT)
{
    if(BT == NULL) return 0;
    return 1+ Count_BT(BT->lc) + Count_BT(BT->rc);
}

void Largest_BST(btptr BT, btptr &Max_BST,int &count)
{
    if(BT == NULL)return;
    if(Check_BST(BT,-999,999))
    {
        if(Count_BT(BT)>count){
            count = Count_BT(BT);
            Max_BST = BT;
        }
    }
    Largest_BST(BT->lc, Max_BST, count);
    Largest_BST(BT->rc, Max_BST, count);
}

void Print(btptr BT)
{
    if(BT == NULL){return;}
    Print(BT->lc);
    cout<<BT->data<<" ";
    Print(BT->rc);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    btptr BT = NULL;
    int a;
    cin>>a;
    Construct(BT,a);
    btptr Max_BST = NULL;
    int count = 0;
    Largest_BST(BT,Max_BST,count);
    Print(Max_BST);
}