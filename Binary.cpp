#include<iostream>
using namespace std;

struct btnode{
    struct btnode *lc;
    char data;
    struct btnode *rc;
};

typedef struct btnode * btptr;


void InsertBT(btptr &T, char ch)
{
    if(T== NULL)
    {
        T = new(btnode);
        T->data = ch;
        T->lc = NULL;
        T->rc = NULL;
    }
    cin>>ch;
    if(ch!='.')
        InsertBT(T->lc,ch);
    cin>>ch;
    if(ch!='.')
        InsertBT(T->rc,ch);
}

void PrintBT(btptr T)
{
    if(T == NULL)
    return;
    if(T -> lc == NULL && T-> rc == NULL )
    {cout<<T->data<<" ";}
    else
    cout<<T->data<<" ";
    PrintBT(T->lc);
    PrintBT(T->rc);
}

void Recursiveldr(btptr T)
{
    if(T!=NULL)
    {
        Recursiveldr(T->lc);
        cout<<T->data<<" ";
        Recursiveldr(T->rc);
    }
}

void Recursivelrd(btptr T)
{
    if(T!=NULL)
    {
        Recursivelrd(T->lc);
        Recursivelrd(T->rc);
        cout<<T->data<<" ";
    }
}

void IterativeLDR(btptr T)
{
    
}

int main()
{
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file 
    freopen("input.txt", "r", stdin); 
    // Printing the Output to output.txt file 
    freopen("output.txt", "w", stdout);    
    btptr T = NULL;
    char c;
    cin>>c;
    InsertBT(T,c);
    Recursivelrd(T);
#endif 
    return 0; 
}