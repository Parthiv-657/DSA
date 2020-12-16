#include<iostream>
using namespace std;

struct trnode
{
    bool word = 0;
    trnode* ptr[26]={NULL};
};

typedef trnode* tptr;

void Add(trnode* &T, string s){
    if(T == NULL)T = new(trnode);
    trnode* temp = T;
    for(int i=0; i<s.size(); i++){
        if(temp->ptr[s[i] - 'a'] == NULL)
        temp->ptr[s[i] - 'a'] = new(trnode);
        temp = temp->ptr[s[i] - 'a'];
    }
    temp->word = 1;
}

bool search(trnode* T, string s, int i){
    if(T == NULL)return 0;
    if(i == s.size()){
        if(T->word == 1)
            return 1;
        else 
            return 0;
    }
    return search(T->ptr[s[i] - 'a'], s, i+1);
}

void suggestion(trnode* T,string s){
    if(T->word == 1)
    cout<<s<<endl;
    for(int i=0; i<26; i++){
        if(T->ptr[i] != NULL){
            string s1 = s+char(i+97);
            suggestion(T->ptr[i], s1);
        }
    }
    return;
}

int main(){
    trnode* T = NULL;
    string s;
    while(cin>>s, s!="#") 
        Add(T, s);
    cin>>s;
    cout<<search(T, s, 0)<<endl;
    cin>>s;
    trnode* temp = T;
    for(int i=0; i<s.size(); i++){
        temp = temp->ptr[s[i]-'a'];
    }
    suggestion(temp, s);
}

/*struct trnode
{
    bool one_indicator = 0;
    string s;
    bool word = 0;
    trnode* ptr[26]={NULL};
};*/