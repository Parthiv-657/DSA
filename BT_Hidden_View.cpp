#include<iostream>
using namespace std;

struct btnode
{
    struct btnode* lc;
    char data;
    struct btnode* rc;
};

typedef struct btnode* btptr;

void Construct(btptr &BT,string a,int &i)
{
    cout<<1<<endl;
    if(i == a.size())
    return;
    BT = new(btnode);
    BT->data = a[i];
    BT->lc = BT->rc = NULL;
    i++;
    if(a[i]!='#')Construct(BT->lc,a,i);
    i++;
    if(a[i]!='#')Construct(BT->rc,a,i);
}

void Hidden_Printer(btptr BT, bool a, bool b,btptr BT1)
{
    if(BT->lc == NULL && BT->rc == NULL)
    return;
    if(BT == BT1)
    Hidden_Printer(BT,true,false,BT1);
    else
    if(a==true)
    Hidden_Printer(BT,true, false, BT1);
    else
    Hidden_Printer(BT,false,false,BT1);
    if(a==false&&b==false)
    cout<<BT->data<<" ";
    if(BT == BT1)
    Hidden_Printer(BT->rc,false,true,BT1);
    else
    if(b = true)
    Hidden_Printer(BT,false, true, BT1);
    else
    Hidden_Printer(BT->rc, false, false,BT1);
}

int main()
{
    btptr BT = NULL;
    string s;
    cin>>s;
    int i =0;
    Construct(BT,s,i);
    Hidden_Printer(BT,false, false, BT);
}
