#include<bits/stdc++.h>
using namespace std;

struct bknode {
    string s;
    bknode *ptr[10] = {NULL};
    int diff[10] = {-1};
};
int min(int a,int b,int c, int &d)
{
   if (a < b && a < c)
   {
      d = 1;
      return a;
   }
   else if (b < a && b < c)
   {
      d = 2;
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
    char a[m+1],b[n+1];
    for(int i=0; i<=m; i++){
        a[i] = '#';
    }
    for(int i=0; i<=n; i++){
        b[i] = '#';
    }
    int i = m,j = n;
    while(i==0 && j==0){

    }
    return arr[m][n];
}

void Construct(bknode* &B,string s)
{
    if (B==NULL)
    {
        B=new(bknode);
        B->s=s;
        return;
    }
    else
    {
        int k= Diff_str(B->s,s, B->s.size(), s.size());
        Construct(B->ptr[k],s);
    }
}
void Suggest(bknode* T, string s, int n){
    if(T == NULL)return;
    int d = T->s.size();
    int diffe = Diff_str(s, T->s, s.size(), d);
    if(diffe <= n)
        cout<<diffe<<" "<<T->s<<endl;
    for(int i=0; i<10; i++){
        int m = n-diffe;if(m<0)m = 0-m;
        if( n-diffe <= T->diff[i] <= n+diffe)
            Suggest(T->ptr[i], s, n);
    }
}
void Print_Helper(bknode* T){
    if(T == NULL)return;
    cout<<T->s<<" ";
    for(int i=0; i<10; i++)
        Print_Helper(T->ptr[i]);
}
void Print(bknode* T){
    if(T == NULL)return;
    cout<<T->s<<endl;
    for(int i=0; i<10; i++){
        if(T->ptr[i] != NULL){
            cout<<i<<" ";
            Print_Helper(T->ptr[i]);
            cout<<endl;
        }
    }
    for(int i=0; i<10; i++){
        Print(T->ptr[i]);
    }
}

int main(){
    string s1; string s2;
    cin>>s1>>s2;
    cout<<Diff_str(s1, s2);
    Print(T);
}