#include<iostream>
using namespace std;

int main(){
        freopen("input.txt","r",stdin);
    int i,e;
    cin>>i>>e;
    float c1 =18,c2 = 12;
    float ci[i];
    float ce[e];
    for(int k=0; k<i; k++)
    cin>>ci[k];
    for(int k=0; k<e; k++)
    cin>>ce[k];
    float cost =0;
    for(int k=0; k<i; k++){
        cost += c1*ci[k];
    }
    for(int k=0; k<e; k++){
        cost += c2*ce[k];
    }
    cout<<cost<<endl;
}