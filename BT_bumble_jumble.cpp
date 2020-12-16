#include<bits/stdc++.h>
using namespace std;

struct btnode
{
    struct btnode* lc;
    int data;
    struct btnode* rc;
};

typedef struct btnode* btptr;

void Construct(btptr &BT, int a)
{
    BT = new(btnode);
    BT->data = a;
    BT->lc = BT->rc = NULL;
    cin>>a;
    if(a)Construct(BT->lc,a);
    cin>>a;
    if(a)Construct(BT->rc,a);
}

void Level_Order(queue <btptr> q){
    if(!q.empty())
        return;
    int i = q.size();bool flag = false;
    while(i--){
        btptr t = q.front();
        q.pop();
        if(flag){
            
        }
    }
    if(flag){
        i = q.size();
        while(i--){
            btptr t = q.front();
            q.pop();
            cout<<t->data<<" ";
            q.push(t);
        }
    }
    while(!q.empty()){
        btptr t = q.front();
        q.pop();
        if(t->lc)
            q.push(t->lc);
        if(t->rc)
            q.push(t->rc);
    }
}

int main()
{
    btptr BT = NULL;
    int a;
    cin>>a;
    Construct(BT,a);
}
