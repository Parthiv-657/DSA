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

int size(gtnode* GT){
    int i=0;
    while(GT != NULL){
        i++;
        GT = GT->ns;
    }
    return i;
}

bool Check_Mirror(deque <gtnode*> q){
    if(q.empty())return true;
    //cout<<"haha"<<endl;
    if(q.size() == 1){
        gtnode* temp = q.front();
        temp = temp->fs;
        deque <gtnode*> q1;
        while(temp!=NULL){
            q1.push_back(temp);
            temp = temp->ns;
        }
        return Check_Mirror(q1);
    }
    deque <gtnode*> q1;
    deque <gtnode*> q2;
    //cout<<q.size()<<endl;
    while(q.size()!=0 && q.size()!=1){
        cout<<q.size()<<endl;
        gtnode* temp1 = q.front();
        gtnode* temp2 = q.back();
        q.pop_back();q.pop_front();
        //cout<<size(temp1->fs)<<" "<<size(temp2->fs)<<endl;
        if(size(temp1->fs) != size(temp2->fs))
            return false;
        if(temp1->fs)
            q1.push_back(temp1->fs);
        if(temp2->fs)
            q2.push_back(temp2->fs);
    }
    if(q.size() == 1 && q.front()->fs!=NULL)
        q1.push_back(q.front()->fs);
    while(!q2.empty()){
        q1.push_back(q2.back());
        q2.pop_back();
    }
    return Check_Mirror(q1);
}

int main(){
    freopen("input.txt","r",stdin);
    string s;
    cin>>s;
    gtnode* GT = NULL;
    int i=0;
    Construct(GT, s, i);
    deque <gtnode*>q;
    q.push_back(GT);
    if(Check_Mirror(q))
        cout<<"Mirror"<<endl;
    else 
        cout<<"Not Mirror"<<endl;
}