/*******************“Luck isn't as random as you think.
         Before that lottery ticket won the jackpot, someone had to buy it.”*************/

#include<iostream>
using namespace std;

struct nd{
    int data;
    struct node* ptr;
};

struct node{
    int data;
    struct node *next;
    struct node *random = NULL;
};

typedef struct node* lptr;


int Insert(lptr &L,struct nd* a[])
{
    lptr l;
    int i,j=1,k,idx=-1;
    while(j!=0)
    {
        cin>>i>>j>>k;
        lptr temp = new(node);
        temp->data = i;
        temp->next = NULL;
        temp->random = NULL;
        if(L==NULL)
        {
            L = temp;
            l = L;
        }else{
            l->next = temp;
            l = l->next;
        }
        if(k!=0)
        {
            idx++;
            a[idx]=new(nd);
            a[idx]->data = k;
            a[idx]->ptr = temp;
        }
        for(int itr = 0; itr<=idx ; itr++)
        {
            if(i==a[itr]->data)
            {
                a[itr]->ptr->random = temp;
                break;
            }
        }
    }
    return idx;
}

void Print(lptr L , struct node* a[] , int j , int n)
{
    if(L==NULL) return;
    cout<<L->data<<" ";
    if(a[j] == L&& j<n)
    Print(L->random, a, j+1,n);
    else
    Print(L->next,a,j,n);
}

bool Check (lptr L , struct node* a[] , int n )
{
    int i = 0;
    while(L != NULL)
    {
        if(L == a[i]){
            L = L->random;i++;}
        else{
            L = L->next;
        }
    }
    if(i==n+1)
    return true;
    return false;
}


void Combination(lptr L, struct nd* a[], struct node* arr[], int j, int n, int i)
{
    if(Check(L, arr, i-1))
    {
        Print(L,arr,0,i);
        cout<<endl;
    }
    for(j ; j<=n ; j++)
    {
        arr[i] = a[j]->ptr;
        Combination(L,a,arr,j+1,n,i+1);
    }
    
}
int main()
{
    lptr L = NULL;
    struct nd* a[10];
    struct node* arr[10];
    int idx = Insert(L,a);
    Combination(L,a,arr,0,idx,0);
}





