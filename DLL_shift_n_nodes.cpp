#include<iostream>
using namespace std;

struct dnode{
    struct dnode* left =NULL;
    int data;
    struct dnode* right = NULL; 
};

typedef struct dnode* dlptr;

void Construct(dlptr &DL){
    dlptr l;int n;
    while(cin>>n,n!=-1){
        dlptr temp = new(dnode);
        temp->data = n;
        if(DL == NULL){
            DL = temp;
            l = temp;
        }else{
            l->right = temp;
            temp->left = l;
            l = l->right;
        }
    }
}

int Count(dlptr DL){
    int count = 0;
    while(DL!=NULL){
        count++;
        DL = DL->right;
    }
    return count;
}

void Shifter(dlptr &DL, int n){
    int count = Count(DL);
    n = n%count;
    dlptr d = DL;
    dlptr prev = NULL;
    for(int i=0; i<n ;i++){
        prev = DL;
        DL = DL->right;
    }
    prev->right = NULL;
    DL->left = NULL;
    dlptr end = DL;
    while(end->right!= NULL)
    end = end->right;
    end->right = d;
    d->left = end;
}

void Print(dlptr DL){
    if(DL == NULL){
        cout<<endl;
        return;
    }
    cout<<DL->data<<" ";
    Print(DL->right);
}

int main(){
    dlptr DL = NULL;
    Construct(DL);
    Shifter(DL, 3);
    Print(DL);
}