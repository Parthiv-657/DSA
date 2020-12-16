
#include<iostream>
using namespace std;

struct btnode{
    struct btnode* lc = NULL;
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

    btptr DeQueue1()
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
                btptr t = elements[r];
                r = (r-1)%size;
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

bool Find(btptr BT, char a,int &i)
{
    if(BT == NULL)
    return false;
    if(BT->data == a){i =1;return true;}
    else return false + Find(BT->lc,a,i) + Find(BT->rc, a,i);
}

int main()
{
    freopen("input.txt","w",stdin);
    btptr BT = NULL;
    cout<<BT<<endl;
    string a;
    cin>>a;
    int i = 0;
    Construct(BT, a, i);
    cout<<BT<<endl;
    char c,b;
    cin>>b>>c;
    i = 0;int j =0;
    while((Find(BT->lc,b,i) && Find(BT->lc, b,i))||(Find(BT->rc, c,j) && Find(BT->rc, b,j)))
    {
        cout<<BT->data<<" ";
        if(i == 1)
        BT = BT->lc;
        else
        {
            BT = BT->rc;
        }
    }
}