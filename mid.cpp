#include<bits/stdc++.h>
using namespace std;

struct bnode
{
    bool flag =0;
    int data;
    bnode* lc;
    bnode* rc;
};

void Construct(bnode* &BT, int a){
    if(BT == NULL){
        BT = new(bnode);
        BT->data = a;
        BT->lc = BT->rc = NULL;
    }
    cin>>a;
    if(a)
        Construct(BT->lc, a);
    cin>>a;
    if(a)
        Construct(BT->rc, a);
}

void Print(stack<bnode*>s1, stack<bnode*>s2){
    if(s1.empty() && s2.empty())return;
    stack<bnode*>s3;
    while(!s2.empty()){
        bnode* temp = s2.top();s2.pop();
        cout<<temp->data<<" ";;
        temp->flag = 1;
        if(temp->lc && temp->lc->flag == 0)
            s3.push(temp->lc);
        if(temp->rc && temp->rc->flag == 0)
            s3.push(temp->rc);
    }
    if(!s1.empty()){
        bnode* temp = s1.top();s1.pop();
        cout<<temp->data<<" ";temp->flag = 1;
        if(temp->lc && temp->lc->flag == 0)
            s3.push(temp->lc); 
        if(temp->rc && temp->rc->flag == 0)
            s3.push(temp->rc);
    }
    cout<<endl;
    Print(s1, s3);
}

void Search(bnode* BT, int a, stack<bnode*>s, stack<bnode*>&s2){
    if(BT == NULL)return;
    if(BT->data == a){
        s.push(BT);
        s2 = s;
        return;
    }
    s.push(BT);
    Search(BT->lc, a, s, s2);
    Search(BT->rc, a, s, s2);
    return;
}

void Inorder(bnode* BT){
    if(BT == NULL)return;   
    Inorder(BT->lc);
    cout<<BT->data<<" ";
    Inorder(BT->rc);
}

int main(){
    freopen("input.txt","r",stdin);
    bnode* BT = NULL;
    int a;
    cin>>a;
    Construct(BT, a);
    cin>>a;
    Inorder(BT);cout<<endl;
    stack<bnode*>s;
    Search(BT, a, s, s);
    stack<bnode*>s2;
    cout<<endl;
    Print(s, s2);
}