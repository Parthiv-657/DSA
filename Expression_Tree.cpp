#include<iostream>
#include<string>
using namespace std;

struct expnode{
    struct expnode* lc;
    int tag;
    union {
        int oprnd;
        char optr;
    } data;
    struct expnode* rc;
};

typedef struct expnode* exptr;

int evalExpTree(exptr E)
{
    if(E->tag == 1)
        return E->data.oprnd;
    switch(E->data.optr)
    {
        case '+':
        return evalExpTree(E->lc) + evalExpTree(E->rc);
        break;
        case '-':
        return evalExpTree(E->lc) - evalExpTree(E->rc);
        break;
        case '*':
        return evalExpTree(E->lc) * evalExpTree(E->rc);
        break;
        case '/':
        return evalExpTree(E->lc) / evalExpTree(E->rc);
        break;
    }
}

void ConstructExpTree(exptr &E, string s, int &l)
{
    if(l==s.size())
        return;
    E = new(expnode);
    E->lc = E->rc = NULL;
    if(s[l]>57 || s[l]<48){
        E->tag = 0;
        E->data.optr = s[l];
        l += 1;
        ConstructExpTree(E->rc, s, l);
        l+=1;
        ConstructExpTree(E->lc, s, l);
    }else{
        E->tag = 1;
        E->data.oprnd = s[l]-'0';
    } 
    cout<<E->lc->lc->lc<<endl;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    cin>>s;
    for(int i = 0; i<s.size()/2; i++)
    {
        char c = s[i];
        s[i] = s[s.size()-i-1];
        s[s.size()-i-1] = c;
    }
    cout<<s<<endl;
    exptr E = NULL;
    int l = 0;
    ConstructExpTree(E, s, l);
    int a= evalExpTree(E);
    cout<<a<<endl;
}