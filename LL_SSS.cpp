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
bool Find(struct node *L , int a ){
    
    while( L!=NULL )
    {
        if(L->data==a)
         return true;
        L = L->next;
    }
    return false;
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
void ReverseLL(lptr &L,int i){
    lptr LL = NULL;
    if(i==0)
    {
        LL = L;
        while(LL->next != NULL)
            LL = LL->next ;
    }
    if(L->next == NULL)
    {return;}
    if(L->next->next==NULL)
    {
        L->next->next = L;
        return;
    }
    ReverseLL(L->next,1);
    if(i==0)
    {
        L->next->next = L;
        L->next = NULL;
        L = LL;
    }else{
         L->next->next = L;
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

void Delete(lptr &L, int k){
    if(L->data == k)
    {
        L = L->next;
        Delete(L,k);
        return;
    }
    struct node * L1 = L;
    while( L1->next != NULL )
    {
        if(L1->next->data != k)
            L1 = L1->next;
        else
            L1->next = L1->next->next;
    }
}
void SortedDel(lptr L2)
{
    lptr L = L2;
    if(L->next == NULL)
        return;
    int a = L->data;
    lptr L1 = L->next;
    while(L1->data == a && L1->next!=NULL)
        L1 = L1->next;
    L->next = L1;
    SortedDel(L->next);
}
void Duplicate(lptr L)
{
    if(L->next == NULL)
    return;
    int a = L->data;
    Delete(L,a);
    Duplicate(L->next);
}
void LastDuplicate(lptr L,int a[])
{
    while(L->next!=NULL)
    {
        if(a[L->data]==0)
        {
            lptr l = L;
            int count = 0;
            while(l!=NULL)
            {
                if(l->data == L->data)
                    count++;
                l = l->next;
            }
            l = L;
            if(count>1)
            {
                while(l!=NULL)
                {
                    if(count == 1){
                        Delete(l,L->data);
                        a[L->data] = 1;
                        break;}
                    else{
                        if(l->data == L->data)
                            count--;
                        l = l->next;
                    }
                }
            }
        }
        L = L->next;
    }
}
void KReverse(lptr &L,int k)
{
    int n = count(L);
    if(k>n||2*k-1==n)
        return;
    lptr Xp=NULL,Xc=L,Yp=NULL,Yc=L;
    for(int i = 1 ; i<k ; i++)
    {  
        Xp = Xc ;  
        Xc = Xc->next;
    }
    for(int i = 1 ; i <= n-k ; i++)
    {
        Yp = Yc ;
        Yc = Yc->next;
    }
    lptr temp = Xc->next;
    if(Xp)
    Xp->next = Yc;
    if(Yp)
    Yp->next = Xc;
    Xc->next = Yc->next;
    Yc->next = temp;

    return;
}
bool CheckPresent(lptr L1,lptr L2)
{
    lptr l = L2;
    bool flag = 0;
    while(L1 != NULL)
    {
        if(L1->data == l->data)
        {
            while(l!=NULL)
            {
                if(l->data == L1->data)
                {
                    l = l->next;
                    L1 = L1->next;
                    flag = 1;
                }else{
                    flag = 0;
                    break;
                }
            }
            if(flag == 1)
            return flag;
            l = L2;
        }else{
            L1 = L1->next;
        }
    }
    return flag ;
}

void Union(lptr L1 , lptr L2 , lptr &L3 ){
    
    lptr l3=L3;
    int i =0;
    while(L1!=NULL && L2!=NULL){
        lptr temp=new(node);
        temp->next = NULL;
        if(i==0)
        {
            temp->data = L1->data;
            i=1;
            L1 = L1->next;
        }else if(i==1){
            temp->data = L2->data;
            i = 0;
            L2 = L2->next;
        }
        if(L3 == NULL)
        {
            L3 = temp;
            l3 = L3;
        }else{
            l3->next = temp;
            l3 = l3->next;
        }
    }
    while(L1!=NULL){
        
        lptr temp=new(node);
        temp->data = L1->data;
        temp->next = NULL;
        l3->next = temp;
        l3 = l3->next;
        L1 = L1->next;
        
    }
    while(L2!=NULL){
        lptr temp=new(node);
        temp->data = L2->data;
        temp->next = NULL;
        l3->next = temp;
        l3 = l3->next;
        L2 = L2->next;
    }
    
}
int main()
{
    //////11111111111
    lptr L1=NULL,l1,l2,L2=NULL;int n;int m;
    while(cin>>n,n!=-1)
    {
        struct node *temp = new(node);
        temp->data = n;
        temp->next = NULL;
        struct node *temp1 = new(node);
        temp1->data = n;
        temp1->next = NULL;
        if(L1==NULL)
        {
            L1 = temp;
            l1=L1;
        }else{
            l1->next = temp;
            l1 = l1 -> next;
        }
        if(L2==NULL)
        {
            L2 = temp1;
            l2=L2;
        }else{
            l2->next = temp1;
            l2 = l2 -> next;
        }
    }
    ReverseLL(L1,0);
    bool flag1 = 1;
    while(L1!=NULL)
    {
        if(L1->data != L2->data)
        {
            flag1 = 0;
            cout<<flag1<<endl;
            break;
        }
        L1 = L1->next;
        L2 = L2->next;
    }
    if(flag1 == 1)
    cout<<flag1<<endl;
    ///////222222222
    L2 = NULL;
    Insert(L2);
    SortedDel(L2);
    Print(L2);
    ////////3333333333333
    lptr L3=NULL;
    Insert(L3);
    Duplicate(L3);
    Print(L3);
    ////////444444444444
    int a[100] = {0};
    lptr L4=NULL;
    Insert(L4);
    LastDuplicate(L4,a);
    Print(L4);
    ////////777777777777
    lptr L7=NULL;
    Insert(L7);
    ReverseLL(L7,0);
    Print(L7);
    /////////888888888
    lptr L8=NULL;
    Insert(L8);
    int k;
    cin>>k;
    KReverse(L8,k);
    Print(L8);
    /////////9999999999
    lptr L9 = NULL;
    lptr L10 = NULL;
    Insert(L9);
    Insert(L10);
    cout<<CheckPresent(L9,L10)<<endl;
    //////////10101010101010
    L10 = NULL;
    Insert(L10);
    lptr L11 = NULL;
    Insert(L11);
    lptr L12 = NULL;
    Union(L10,L11,L12);
    Print(L12);
    
}