#include<iostream>
using namespace std;

struct node{
    int data;
    struct node*  next;
};

typedef struct node* lptr;

struct stack{
    int top = -1;
    int element[100];
    
    bool isEmpty(){
        if(top == -1)
        return true;
        return false;
    }

    void push(int a){
        element[++top] = a;
    }

    int pop(){
        return element[top--];
    }

    int peek(){
        return element[top];
    }
};

void Construct(lptr &L)
{
    int n;lptr l;
    while(cin>>n,n!=-1)
    {
        lptr temp = new(node);
        temp->data = n;
        temp->next = NULL;
        if(L){
        l->next = temp;
        l = l->next;}
        else
        {
            L = temp;
            l = L;
        }   
    }
}

bool Palindrome_Checker(lptr L){
    lptr slow = L;
    lptr fast = L->next;
    stack s;
    bool flag = 0;
    while(true){
        if(fast->next!=NULL){
            s.push(slow->data);
            slow = slow->next;
            fast = fast->next;
            if(fast->next!=NULL){
                fast = fast->next;
            }else{
                flag = 1;
                break;}
        }
    }
    if(flag != 1) s.push(slow->data);
    slow = slow->next;
    while(!s.isEmpty()){
        if(slow->data == s.pop()){
            slow = slow->next;
        }else return false;
    }
    return true;
}

int main()
{
    freopen("input.txt","r",stdin);
    lptr L = NULL;
    Construct(L);
    cout<<Palindrome_Checker(L)<<endl;
}