#include<iostream>
using namespace std;

typedef struct node* lptr;  

struct node{
    int data;
    struct node *next;
};

int count (lptr L)
{
    int n = 0;
    while(L!=NULL)
    {
        n++;
        L = L->next;
    }return n;
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

void Print(struct node *L){
    if(L==NULL){
        return ;
    }
    int a = L->data;
    cout<<a<<" ";
    Print(L->next);
}

void AddEnd(lptr &L, lptr t){
    if(L==NULL)
    {
        L =t;
    }else{
        lptr l = L;
        while(l->next != NULL){
            l = l->next;
        }l->next = t;
    }
}

lptr Partition(lptr L, lptr &l, lptr &r){
    l = L;
    while(l->next!=NULL)
        l = l->next;
    lptr pi = l;
    l = L;
    lptr prev = NULL;
    while(L!=pi){
        if(L->data>pi->data){
            lptr t = L->next;
            if(prev){
                prev->next = t;
                AddEnd(pi, L);
                L->next = NULL;
                L = t;
            }else{
                l = l->next;
                AddEnd(pi, L);
                L->next = NULL;
                L = t;
            }
        }
        else{prev = L; L= L->next;}
    }
    if(l == pi)l = NULL;
    r = pi->next;
    return pi;
}

void Nullify(lptr l, lptr pi){
    if(l){
        while(l->next!=pi)
            l = l->next;
        l->next = NULL;
    }
    pi->next = NULL;
    return;
}

void Quick_Sort(lptr &L){
    if(L == NULL || L->next == NULL)
        return;
    lptr l = NULL;
    lptr r = NULL;
    lptr pi = Partition(L, l, r);
    Nullify(l, pi);
    Quick_Sort(l);
    Quick_Sort(r);
    lptr temp;
    if(l) temp = l; else temp = pi;
    if(l){
    while(l->next!=NULL)
    l = l->next;l->next = pi;}
    pi->next = r;
    L = temp;
}

int main()
{
    freopen("input.txt","r",stdin);
    lptr L=NULL;
    Insert(L);
    Quick_Sort(L);
    Print(L);cout<<endl;
}