#include<iostream>
using namespace std;

typedef struct node* lptr;  

struct node{
    int data;
    struct node *next;
};

void Print(struct node *L){
    if(L==NULL){
        return ;
    }
    int a = L->data;
    cout<<a<<" ";
    Print(L->next);
    
}
void Insert(lptr &L)
{
    lptr l;
    int n;
    while(cin>>n,n!=-1)
    {
        lptr temp = new(node);
        temp->data = n;
        temp->next = NULL;
        if(L==NULL)
        {
            L = temp;
            l= L;
        }else{
            l->next = temp;
            l = l->next;
        }
    }
}

void InserLL(lptr &L)
{
    lptr nod = L;
    while(nod->next !=NULL)
    {
        lptr l = L,prevl=NULL;
        if(nod->data > nod->next->data)
        {
            while(l->data < nod->next->data){
                prevl = l;
                l = l->next;}
            if(prevl==NULL)
            {
                L=nod->next;
                nod->next = nod->next->next;
                L->next=l;
            }else{
                prevl->next = nod->next;
                nod->next = nod->next->next;
                prevl->next->next = l; 
            }
        }
        nod = nod->next;
    }
    
}

int main()
{
    lptr L=NULL;
    Insert(L);
    InserLL(L);
    Print(L);
}
