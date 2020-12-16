#include<bits/stdc++.h>
using namespace std;

struct gtnode{
    gtnode* ns = NULL;
    char data;
    int at = -1;
    int dt = -1;
    bool flag = 0;
    gtnode* fs = NULL;
};

void Construct(struct gtnode* &GT, string s, int &i){
    if(GT == NULL){
        GT = new(gtnode);
        GT->data = s[i];
    }
    i++;
    if(s[i]!='.')
        Construct(GT->fs, s, i);
    i++;
    if(s[i]!='.')
        Construct(GT->ns, s, i);
}

void AT_DT(gtnode* GT, int &i){
    if(GT == NULL)return;
    GT->at = i;
    if(GT->fs){
        i++;
        AT_DT(GT->fs, i);
    }
    if(GT->fs == NULL)
    i++;
    GT->dt = i;
    if(GT->ns){
        AT_DT(GT->ns, i);
    }
}

void Level_Print(queue<gtnode*>q){
    if(q.size() == 0)return;
    int n = q.size();
    for(int i=0; i<n; i++){
        gtnode* temp = q.front();
        q.pop();
        while(temp!=NULL){
            q.push(temp->fs);
            cout<<temp->at<<" "<<temp->dt<<" ";
            temp = temp->ns;
        }
    }
    cout<<endl;
    Level_Print(q);
}

int Min_Time(gtnode* GT){
    if(GT->dt-GT->at<4){
        if(GT->dt - GT->at == 3)return 2;
        if(GT->dt - GT->at == 1)return 0;
    }
    gtnode* temp = GT->fs;
    int a[10]={0};int i=0;
    while(temp!=NULL){
        a[i] = Min_Time(temp);
        i++;
        temp = temp->ns;
    }
    sort(a,a+i);
    int time =0;
    /*for(int j=i-1; j>=0; j--){
        cout<<a[j]<<" ";
    }
    cout<<endl;*/
    int k=1;
    for(int j=i-1; j>=0; j--){
        if(time<a[j]+k){
            time = a[j]+k;
        }
        k++;
    }
    return time;
}

int main()
{
    freopen("input.txt","r",stdin);
    string s;
    cin>>s;
    int i=0;
    gtnode* GT = NULL;
    Construct(GT, s, i);
    i=0;
    AT_DT(GT, i);
    queue<gtnode*>q;
    q.push(GT);
    //Level_Print(q);
    cout<<Min_Time(GT)<<endl;
}