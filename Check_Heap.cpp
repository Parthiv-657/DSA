#include<iostream>
using namespace std;

bool Check_Heap(int a[],int i,int size)
{
    if(2*i+1>=size)
    return true;
    if(a[i]<a[2*i+1] && a[i]<a[2*i+2])
    {
        return true *Check_Heap(a,2*i+1,size)*Check_Heap(a,2*i+2,size);
    }else return false;
}

int main()
{
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    int a[n];
    int size = 1;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];++size;
    }
    cout<<Check_Heap(a,0,size)<<endl;
}