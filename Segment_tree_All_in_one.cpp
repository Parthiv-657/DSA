#include<iostream>
using namespace std;

struct node{
    int min;
    int max;
    int sum;
    int c[10]={-1};
};

int min(int x, int y)
{
    if(x>y)return y;
    return x;
}

int max(int x, int y)
{
    if(x<y)return y;
    return x;
}

node Build(node *s, int *a, int i, int l, int h)
{
    //cout<<i<<" "<<l<<" "<<h<<endl;
    if(l==h){
        s[i].min = a[l];
        s[i].max = a[l];
        s[i].sum = a[l];
        return s[i];
    }
    int m = (l+h)/2;
    node temp1 = Build(s,a, 2*i+1, l, m);
    node temp2 = Build(s, a, 2*i+2, m+1, h);
    s[i].min = min(temp1.min, temp2.min);
    s[i].max = max(temp2.max, temp2.max);
    s[i].sum = temp1.sum + temp2.sum;
    return s[i];
}

node Return(node *s, int l, int h, int sl, int sh, int i){
    if(sl>sh || l>h)
    {
        node haha;
        haha.min =100;
        haha.max = -100;
        haha.sum =0;
        return haha;
    }
    //cout<<sl<<" "<<sh<<";"<<l<<" "<<h<<endl;
    if(sl == l && sh == h){
        //cout<<"my i is "<<i<<endl;
        return s[i];
    }
    int m =(l+h)/2;
    if(m<sl)
        return Return(s, m+1, h, sl, sh, 2*i+2);
    else if(m>sh)
        return Return(s, l, m, sl, sh, 2*i+1);
    else{
        node temp1 = Return(s, l, m, sl, m, 2*i+1);
        node temp2 = Return(s, m+1, h, m+1, sh, 2*i+2);
        //cout<<temp1.max<<" "<<temp2.max<<endl;
        node haha;
        haha.min = min(temp1.min, temp2.min);
        haha.max = max(temp1.max, temp2.max);
        haha.sum = temp1.sum + temp2.sum;
        //cout<<s[i].max<<"      jfsadklfjgfkld"<<l<<h<<endl;
        return haha;
    }
}

void Change(node *s, int i){
    if(i==0){
        node temp1 = s[2];
        node temp2 = s[1];
        s[i].min = min(temp1.min, temp2.min);
        s[i].max = max(temp2.max, temp2.max);
        s[i].sum = temp1.sum + temp2.sum;
        return;
    }
    int j = (i-1)/2;
    node temp1 = s[2*j+2];
    node temp2 = s[2*j+1];
    s[j].min = min(temp1.min, temp2.min);
    s[j].max = max(temp1.max, temp2.max);
    s[j].sum = temp1.sum + temp2.sum;
    Change(s, j); 
}

void Changer(node *s, int l, int h, int i, int c, int idx){
    if(l == h && l == idx){
        s[i].min = s[i].max = s[i].sum = c;
        Change(s, i);
        return;
    }
    int m = (l+h)/2;
    if(m<idx)
        Changer(s, m+1, h, 2*i+2, c, idx);
    else
        Changer(s, l, m, 2*i+1, c, idx);
}

int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;struct node s[100];
    cin>>n;int a[n];
    for(int i=0;i<n; i++)
    cin>>a[i];
    Build(s, a, 0, 0, n-1);
    int q;
    cin>>q;
    //cout<<"          "<<s[2].max<<endl;
    while(q--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            cout<<Return(s,0, n-1, b, c, 0).min<<endl;
        }else if(a==2){
            cout<<Return(s,0, n-1, b, c, 0).max<<endl;
        }else if(a==3){
            cout<<Return(s,0, n-1, b, c, 0).sum<<endl;
        }else if(a==4){
            cout<<float(float(Return(s,0, n-1, b, c, 0).sum)/float(c-b+1))<<endl;
        }else{
            Changer(s, 0, n-1, 0, c, b);
        }
    }
}