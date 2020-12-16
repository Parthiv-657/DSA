#include<iostream>
using namespace std;

struct trpnode{
    trpnode* lc = NULL;
    char c;
    int i;
    trpnode* rc = NULL;
};

void left_rotation(trpnode* &BT){
    trpnode* r = BT->rc;
    BT->rc = r->lc;
    r->lc = BT;
    BT = r;
}

void right_rotation(trpnode* &BT){
    trpnode* l = BT->lc;
    BT->lc = l->rc;
    l->rc = BT;
    BT = l;
}

void Construct(trpnode* &T, int c, int i){
    if(T == NULL){
        T = new(trpnode);
        T->c = c;
        T->i = i;
        return;
    }
    if(c<T->c)
        Construct(T->lc, c, i);
    else
        Construct(T->rc, c, i);
    trpnode* temp = NULL;
    if(T->lc && T->i > T->lc->i)
        right_rotation(T);
    else if(T->rc && T->rc->i)
        left_rotation(T);
}

void Print(trpnode* T){
    if(T == NULL)return;
    Print(T->lc);
    cout<<T->c<<" "<<T->i<<" ";
    Print(T->rc);
}

void Delete_Helper(trpnode* BT, trpnode* parent, bool flag){
    if(BT->lc == NULL && BT->rc == NULL){
        if(flag == 0){
            parent->lc = NULL;
        }else{
            parent->rc = NULL;
        }
    }
    if(BT->lc && BT->rc == NULL){
        if(flag == 0){
            parent->lc = BT->lc;
        }else{
            parent->rc = BT->lc;
        }
    }else if(BT->rc && BT->lc == NULL){
        if(flag == 0){
            parent->lc = BT->rc;
        }else{
            parent->rc = BT->rc;
        }
    }else if(BT->lc && BT->rc){
        if(BT->lc->i < BT->rc->i){
            BT->i = BT->lc->i;
            BT->c = BT->lc->c;
            Delete_Helper(BT->lc, BT, 0);
        }else{
            BT->i = BT->rc->i;
            BT->c = BT->rc->c;
            Delete_Helper(BT->rc, BT, 1);
        }
    }
}

void Delete(trpnode* &BT, int c, trpnode* parent, bool flag){
    if(BT->c == c){
        Delete_Helper(BT, parent, flag);
        return;
    }
    if(c<BT->c)
        Delete(BT->lc, c, BT, 0);
    else
        Delete(BT->rc, c, BT, 1);
}

int main(){
    trpnode* T = NULL;
    char c;
    int i;
    while(cin>>c, c!='#'){
        cin>>i;
        trpnode* parent = NULL;
        Construct(T, c, i);
    }
    char a,b;
    cin>>a>>b;
    Delete(T, a, NULL, 0);
    Delete(T, b, NULL, 0);
    Print(T);
}