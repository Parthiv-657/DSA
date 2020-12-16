#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

typedef struct node* lptr;

struct Heap{
    int size=-1;
    lptr element[100]={NULL};
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
            l = l->next;
        }else{
            L = temp;
            l = L;
        }
    }
}

void swap(lptr &a, lptr &b)
{
    lptr t = a;
    a = b;
    b = t;
}

void Percolate_Down(struct Heap &H, int i)
{
    while(true)
    {
        if(2*i+1>H.size)
        break;
        if(2*i+2<=H.size)
        {
            if(H.element[i]->data>H.element[2*i+1]->data && H.element[i]->data>H.element[2*i+1]->data)
            {
                if(H.element[2*i+2]->data < H.element[2*i+1]->data){
                    swap(H.element[i], H.element[2*i+2]);
                    i = 2*i+2;
                }else{
                    swap(H.element[i], H.element[2*i+1]);
                    i = 2*i+1;
                }
            }else if(H.element[i]->data>H.element[2*i+1]->data){
                swap(H.element[i], H.element[2*i+1]);
                i = i*2+1;
            }else if(H.element[i]->data>H.element[2*i+2]->data){
                swap(H.element[i], H.element[2*i+2]);
                i = i*2 + 2;
            }else break;
        }else if(2*i+1<=H.size){
            swap(H.element[i],H.element[2*i+1]);
            break;
        }
    }
}

void Percolate_Up(struct Heap &H, int i)
{
    if(i<=0||H.element[i]->data>H.element[(i-1)/2]->data)
    return;
    swap(H.element[i], H.element[(i-1)/2]);
    Percolate_Up(H, (i-1)/2);
}

void Heapify(struct Heap &H)
{
    if(H.size == -1)return;
    cout<<H.element[0]->data<<" ";
    if(H.element[0]->next == NULL){
        if(H.size == 0)return;
        H.element[0] = H.element[H.size--];
        Percolate_Down(H, 0);
    }else{
        H.element[0] = H.element[0]->next;
        Percolate_Down(H, 0);
    }
    Heapify(H);
}

int main()
{
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    lptr L[n]={NULL};
    for(int i=0; i<n; i++)
        Construct(L[i]);
    Heap H;
    for(int i=0; i<n; i++){
        H.element[++H.size] = L[i];
        Percolate_Up(H, H.size);
    }
    Heapify(H);
}