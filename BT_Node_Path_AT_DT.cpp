#include<iostream>
using namespace std;

struct btnode{
    struct btnode* lc = NULL;
    int data;
    int at;
    int dt;
    struct btnode* rc = NULL;
};

typedef struct btnode* btptr;

struct stack{
    int top = -1;
    btptr elements[100];

    bool isEmpty()
    {
        if(top == -1)return true;
        return false;
    }

    void push(btptr t)
    {
        elements[++top] = t;
    }

    btptr pop()
    {
        if(!isEmpty())
        {
            btptr t = elements[top];
            top--;
            return t;
        }else cout<<"empty"<<endl;
    }
    btptr peek()
    {
        if(!isEmpty())
            return elements[top];
    }
};

void Construct(btptr &BT, int a)
{
    BT = new(btnode);
    BT->data = a;
    BT->lc = BT->rc = NULL;
    cin>>a;
    if(a)Construct(BT->lc,a);
    cin>>a;
    if(a)Construct(BT->rc,a);
}

void AT_DT(btptr BT, int &t, int &at1, int &at2, int &dt1, int &dt2, int a, int b)
{
    if(BT->data == a)
    at1 = t;
    if(BT->data == b)
    at2 = t;
    BT->at = t;
    t+=1;
    if(BT->lc)
    AT_DT(BT->lc,t,at1, at2, dt1, dt2, a, b);
    if(BT->rc)
    AT_DT(BT->rc,t,at1, at2, dt1, dt2, a, b);
    BT->dt = t;
    if(BT->data== a)
    dt1 = t;
    if(BT->data== b)
    dt2 = t;
    t++;
}

bool Checker(btptr BT, int a, int b, int &bool1)
{
    if(BT == NULL)return false;
    if(BT->at<=a&&BT->dt>=b){
    bool1 = 1;return true;}
    return false;
}

void Print(struct stack s,bool f)
{
    if(s.isEmpty())
    return;
    if(f == 0){
        btptr t = s.pop();
        cout<<t->data<<" ";
        Print(s, f);
    }
    else
    {
        btptr t = s.pop();
        Print(s, f);
        cout<<t->data<<" ";
    }  
    
}

void Find(btptr BT, int a, int d, struct stack &s)
{
    if(BT->at == a && BT->dt == d)
    {
        return;
    }else{
        int bl;
        if(Checker(BT->lc,a,d,bl))
        {
            s.push(BT->lc);
            Find(BT->lc, a, d, s);
        }else{
            s.push(BT->rc);
            Find(BT->rc, a, d, s);
        }
    }
}

void Print_Path(btptr BT, int a, int b, int at1, int at2, int dt1, int dt2)
{
    if(BT == NULL){
        return;}
    int bool1 =0,bool2 =0,bool3 =0,bool4 =0;
    if((Checker(BT->lc, at1, dt1,bool1) && Checker(BT->lc, at2, dt2,bool2)) || (Checker(BT->rc, at1, dt1, bool3)&& Checker(BT->rc, at2, dt2, bool4)))
    {
        if(bool1 == 1 && bool2 == 1){
        Print_Path(BT->lc,a,b,at1,at2,dt1,dt2);return;}
        else if(bool3 == 1 && bool4 == 1){
        Print_Path(BT->rc, a, b, at1, at2, dt1, dt2);return;}
    }

        struct stack s1, s2;
        Find(BT, at1, dt1, s1);
        Find(BT, at2, dt2, s2);
        Print(s1,0);
        cout<<BT->data<<" ";
        Print(s2,1);

}

int main()
{
    freopen("input.txt","r",stdin);
    btptr BT = NULL;
    int n;
    cin>>n;
    Construct(BT, n);
    int t=0,at1,at2,dt1,dt2,a,b;
    cin>>a>>b;
    AT_DT(BT, t, at1, at2, dt1, dt2, a, b);
    Print_Path(BT, a, b, at1, at2, dt1 , dt2);
}