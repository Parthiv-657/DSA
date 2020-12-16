/**********“Perhaps the most valuable result of an education is 
the ability to make yourself Do the thing you have to Do, 
when it ought to be done, whether you like it Or Not.”– Thomas Huxley*****/
#include<iostream>
using namespace std;

struct btnode{
    struct btnode* lc= NULL;
    char data;
    struct btnode* rc = NULL;
};

typedef struct btnode* btptr;

struct queue{
    int size=100;
    int f=-1;
    int r=-1;
    btptr elements[100];

    bool isEmpty()
    {
        if(f == -1&&r == -1)
            return true;
        return false;
    }

    bool isFull()
    {
        if((r+1)%size == f)
            return true;
        return false; 
    }

    void EnQueue(btptr a){
        if(!isFull())
        {   
            if(f == -1)
            {
                f = 0;
                r = 0;
                elements[r] = a;
            }else{
                r = (r+1)%size;
                elements[r] = a;
            }
        }else{
            cout<<"FULL"<<endl;
            //return -100;
        }
    }

    btptr DeQueue()
    {
        if(!isEmpty())
        {
            if(f == r)
            {
                btptr t = elements[f];
                f = -1;
                r = -1;
                return t;
            }else{
                btptr t = elements[f];
                f = (f+1)%size;
                return t;
            }
        }
    }

    btptr peek()
    {
        if(!isEmpty())
            return elements[f];
    }
};

void Print(struct queue q)
{
    if(q.isEmpty())
    return;
    struct queue q1;
    while(!q.isEmpty())
    {
        btptr t = q.DeQueue();
        if(t){
        cout<<t->data<<" ";
        if(t->lc)
        q1.EnQueue(t->lc);
        if(t->rc)
        q1.EnQueue(t->rc);}
    }
    cout<<endl;
    Print(q1);
}


int main()
{    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    cin>>s;
    //cout<<s.size();
    int i = 0;
    btptr BT = NULL;
    BT = new(btnode);
    BT->data = s[i];i+=1;
    struct queue q;
    q.EnQueue(BT);
    while(i!=s.size()-1)
    {
        //cout<<s[i]<<endl;
        btptr t = q.DeQueue();
        if(s[i]!='#')
        {
            t->lc = new(btnode);
            t->lc->data = s[i];
            q.EnQueue(t->lc);
        }
        i++;
        //cout<<s[i]<<endl;
        if(i!=s.size()-1 && s[i] != '#')
        {
            t->rc = new(btnode);
            t->rc->data = s[i];
            q.EnQueue(t->rc);
        }
        i++;
    }
    struct queue q2;
    q2.EnQueue(BT);
    cout<<BT->data<<endl;
    if(BT->lc == NULL)
    cout<<"Print kaku plsss dannam pedta"<<endl;
    Print(q2);
}