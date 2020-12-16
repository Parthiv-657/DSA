#include <iostream>
using namespace std;

struct bstnode{
    int data;
    struct bstnode* lc = NULL;
    struct bstnode* rc = NULL;
};

typedef struct bstnode* bstptr;

struct node{
    bstptr data;
    struct node* next = NULL;
};

typedef struct node* lptr;

void Add_End(lptr &L, bstptr BT){
    lptr temp = new(node);
    temp->data = BT;
    temp->next = NULL;
    if(L == NULL){
        L  = temp;
    }else{
        lptr l = L;
        while(l->next != NULL)
            l = l->next;
        l->next = temp;
    }
}

void Del(lptr &L){
    if(L == NULL)return;
    if(L->next == NULL){L = NULL;return;}
    lptr prev = NULL,curr = L;
    while(curr->next !=NULL){
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
}

void Insert(bstptr &BT, int a){
    if(BT == NULL){
        BT = new(bstnode);
        BT->data = a;
        return;
    }
    if(BT->data<a)
        Insert(BT->rc, a);
    else
        Insert(BT->lc, a);
}

void swap(bstptr &a, bstptr &b){
    bstptr c = a;
    a = b;
    b = c;
}

void Permutations(int sequen[], int i, int count, lptr L){
    if(i==count || L == NULL){
        for(int idx=0; idx<count ; idx++)
            cout<<sequen[idx]<<" ";
        cout<<endl;
        return;
    }
    lptr prev = NULL, curr = L;
    while(curr!=NULL){
        sequen[i]=curr->data->data;
        //remove node
        if(prev==NULL){
            L = L->next;
        }else{
            prev->next = curr->next;
        }int ch =0;
        //add childs
        if(curr->data->lc){
        Add_End(L, curr->data->lc);ch++;}
        if(curr->data->rc){
        Add_End(L, curr->data->rc);ch++;}
        Permutations(sequen, i+1, count, L);
        //remove child
        while(ch--)
        Del(L);
        //replace the deletd node
        if(prev==NULL){
            L = curr;
        }else{
            prev->next= curr;
        }
        //next iteration
        prev = curr;
        curr = curr->next;
    }
}

int main() {
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    bstptr BT = NULL;
    int a;int count =0;
    while(cin>>a, a!=-1){
        Insert(BT,a);count++;}
    lptr L = NULL;int sequen[count]={0};
    Add_End(L, BT);
    Permutations(sequen, 0, count, L);
}
