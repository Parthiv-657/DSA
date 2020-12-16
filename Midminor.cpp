#include<bits/stdc++.h>
using namespace std;

int min(int a,int b,int c)
{
   if (a < b && a < c)
   {
      return a;
   }
   else if (b < a && b < c)
   {
     return b;
   }
   else
   {
    return c;
   }
}
int Diff_str(string s1, string s2, int m, int n){
    int arr[m+1][n+1]={0};
    for(int i=0; i<=m; i++) 
        arr[i][0] = i;
    for(int i=0; i<=n; i++) 
        arr[0][i] = i;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[i-1] == s2[j-1]){
                arr[i][j] = arr[i-1][j-1];
            }else{
                arr[i][j] = 1 + min(arr[i-1][j-1], arr[i-1][j], arr[i][j-1]);
            }
        }
    }
    int ab[max(m,n)];char a[max(m,n)],b[max(n,m)];
    int size = max(m,n);
    for(int i=0; i<size; i++){
        a[i] = '#';
        b[i] = '#';
    }
    int i = m,j = n;
    int alias = size-1;
    while(i!=0 || j!=0){
        if(i==0){
            ab[alias] = 1;
            b[alias] = s2[j-1];
            j--;alias--;
        }else if(j == 0){
            ab[alias] = 2;
            a[alias] = s1[i-1];
            i--;alias--;
        }else{
            if(arr[i][j] == 1+arr[i-1][j]){
                ab[alias] = 2;
                a[alias] = s1[i-1];
                i--;alias--;}
            else if(arr[i][j] == 1+arr[i][j-1]){
                ab[alias] = 1;
                a[alias] = s2[j-1];
                j--;alias--;
            }
            else if(arr[i][j] == arr[i-1][j-1]){
                ab[alias] = 4;
                a[alias] = s1[i-1];
                b[alias] = s2[j-1];
                i--;j--;alias--;
            }else if(arr[i][j] == 1+arr[i-1][j-1]){
                ab[alias] = 3;
                a[alias] = s1[i-1];
                b[alias] = s2[j-1];
                i--;j--;alias--;
            }
        }
    }
    for(int i=0; i<size; i++){
        switch(ab[i]){
            case 1:
                cout<<"A"<<" ";
                break;
            case 2:
                cout<<"D"<<" ";
                break;
            case 3:
                cout<<"C"<<" ";
                break;
            case 4:
                cout<<"N"<<" ";
                break;
        }
        if(a[i] != '#')cout<<a[i]<<" ";
        if(b[i] != '#')cout<<b[i]<<" ";
        cout<<endl;
    }
    return arr[m][n];
}

int main(){
    freopen64("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--){
    string s1; string s2;
    cin>>s1>>s2;
    cout<<s1<<" "<<s2<<endl;
        cout<<Diff_str(s1, s2, s1.size(), s2.size())<<endl;}
}
