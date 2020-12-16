#include<iostream>
using namespace std;

int min(int a, int b){
    if(a>b)
    return b;
    return a;
}

int Find(int s[], int i, int l, int h, int sl, int sh){
    if(l>h || sl>sh)
        return 100;
    if(l==sl && h == sh)
        return s[i];
    int m = (l+h)/2;
    if(m>sh)
        return Find(s, 2*i+1, l, m, sl, sh);
    else if(m<sl)
        return Find(s, 2*i+2, m+1, h, sl, sh);
    else{
        return min(Find(s, 2*i+1, l, m, sl, m), Find(s, 2*i+2, m+1, h, m+1, sh));
    }
}

int Construct(int s[], int a[], int l, int h, int i){
    if(l==h){
        s[i] = a[l];
        return s[i];
    }
    int m= (l+h)/2;
    s[i] = min(Construct(s, a, l, m, 2*i+1), Construct(s, a, m+1, h, 2*i+2));
    return s[i];
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    cin>>a[i];
    int s1[4*n]={100};
    Construct(s1, a, 0, n-1, 0);
    cin>>n;
    for(int i=0; i<n; i++)
    cin>>a[i];
    int s2[4*n]={100};
    Construct(s2, a, 0, n-1, 0);
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int min1 = Find(s1, 0, 0, n-1, i, j);
            int min2 = Find(s2, 0, 0, n-1, i, j);
            if(min1 == min2)
                cout<<i<<" "<<j<<endl;
        }
    }
}