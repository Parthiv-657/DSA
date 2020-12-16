#include<iostream>
using namespace std;
int number(string input1){
    int n=0;
    n = input1.size();
    int arr[n];
    for(int i=0; i<n; i++){
        arr[i] = input1[i]-'0';
    }
    bool flag[n]={0};
    while(true){
        bool flag1 = 0;
        for(int i=0; i<n-1; i++){
            if(flag[i] == 1)
                continue;
            int j=i+1;
            while(flag[j] == 1)
                j++;
            if(j == n)
                break;
            if(arr[i] + arr[j] == 17){
                flag[i] = flag[j] = 1;
                flag1 = 1;
            }
        }
        if(flag1 == 0)
        {
            int count = 0;
            for(int i=0; i<n; i++){
                if(flag[i] == 0)
                    count++;
            }
            return count;
        }
    }
}
int main(){
    string s;
    cin>>s;
    cout<<number(s)<<endl;
}