#include<bits/stdc++.h>
using namespace std;

struct gtnode{
    gtnode* ns = NULL;
    char data;
    bool flag = 0;
    gtnode* fs = NULL;
};

void Construct(struct gtnode* &GT, string s, int &i){
    if(GT == NULL){
        GT = new(gtnode);
        GT->data = s[i];
    }
    i++;
    if(s[i]!='.')
        Construct(GT->fs, s, i);
    i++;
    if(s[i]!='.')
        Construct(GT->ns, s, i);
}

void Inorder(gtnode* GT){
    cout<<GT->data;
    gtnode* temp = GT->fs;
    if(temp){
    while(temp->flag == 1){
        temp = temp->ns;
    }}
    if(temp){
        Inorder(temp);
    }else{
        cout<<'.';
    }
    temp =temp->ns;
    if(temp){
    while(temp->flag == 1){
        temp = temp->ns;
    }}
    if(temp){
        Inorder(temp);
    }else{
        cout<<'.';
    }
    temp = GT->fs;
    bool flag = 0;
    while(temp!=NULL){
        if(temp->flag == 0)
        {flag = 1;break;}
        temp = temp->ns;
    }
    if(flag == 0)
    GT->flag = 1;
}

int main(){
    string s;
    cin>>s;
    int i=0;
    gtnode* GT=NULL;
    Construct(GT, s, i);
    while(GT->flag !=1){
        Inorder(GT);
        cout<<endl;
    }
}





