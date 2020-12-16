#include<iostream>
#include<map>
using namespace std;

struct htnode{
    struct htnode* lc = NULL;
    char data;
    int freq=0;
    struct htnode* rc = NULL;
};

void Insert(htnode* &HT, htnode* temp){
    if(HT == NULL)HT = temp;
    else{
        if(temp->freq < HT->freq)
            Insert(HT->lc, temp);
        else 
            Insert(HT->rc, temp);
    }
}

void Inorder_Print(htnode* HT, string s){
    if(HT == NULL)return;
    string s1 =s;
    if(HT->lc){
        s1+='0';
        Inorder_Print(HT->lc, s1);
    }
    cout<<HT->data<<" "<<s<<endl;
    if(HT->rc){
        s+='1';
        Inorder_Print(HT->rc, s);
    }
}

void Make(htnode* &neww , htnode* temp){
    if(neww == NULL)neww = temp;
    else{
        htnode* t = new(htnode);
        t->data = '#';
        t->freq = neww->freq + temp->freq;
        if(neww->freq < temp->freq)
        {
            t->lc = neww;
            t->rc = temp;
        }else{
            t->rc = neww;
            t->lc = temp;
        }
        neww = temp;
    }
    return;
}

void Inorder(htnode* &HThead ,htnode* &HT, htnode* prev, htnode* &neww, int &flag) {
    if(flag == 2) return;
    if(HT == NULL)return;
    Inorder(HT->lc,HT, neww, flag);
    if(prev==NULL){
        HThead = H
    }else{
        prev->lc = HT->rc;
    }
    Make(neww, HT);
    flag++;
    if(flag == 2){
        Insert(neww, HT);
    }
    Inorder(HT->rc,HT, neww, flag);
}

int main(){
    freopen("input.txt","w",stdin);
    int n;cin>>n;htnode* HT = NULL;
    while(n--){
        char c;
        int freq;
        cin>>c>>freq;
        htnode* temp = new(htnode);
        temp->data = c;
        temp->freq = freq; 
        Insert(HT, temp);
    }
    while(HT->lc!=NULL || HT->rc == NULL){
        htnode* neww = NULL;
        int flag = 0;
        Inorder(HT, NULL, neww, flag);
    }
}