#include<bits/stdc++.h>
using namespace std;

string Min_String(string a, string b){
    string c;
    int arr[26]={0};
    for(int i=0; i<a.size(); i++){
        arr[int(a[i])-97]++;
        if(arr[int(a[i])-97]==1)
        c+=a[i];
    }
    for(int i=0; i<b.size(); i++){
        arr[int(b[i])-97]++;
        if(arr[int(b[i])-97]==1)
        c+=b[i];
    }
    return c;
}

string Distinct_Constructor(string *s, string a, int l, int h, int i){
    //cout<<l<<" "<<h<<endl;
    if(l == h){
        s[i]+=a[l];
        //cout<<s[i]<<endl;
        return s[i];
    }else{
        int m = (l+h)/2;
        s[i] = Min_String(Distinct_Constructor(s, a, l, m, 2*i+1), Distinct_Constructor(s, a, m+1, h, 2*i+2));
        return s[i];
    }
}

string Distinct_Range(string *s, int sl, int sh, int l, int h, int i)
{
    if(l>h || sl>sh)return "";
    //cout<<sl<<" "<<sh<<";"<<l<<" "<<h<<endl;
    //if(l==4 && h==6)
    //cout<<s[i]<<"       hehehe"<<endl;
    if(sl == l && sh == h){
        return s[i];
    }
    int m = (l+h)/2;
    if(m<sl){
        return Distinct_Range(s, sl, sh, m+1, h, 2*i+2);
    }else if(m>sh){
        return Distinct_Range(s, sl, sh, l, m, 2*i+1);
    }else{
        return Min_String(Distinct_Range(s, sl, m, l,m, 2*i+1),Distinct_Range(s, m+1,sh, m+1, h, 2*i+2));
    }
}

void Change(string *s, int i){
    if(i==0){
        s[i] = Min_String(s[2*i+1], s[2*i+1]);
        return;
    }
    int j = (i-1)/2;
    s[j] = Min_String(s[2*j+1], s[2*j+2]);
    Change(s, j);
}

void Changer(string *s, int l, int h, int i, int c, char c1)
{
    if(l>h||(l==h && l!=c))
    return;
    if(l == c && h == c){
        s[i] = "";
        s[i]+=c1;
        //cout<<s[i]<<"  print"<<endl;
        Change(s, i);return;
    }else{
        int m = (l+h)/2;
        if(m>=c){
            Changer(s, l, m, 2*i+1, c, c1);
        }else{
            Changer(s, m+1, h, 2*i+2, c, c1);
        }
    }
}


int main()
{
    string s1;
    cin>>s1;
    int n = s1.size();
    string s[4*n]={""} ;
    Distinct_Constructor(s, s1, 0, s1.size()-1, 0);
    int q;
    cin>>q;
    while(q--){
        int a;
        cin>>a;
        if(a==1){
            int b;char c;
            cin>>b>>c;
            Changer(s, 0, s1.size()-1, 0, b-1,c);
        }else{
            int b,c;
            cin>>b>>c;
            cout<<Distinct_Range(s, b-1,c-1, 0, s1.size()-1, 0).size()<<endl;
        }
    }
}