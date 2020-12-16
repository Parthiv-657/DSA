#include<iostream>
using namespace std;

struct btnode
{
    struct btnode* lc;
    int data;
    int h;
    int v;
    struct btnode* rc;
};

typedef struct btnode* btptr;

void Construct(btptr &BT, int a,int h, int v, int &hmin, int &hmax, int &vmax)
{
    BT = new(btnode);
    BT->data = a;
    BT->h = h;
    BT->v = v;
    if(h<hmin)hmin = h;
    if(h>hmax)hmax = h;
    if(v>vmax) vmax = v;
    BT->lc = BT->rc = NULL;
    cin>>a;
    if(a)Construct(BT->lc,a,h-1,v+1, hmin, hmax, vmax);
    cin>>a;
    if(a)Construct(BT->rc,a,h+1,v+1, hmin, hmax, vmax);
}

void HV_Sum(btptr BT, int hsum[], int vsum[], int h)
{
    if(BT == NULL)
    return;
    hsum[BT->h+h]+= BT->data;
    vsum[BT->v]+=BT->data;
    HV_Sum(BT->lc, hsum, vsum, h);
    HV_Sum(BT->rc, hsum, vsum, h);
}

int main()
{
    btptr BT = NULL;
    int a;
    cin>>a;
    int hmin=100,hmax = 0, vmax =0;
    Construct(BT,a,0,0,hmin,hmax,vmax);
    int hsum[hmax-hmin+1]={0};
    int vsum[vmax+1]={0};
    HV_Sum(BT, hsum, vsum, -hmin);
    for(int i=0; i<hmax-hmin+1; i++)
    cout<<hsum[i]<<" ";
    cout<<endl;
    for(int i=0; i<= vmax; i++)
    cout<<vsum[i]<<" ";
    cout<<endl;
}