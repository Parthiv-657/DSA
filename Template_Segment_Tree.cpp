#include<iostream>
using namespace std;

int Sum_Construct(int *s, int *a, int i, int l, int h)
{
    if(l==h){
        s[i] = a[l];
        return s[i];
    }else{
        int m = (l+h)/2;
        s[i] = Sum_Construct(s,a,2*i+1,l,m)+Sum_Construct(s,a,2*i+2,m+1,h);
        return s[i];
    }
}

int Sum_of_Range(int *s,  int sl, int sh, int l, int h, int i){
    if(sl>sh)
    return 0;
    if(sh<l || sl>h)
        return 0;
    if(sl<=l && sh>=h)
        return s[i];
    else{
        int m = (l+h)/2;
        return Sum_of_Range(s, sl, m, l, m, 2*i+1) + Sum_of_Range(s, m+1, sh, m+1, h, 2*i+2);
    }
    
}

void Replacer(int *s, int i, int a, int l, int h){
    if(i==l && i==h){
        s[i]-=a;
        return;
    }
    s[i]-=a;
    int m = (l+h)/2;
    if(i>m)
    Replacer(s,i,a,m+1,h);
    else
    Replacer(s,i,a,l,m);
}

int min(int x, int y){
    if(x<y)
    return x;
    return y;
}

int max(int x, int y){
    if(x<y)
    return y;
    return x;
}

int Min_Constructor(int *s, int *a, int i, int l, int h)
{
    if(l ==h){
        s[i] = a[l];
        return s[i];
    }else{
        int m = (l+h)/2;
        s[i] = min(Min_Constructor(s,a,2*i+1,l,m),Min_Constructor(s,a,2*i+2,m+1,h));
        return s[i];
    }
}

int Max_Constructor(int *s, int *a, int i, int l, int h)
{
    if(l ==h){
        s[i] = a[l];
        return s[i];
    }else{
        int m = (l+h)/2;
        s[i] = max(Max_Constructor(s,a,2*i+1,l,m),Max_Constructor(s,a,2*i+2,m+1,h));
        return s[i];
    }
}

int Min_of_Range(int *s,  int sl, int sh, int l, int h, int i){
    if(sl>sh)
    return 100;
    if(sl==l && sh==h)
        return s[i];
    else{
        int m = (l+h)/2;
        if(m<sl){
            Min_of_Range(s, sl, sh, m+1, h, 2*i+2);
        }else if(m>sh){
            Min_of_Range(s, sl, sh, l, m, 2*i+1);
        }else{
            return min(Min_of_Range(s, sl, m, l,m, 2*i+1),Min_of_Range(s, m+1,sh, m+1, h, 2*i+2));
        }
    }
}

int Max_of_Range(int *s,  int sl, int sh, int l, int h, int i){
    if(sl>sh)
        return 0;
    if(sh<l || sl>h)
        return 0;
    if(sl<=l && sh>=h)
        return s[i];
    else{
        int m = (l+h)/2;
        return max(Sum_of_Range(s, sl, m, l, m, 2*i+1),Sum_of_Range(s, m+1, sh, m+1, h, 2*i+2));
    }
}

float Avg_Constructor(float *s, int *a, int i, int l, int h)
{
    if(l ==h){
        s[i] = float(a[l]);
        return s[i];
    }else{
        int m = (l+h)/2;
        s[i] = (Avg_Constructor(s,a,2*i+1,l,m)+Avg_Constructor(s,a,2*i+2,m+1,h))/float(h-l+1);
        return s[i]*float((h-l+1));
    }
}

float Avg_of_Range(float *s, int sl, int sh, int l, int h, int i){
    if(sl>sh)
    return 0;
    if(sl == l && sh == h)
        return s[i]*float(h-l+1);
    else{
        int m = (l+h)/2;
        if(m<sl){
            Avg_of_Range(s, sl, sh, m+1, h, 2*i+2);
        }else if(m>sh){
            Avg_of_Range(s, sl, sh, l, m, 2*i+1);
        }else{
            return Avg_of_Range(s, sl, m, l,m, 2*i+1)+Avg_of_Range(s, m+1,sh, m+1, h, 2*i+2);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    cin>>a[i];
    int s[10000]={0};
    Min_Constructor(s,a,0,0,n-1);
    for(int i=0; i<20; i++){
        cout<<s[i]<<" ";
    }
    cout<<Min_of_Range(s,1,5,0,5,0)<<endl;
}