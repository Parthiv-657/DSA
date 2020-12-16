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

bool Loop_Detector(lptr L, lptr &l)
{
    lptr fast = L;
    lptr slow = L;
    while(slow!=NULL&&fast!= NULL&&fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast){
            l = slow;
            return 1;
        }
    }
    return 0;
}

int main()
{
    lptr L = NULL;
    Construct(L);
    lptr haha = L;
    while(haha->next !=NULL)
    haha = haha->next;  
    haha ->next = L->next->next;
    lptr l;
    if(Loop_Detector(L,l)){
        cout<<l->data<<endl;
        lptr t = l;
        while(t->next!=l)
        t = t->next;
        t->next = NULL;
    }
    Print(L);
}