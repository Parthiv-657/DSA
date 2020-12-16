#include<iostream>
#include<map>
using namespace std;

struct htnode{
    struct htnode* lc;
    char data;
    struct htnode* rc;
};

typedef struct htnode* htptr;

struct st{
    int i;
    htptr h;
};

struct queue{
    int f =-1;
    int r=-1;
    int size = 100;
    struct st elements[100];

    bool isEmpty()
    {
        if(f == -1)
        return true;
        return false;
    }

    bool isFull()
    {
        if((r+1)%size == f)
        return true;
        return false;
    }

    void Enq(struct st s)
    {
        if(!isFull())
        {
            if(f == -1)
            {
                f =0;r =0;
                elements[f] = s;
            }else{
                r = (r+1)%size;
                elements[r] = s;
            }
        }
    }

    struct st Deq()
    {
        if(!isEmpty()){
            if(r == f)
            {
                struct st s = elements[f];
                f = -1;
                r = -1;
                return s;
            }else{
                struct st s = elements[f];
                f = (f+1)%size;
                return s;
            }
        }
        else cout<<"empty"<<endl;
    }

    struct st peek()
    {
        if(!isEmpty())
            return elements[f];
    }
};

void Assign_Map(htptr HT, map<char, string> &Encoder,string s)
{
    if(HT->lc == NULL && HT->rc == NULL){
        Encoder[HT->data] = s;
        return;
    }
    if(HT->lc){
        string s1;
        for(int i =0; i<s.size(); i++)
        s1 += s[i];
        s1+='0';
        Assign_Map(HT->lc, Encoder, s1);
    }
    if(HT->rc){
        string s1;
        for(int i =0; i<s.size(); i++)
        s1 += s[i];
        s1+='1';
        Assign_Map(HT->rc, Encoder, s1);
    }
}

void Min_Finder(struct queue q, struct st &h1, struct st &h2,struct queue &q1)
{
    struct st st1 = q.Deq();
    struct st st2 = q.Deq();
    if(st1.i>st2.i)
    {
        struct st temp = st1;
        st1 = st2;
        st2 = temp;
    }
    struct queue q2;
    while(!q.isEmpty())
    {
        struct st st3 = q.Deq();
        if(st3.i<st1.i){
            q2.Enq(st2);
            st2 = st1;
            st1 = st3;
        }
        else if(st3.i>=st1.i && st3.i< st2.i){
            q2.Enq(st2);
            st2 = st3;
        }
        else
            q2.Enq(st3);
    }
    h1 = st1;
    h2 = st2;
    q1 = q2;
}

htptr Construct(struct queue q)
{
    struct st st1 = q.Deq();
    if(q.isEmpty())
    return st1.h;
    q.Enq(st1);
    struct st st2;
    Min_Finder(q,st1, st2, q);
    struct st st3;
    st3.i = st1.i + st2.i;
    htptr temp  = new(htnode);
    temp->lc = st1.h;
    temp->rc = st2.h;
    st3.h = temp;
    q.Enq(st3);
    Construct(q);
}

int main()
{
    freopen("input.txt","r",stdin);
    struct queue q;
    int i;char c;
    while(cin>>i>>c,i != -1)
    {
        struct st s;
        s.i = i;
        s.h = new(htnode);
        s.h->data = c;
        s.h->lc = s.h->rc = NULL;
        q.Enq(s);
    }
    htptr HT = NULL;
    HT = Construct(q);
    std::map <char, string> Encoder;
    string s;
    Assign_Map(HT, Encoder, s);
    cout<<Encoder['n']<<endl;
}