#include<iostream>
using namespace std;

struct bstnode
{
    struct bstnode* lc;
    int data;
    struct bstnode* rc;
};

struct dlnode{
    struct dlnode* left=NULL;
    int data;
    struct dlnode* right = NULL;
};

typedef struct dlnode* dlptr;

typedef struct bstnode* bstptr;

void Construct(bstptr &BT, int a)
{
    if(BT == NULL)
    {
        BT = new(bstnode);
        BT->data = a;
        BT->lc = BT->rc = NULL;
        return;
    }
    if(BT->data < a)
        Construct(BT->rc, a);
    else
        Construct(BT->lc, a);
}

void Add_End_DL(dlptr &head, dlptr &tail, int data){
    dlptr temp = new(dlnode);
    temp->data = data;
    if(head == NULL){
        head = tail = temp;
    }else{
        tail->right = temp;
        temp->left = tail;    
        tail = temp;    
    }
}

void Make_DLL(bstptr BT, dlptr &head, dlptr &tail){
    if(BT == NULL)return;
    Make_DLL(BT->lc, head, tail);
    Add_End_DL(head, tail, BT->data);
    Make_DLL(BT->rc, head, tail);
}

void S_Finder(dlptr head, dlptr tail, int s){
    while(tail->left != head){
        dlptr temp_head = head->right;
        dlptr temp_tail = tail;
        while(temp_head!=temp_tail && temp_head->left!=temp_tail){
            if(head->data+temp_tail->data+temp_head->data == s){
                cout<<head->data<<" "<<temp_head->data<<" "<<temp_tail->data<<endl;
                temp_head = temp_head->right;
                temp_tail = temp_tail->left;
            }else if(head->data+temp_tail->data+temp_head->data > s){
                temp_tail = temp_tail->left;
            }else{
                temp_head = temp_head->right;
            }
        }
        head = head->right;
    }
}

void Print(dlptr DL){
    if(DL == NULL)return;
    cout<<DL->data<<" ";
    Print(DL->right);
}

void BTPrint(bstptr BT){
    if(BT == NULL)return;
    BTPrint(BT->lc);
    cout<<BT->data<<" ";
    BTPrint(BT->rc);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    bstptr BT = NULL;
    int a;
    while(cin>>a, a!=-1){
        Construct(BT,a);
    }
    //BTPrint(BT);
    //cout<<endl;
    int s;
    cin>>s;
    dlptr head = NULL;
    dlptr tail = NULL;
    Make_DLL(BT, head, tail);
    //cout<<head->data<<" "<<tail->data<<endl;
    //Print(head);
    S_Finder(head,tail , s);
}

