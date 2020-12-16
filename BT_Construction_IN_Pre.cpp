#include<iostream>
using namespace std;

struct btnode{
    struct btnode* lc = NULL;
    int data;
    struct btnode* rc = NULL;
};

typedef struct btnode* btptr;

void Construct_BST_IN_PR(btptr &BT, int in[], int lin, int pre[], int lpre, int size)
{
    if(size == 1)
    {
        BT = new(btnode);
        BT->data = in[lin];
        return;
    }
    int lsize = 0;
    for(int i = lin; i<lin+size; i++)
        if(in[i]==pre[lpre]){
            lsize = i; break;}
    BT = new(btnode);
    BT->data = pre[lpre];
    Construct_BST_IN_PR(BT->lc, in, lin, pre, lpre+1, lsize-lin);
    Construct_BST_IN_PR(BT->rc, in, lsize+1, pre, lpre+size+1, size-(lsize-lin+1)); 
}

void Print(btptr BT)
{
    if(BT == NULL){
        cout<<endl;return;}
    Print(BT->lc);
    cout<<BT->data<<" ";
    Print(BT->rc);
}

int main()
{
    //freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdin);
    int a[100];
    int b[100];
    int a1 = 0,b1 = 0;
    int n=0;
    cout<<a1<<endl;
    while( n != -1){
        cin>>n;
        a[a1] = n;
        a1++;
    }n = 0;
    while(n!=-1){
        cin>>n;
        b[b1] = n;b1++;
    }
    btptr BT = NULL;
    Construct_BST_IN_PR(BT, a,0,b, 0 , a1+1);
    Print(BT);
}