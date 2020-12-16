#include<iostream>
using namespace std;
int main()
{
    int n,x=0;
    cin>>n;
    while(n!=1)
    {
        x++;
        if(n%2==0)
            n=n/2;
        else if(n%2==1)
            n++;
    }
    cout<<x;
}