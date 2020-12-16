#include<iostream>
using namespace std;

struct node{
    int data;;
    struct node* next;
};

typedef struct node* lptr;

void Construct(lptr &L)
{
    lptr l;int n;
    while(cin>>n, n!=-1){
        lptr temp = new(node);
        temp->data = n;
        temp->next = NULL;
        if(L){
            l->next = temp;
            l = l->next;
        }else{
            L = temp;
            l = L;
        }
    }
}

lptr Segregate(lptr &L){
    lptr itr = L;
    lptr prev = NULL,end = L;
    while(end->next != NULL){
        end = end->next;
    }lptr last = end;
    while(itr!= end){
        if(itr->data&2!=0){
            if(prev){
                prev->next  = itr->next;
                last->next = itr;
                last = last->next;
                itr->next = NULL;
                itr = prev->next;
            }else{
                L= L->next;
                last->next = itr;
                last = last->next;
                itr->next = NULL;
                itr = L;
            }
        }else{
            prev = itr;
            itr = itr->next;
        }
    }
}

void Print(lptr L){
    if(L==NULL){
        cout<<endl;
        return;
    }else{
        cout<<L->data<<" ";
        Print(L->next);
    }
}

int main(){
    freopen("input.txt","r",stdin);
    lptr L = NULL;
    Construct(L);
    Segregate(L);
    Print(L);
}