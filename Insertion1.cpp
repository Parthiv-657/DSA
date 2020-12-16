#include<iostream>
using namespace std;

void Insertion(int a[], int n)
{
    int i,j;
    for(int i =1; i<n; i++)
    {
        for(int k=i-1; k>=0 ; k--)
        {
            if(a[k]>a[k+1])
            {
                int t = a[k];
                a[k] = a[k+1];
                a[k+1] = t;
            }
        }
    }
}

int main()
{
    int m,n;
    cin>>m>>n;
    int a[m][n];
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n ;j++)
        {
            int n;
            cin>>n;
            a[i][j] = n;
        }
    }
    for(int i=0; i<n; i++)
    {
        Insertion(a[i], n);
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<a[i][j]<<" ";
        }cout<<endl;
    }
}