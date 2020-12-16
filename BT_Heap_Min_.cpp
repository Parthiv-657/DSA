#include<iostream>
using namespace std;

struct Heap
{
    int elements[100];
    int size = -1;
};

void swap(int &a, int &b)
{
    cout<<a<<" "<<b<<endl;
    int t = a;
    a = b;
    b = t;
}

void Add_Heap(struct Heap &H, int a)
{
    H.size++;
    cout<<H.size<<endl;
    H.elements[H.size] = a;
    int i = H.size;
    while(i!=0 && H.elements[i]<H.elements[(i-1)/2])
    {
        swap(H.elements[i],H.elements[(i-1)/2]);
        i = (i-1)/2;
    }
}

int Deleat_Heap(struct Heap &H)
{
    int i = H.size;
    H.size -= 1;
    int r = H.elements[0];
    H.elements[0] = H.elements[i];
    i =0;
    while(2*i+2<=H.size || 2*i+1<=H.size)
    {
        if(H.elements[i]>H.elements[2*i+1] && H.elements[i]>H.elements[2*i+2])
        {
            if(H.elements[2*i+1]>H.elements[2*i+2])
            {
                swap(H.elements[2*i+2],H.elements[i]);
                i = 2*i +2;
            }else{
                swap(H.elements[2*i+1],H.elements[i]);
                i = 2*i+1;
            }
        }
        else if(H.elements[i]>H.elements[2*i+1])
        {
            swap(H.elements[i], H.elements[2*i +1]);
            i = 2*i + 1;
        }else if(H.elements[i]>H.elements[2*i+2])
        {
            swap(H.elements[2*i+2],H.elements[i]);
            i = 2*i +2;
        }else break;
    }
    return r;
}

int main()
{
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    cin>>a[i];
    struct Heap H;
    for(int i =0; i<n ;i++)
    {
        Add_Heap(H, a[i]);
    }
    cout<<"//////////////////////"<<endl;
    for(int i=0; i<n; i++)
    {
        a[i] = Deleat_Heap(H);
    }
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
}