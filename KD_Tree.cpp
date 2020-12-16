#include<iostream>
using namespace std;

struct htnode{
    struct htnode* lc;
    int data[100];
    struct htnode* rc;
};

typedef struct htnode* htptr;

void Construct(htptr &HT, int d, int a[])
{
    HT = new(htnode);
    HT->lc = HT->rc = NULL; 
    for(int i =0; i<d; i++)
        HT->data[i] = a[i];
    cin>>a[0];
    if(a[0])
    {
        for(int i=1; i<d; i++)
            cin>>a[i];
        Construct(HT->lc, d,a);
    }
    cin>>a[0];
    if(a[0]);
    {
        for(int i=1; i<d; i++)
            cin>>a[i];
        Construct(HT->lc, d, a);
    }
}

int main()
{
    int d;
    cin>>d;
    int a[d];
    for(int i=0 ;i<d; i++)
    cin>>a[i];
    kdptr KT = NULL;
    Construct(HT, d, a);
}