#include<bits/stdc++.h>
using namespace std;

const int m = 3;

struct mstnode{
    int count =0;
    int key[m-1];
    struct mstnode* cptr[m]={NULL};
};

void Construct2(mstnode* &MT, int n){
    if(MT == NULL){
        MT = new(mstnode);
        MT->count = 1;
        MT->key[0] = n;
        return;
    }
    if(MT->count != m-1){
        if(n>MT->key[MT->count-1]){
            MT->key[MT->count++] = n;
            return;
        }
        for(int i=0; i<MT->count; i++){
            if(n<MT->key[i]){
                for(int j=MT->count; j>=i; j--)
                    MT->key[j] = MT->key[j-1];
                MT->key[i] = n;
                return;
            }
        }
    }
    for(int i=0; i<MT->count; i++){
        if(n<MT->key[i]){
            Construct2(MT->cptr[i], n);
            return;
        }
    }
    Construct2(MT->cptr[MT->count], n);
}

void Print(queue<mstnode*>q){
    if(q.size()==0)return;
    queue<mstnode*>q1;
    while(q.size()!=0){
        mstnode* temp = q.front();
        q.pop();
        for(int i=0; i<temp->count; i++)
        {
            cout<<temp->key[i]<<" ";
            if(temp->cptr[i])
            q1.push(temp->cptr[i]);
        }
        if(temp->cptr[temp->count])
        q1.push(temp->cptr[temp->count]);
    }
    cout<<endl;
    Print(q1);
}

int Delete_Helper(mstnode* MT, int i){
    if(MT->cptr[i+1] == NULL){
        int rx = MT->key[0];
        for(int idx=0; idx<MT->count; idx++){
            if(idx == MT->count-1){
                MT->count-=1;
                MT->cptr[idx] = MT->cptr[idx+1];
            }
            else if(idx == 0){
                MT->key[idx] = MT->key[idx+1];
            }
            else{
                MT->key[idx] = MT->key[idx+1];
                MT->cptr[idx] = MT->cptr[idx+1];
            }
        }
        return rx;
    }
    int rx = MT->key[0];
    MT->key[i] = Delete_Helper(MT->cptr[i+1], 0);
    return rx;
}

void Delete(mstnode* MT, int del){
    for(int i=0; i<MT->count; i++){
        if(del == MT->key[i]){
            Delete_Helper(MT, i);
            return;
        }else if(del<MT->key[i]){
            Delete(MT->cptr[i], del);
            return;
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    mstnode* MT = NULL;
    while(cin>>n,n!=-1)
        Construct2(MT, n);
    queue<mstnode*>q;
    q.push(MT);
    Print(q);cout<<endl;
    int k;cin>>k;
    Delete(MT, k);
    cin>>k;
    Delete(MT, k);
    Print(q);
}
