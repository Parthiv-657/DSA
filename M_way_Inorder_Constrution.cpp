#include<bits/stdc++.h>
using namespace std;
const int m = 3;

int returnlog(int n, int x)
{
    return int(log(n)/log(x));
}

struct mstnode{
    int key[m-1];
    mstnode* cptr[m]={NULL};
};

void Build(queue<mstnode*>q, int level){
    if(level == 1)return;
    queue<mstnode*>q1;
    while(!q.empty()){
        mstnode* temp = q.front();q.pop();
        for(int i=0; i<m; i++){
            temp->cptr[i] = new(mstnode);
            q1.push(temp->cptr[i]);
        }
    }
    Build(q1, level-1);
}

void Construct(mstnode* MT, int a[], int &i){
    if(MT == NULL)return;
    for(int idx=0; idx<m; idx++){
        if(idx == m-1){
            Construct(MT->cptr[m-1], a, i);
        }else{
            Construct(MT->cptr[idx], a, i);
            MT->key[idx] = a[i];i++;
        }
    }
}

void Print(queue<mstnode*>q){
    if(q.empty())return;
    queue<mstnode*>q1;
    while(!q.empty()){
        mstnode* temp = q.front();q.pop();
        for(int i=0; i<m-1; i++){
            if(temp->cptr[i])q1.push(temp->cptr[i]);
            cout<<temp->key[i]<<" ";
        }
        if(temp->cptr[m-1])q1.push(temp->cptr[m-1]);
    }
    cout<<endl;
    Print(q1);
}

int main(){
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    int a[100];
    int size=0;
    while(cin>>n,n!=-1){
        a[size] = n;
        size++;
    }
    //cout<<size<<endl;
    int level = returnlog(size+1, 3);
    //cout<<level<<endl;
    mstnode* MT = new(mstnode);
    queue<mstnode*>q;
    q.push(MT);
    Build(q, 3);
    int i=0;
    Construct(MT, a, i);
    Print(q);
    cout<<endl;
}