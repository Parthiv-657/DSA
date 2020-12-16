#include<bits/stdc++.h>
using namespace std;

struct gtnode{
    char data;
    gtnode* ns = NULL;
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

void Level_Print(queue<gtnode*>q){
    if(q.size() == 0)return;
    int n = q.size();
    for(int i=0; i<n; i++){
        gtnode* temp = q.front();
        q.pop();
        while(temp!=NULL){
            q.push(temp->fs);
            cout<<temp->data<<" ";
            temp = temp->ns;
        }
    }
    cout<<endl;
    Level_Print(q);
}

int main(){
    string s;
    cin>>s;
    gtnode* GT = NULL;
    int i=0;
    Construct(GT, s, i);
    queue <gtnode*>q;
    q.push(GT);
    Level_Print(q);
}