#include<iostream>
using namespace std;

union u{
    int i;
    char c;
    float f;
};

struct stack {
    int top ;
    union u elements[100];
    int tag [100];

    bool isEmpty()
    {
        if(top == -1)
            return true;
        return false;
    }

    void Ipush(int a)
    {
        tag[++top] = 0;
        elements[top].i = a;
    }

    void Cpush(char a)
    {
        tag[++top] = 1;
        elements[top].c = a;
    }

    void Fpush(float a)
    {
        tag[++top] = 2;
        elements[top].f = a;
    }

    union u pop(int &tag1)
    {
        tag1 = tag[top];
        return elements[top--];
    }
};

struct queue{
    int size = 100 ;
    int f = -1;
    int r = -1;
    stack elements[100];

    bool isEmpty()
    {
        if(f == -1)
        return true;
        return false;
    }
};

void EnQueue(struct queue &q,stack a){
    if((q.r+1)%q.size==q.f)
    {
        cout<<"Full"<<endl;
    }else{
        if(q.f==-1)
        {
            q.f+=1;
            q.r+=1;
            q.elements[q.r]=a;
        }else{
            q.r=(q.r+1)%q.size;
            q.elements[q.r]=a;
        }
    }
}
stack DeQueue(struct queue &q){
    if(q.f==-1)
    {
        cout<<"Empty"<<endl;
    }else{
        if(q.f==q.r)
        { 
            stack r= q.elements[q.f];
            q.f=-1;
            q.r=-1;
            return r;
        }else{
            stack r=q.elements[q.f];
            q.f=(q.f+1)%q.size;
            return r;
        }
    }
}


int main()
{
    struct queue q;
    struct stack s;
    s.Ipush(3);
    s.Cpush('a');
    s.Fpush(8.77);
    EnQueue(q,s);
    struct stack s1;
    s.Cpush('*');
    s.Cpush('a');
    s.Fpush(8.77);
    EnQueue(q,s1);
    while(!q.isEmpty())
    {
        int tag;union u u1;
        struct stack s2 = DeQueue(q);
        while(s2.isEmpty())
        {
            u1 = s2.pop(tag);
            switch(tag)
            {
                case 0:
                cout<<u1.i<<" ";
                case 1:
                cout<<u1.c<<" ";
                case 2:
                cout<<u1.f<<" ";
            }
        }
        cout<<endl;
    }
}
