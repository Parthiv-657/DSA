#include<iostream>
using namespace std;

int main()
{
    string s;getline(cin,s);
    int sum=0;
    int j=0;
    while(s!=""){
        int a =0;
        for(int i=0; i<s.size(); i++){
            a = a*10;
            a+= s[i]-'0';
        }
        if(a<17&& a>0)
        sum+=200;
        else if(a>=17 && a<=40)
        sum+=400;
        else if(a>40&& a<120)
        sum+=300;
        else 
        j = 1;
        getline(cin,s);
    }
    if(j == 1)
        cout<<"INVALID INPUT"<<endl;
    else
    cout<<"Total Income "<<sum<<" INR"<<endl;
}