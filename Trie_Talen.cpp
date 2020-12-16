#include<iostream>
using namespace std;
struct nod;
struct node;
union u;
struct nod{
    string s;
};
union u{
    node* ptr[4]={NULL};
    nod* str;
};
struct node{
    int tag=-1;
    union u u1;
};
void tag0(node* &T, string s){
    T = new(node);
    T->tag = 0;
    T->u1.str = new(nod);
    T->u1.str->s = s;
}
void Construct(node* T, string s){
    int n = s.size();
    node* parent = NULL;
    for(int i=0; i<n; i++){
        if(T->tag == 0){
            int idx = s[i-1]-'A';
            parent->u1.ptr[idx] = new(node);
            parent->u1.ptr[idx]->tag = 1;
            string str = T->u1.str->s;
            parent->u1.ptr[idx]->u1.ptr[str[i] - 'A'] = T;
            T = parent->u1.ptr[idx];
            i--;
            continue;
        }
        else if(T->u1.ptr[s[i] - 'A'] == NULL){
            tag0(T->u1.ptr[s[i] - 'A'], s);
            return;
        }
        else if(i == n-1 && T->u1.ptr[s[i] - 'A']!=NULL){
            if(T->u1.ptr[s[i] - 'A']->tag == 1){
                tag0(T->u1.ptr[s[i] - 'A']->u1.ptr[3], s);
                return;
            }else{
                node* temp = T->u1.ptr[s[i] - 'A'];
                string str = temp->u1.str->s;
                T->u1.ptr[s[i] - 'A'] = new(node);
                T->u1.ptr[s[i] - 'A']->tag = 1;
                tag0(T->u1.ptr[s[i] - 'A']->u1.ptr[3], s);
                T->u1.ptr[s[i] - 'A']->u1.ptr[str[i+1] - 'A'] = temp; 
            }
        }
        parent = T;
        T = T->u1.ptr[s[i] - 'A'];
    }
}
void Print(node* T){
    if(T == NULL)return;
    if(T->tag == 0){
        cout<<T->u1.str->s<<endl;
        return;
    }
    for(int i=0; i<4; i++){
        Print(T->u1.ptr[i]);
    }
}
int main(){
    string s;
    node* T = NULL;
    T = new(node);
    T->tag = 1;
    while(cin>>s, s!="#")
        Construct(T, s);
    Print(T);
    while(cin>>s, s!="#")
        Construct(T, s);
    Print(T);
    while(cin>>s, s!="#")
        Construct(T, s);
    Print(T);
}