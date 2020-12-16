#include<bits/stdc++.h>
using namespace std;
void Print(int i){
    if(i == 7){
        cout<<"H";
    }else if(i == 8){
        cout<<"I";
    }else if(i == 9){
        cout<<"X";
    }else if(i == 10){
        cout<<"Y";
    }else{
        cout<<char(i+64);
    }
}
int Traverse(vector<vector<int>> G, int v, int i, int *outd, int leng){
    if(outd[i] == 0)return leng;
    for(int idx=1; idx<=v; idx++){
        if(G[i][idx] != 0){
            return Traverse(G, v, idx, outd, leng+1);
        }
    }
    return 0;
}
int Highest_path_vertex(vector<vector<int>>G, int v, int *ind, int *outd, int &count){
    queue<int>q;
    for(int i=1; i<=v; i++){
        if(ind[i] == 0){
            q.push(i);
        }
    }
    int vertex=0; int length = 0;
    while(!q.empty()){
        int temp = q.front();q.pop();
        int tlen = Traverse(G, v, temp, outd, 0);
        if(tlen > length){
            length  = tlen;
            vertex = temp;
        }
    }
    count = length;
    return vertex;
}
void Collector(vector<vector<int>>G, int v, int *ind, queue<int>temp, queue<queue<int>>&Q, queue<int>&idx, int *haha){
    if(temp.empty())return;
    int iemp = temp.front();temp.pop();
    queue<int>temp1;
    while(ind[iemp] == 1 || ind[iemp] == 0){
        for(int i=1; i<=v; i++){
            if(G[iemp][i] != 0){
                temp1.push(iemp);
                iemp = i;
                break;
            }
        }
    }
    idx.push(haha[iemp]);
    Q.push(temp1);
    Collector(G, v, ind, temp, Q, idx, haha);
}
void Func(vector<vector<int>>&G, int v, vector<vector<int>> &ST, queue<int>present, queue<queue<int>>Q, queue<int>idx, int *haha, int six){
    if(present.empty() && Q.empty()){
        for(int i=0; i<ST.size(); i++){
            for(int j=0; j<ST[i].size(); j++){
                Print(ST[i][j]);cout<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    if(present.empty()){
        idx.pop();
        queue<int>temp = Q.front();Q.pop();
        Func(G, v, ST, temp, Q, idx, haha, 0);
    }else{
        int t1 = present.front();present.pop();
        int h = idx.front()-present.size();
        for(int i=six; i< h; i++){
            vector<int>temp = ST[i];
            ST[i].push_back(t1);
            Func(G, v, ST, present, Q, idx, haha, i+1);
            ST[i] = temp;            
        }
    }
}
int main(){
    int v=10;
    vector<vector<int>>G;
    G = {
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,1},
        {0,0,0,0,1,0,0,0,0,0,0}
    };
    int ind[v+1]={0},outd[v+1]={0};
    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            if(G[i][j]!=0){
                ind[j]++;
                outd[i]++;
            }
        }
    }
    int len=0;
    int h = Highest_path_vertex(G, v, ind, outd, len);int h1 = h;
    vector<vector<int>>TS;
    int haha[100];
    for(int i=0; i<=len; i++){
        vector<int>temp;
        temp.push_back(h);
        haha[h] = i;
        TS.push_back(temp);
        for(int j=1; j<=v; j++){
            if(G[h][j]!=0){
                h = j;
                break;
            }
        }
    }
    h = h1;
    queue<int>temp;
    for(int i=1; i<=v; i++){
        if(i!=h && ind[i] == 0){
            temp.push(i);
        }
    }
    queue<queue<int>> Q;queue<int>idx;
    Collector(G, v, ind, temp, Q, idx, haha);
    queue<int>present = Q.front(); Q.pop();
    Func(G, v, TS, present, Q, idx, haha, 0);
}