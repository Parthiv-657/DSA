#include<iostream>
using namespace std;

struct node{
    int data;
    struct node*  next;
};

typedef struct node* lptr;

void Construct(lptr &L)
{
    int n;lptr l;
    while(cin>>n,n!=-1)
    {
        lptr temp = new(node);
        temp->data = n;
        temp->next = NULL;
        if(L){
        l->next = temp;
        l = l->next;}
        else
        {
            L = temp;
            l = L;
        }   
    }
}

void Print(lptr L)
{
    if(L == NULL)return;
    cout<<L->data<<" ";
    Print(L->next);
}

int main()
{
    lptr L = NULL;
    Construct(L);
}