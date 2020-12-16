#include<bits/stdc++.h>
using namespace std;
struct btnode
{
    struct btnode* lc=NULL;
    int data;
    struct btnode* rc=NULL;
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
void Max_Bends(btptr BT, int tag,  int len, int &max_len, queue<int>q, queue<int> &max){
    if(BT->lc == NULL && BT->rc == NULL){ 
        q.push(BT->data);
        if(len > max_len){
            max_len = len;
            max = q;
        }
        return;
    }
    q.push(BT->data);
    if(tag == -1){
        if(BT->lc)
        Max_Bends(BT->lc, 0, 0, max_len, q, max);
        if(BT->rc)
        Max_Bends(BT->rc, 1, 0, max_len, q, max);
        return;
    }
    if(tag == 0){
        if(BT->lc)
        Max_Bends(BT->lc, 0, len, max_len, q, max);
        if(BT->rc)
        Max_Bends(BT->rc, 1, len+1, max_len, q, max);
    }else{
        if(BT->lc)
        Max_Bends(BT->lc, 0, len+1, max_len, q, max);
        if(BT->rc)
        Max_Bends(BT->rc, 1, len, max_len, q, max);
    }
}
int main(){
    btptr BT = NULL;
    int a;
    cin>>a;
    Construct(BT, a);
    int len = 0;
    queue<int>max,q;
    Max_Bends(BT, -1, 0, len, q, max);
    cout<<max.size()-1<<endl;
    while(!max.empty()){
        cout<<max.front()<<" ";
        max.pop();
    }
    cout<<endl;
    cout<<len<<endl;
}