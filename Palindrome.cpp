#include <bits/stdc++.h> 
using namespace std; 

int findMinOps(int arr[], int n, int b[]) 
{ 
	int ans = 0; 
	for (int i=0,j=n-1; i<=j;) 
	{ 
		if (arr[i] == arr[j]) 
		{ 
			i++; 
			j--; 
		} 
		else if (arr[i] > arr[j]) 
		{ 
			j--; 
			arr[j] += arr[j+1] ; 
            b[j+1]=1;
			ans++; 
		} 

		else
		{ 
			i++; 
			arr[i] += arr[i-1]; 
            b[i-1]=1;
			ans++; 
		} 
	} 

	return ans; 
} 
int main() 
{ 
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int b[n]={0};
    findMinOps(a,n,b);
    for(int i=0; i<n; i++){
        if(b[i]==0)
            cout<<a[i]<<" ";
    }
}