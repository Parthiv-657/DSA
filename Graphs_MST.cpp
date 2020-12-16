#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector <int>>G, int *V, int v, int idx){
    if(V[idx] == 1)return;
    V[idx] = 1;
    for(int i=1; i<=v; i++){
        if(G[idx][i] == 1)
        {
            cout<<idx<<" "<<i<<endl;
            DFS(G, V, v, i);
        }
    }
}

void BFS(vector<vector <int>>G, int *V, int v, queue<int>q){
    if(q.empty())return;
    while(!q.empty()){
        int temp = q.front();q.pop();
        for(int i=1; i<=v; i++){
            if(G[temp][i]!=0 && V[i]==0){
                cout<<temp<<" "<<i<<endl;
                V[i] = 1;
                q.push(i);
            }
        }
    }
}

void Djikstra(vector<vector <int>>G, int v, vector<vector<int>> &DJ, int start){
    if(DJ[start][0] == 1)return;
    DJ[start][0] = 1;
    for(int i=1; i<=v; i++){
        if(i == start)continue;
        if(DJ[i][0] == 0 && G[start][i] != 0){
            int a = G[start][i];
            if(DJ[i][1] > a){
                DJ[i][1] = a;
                DJ[i][2] = start;
            }
        }
    }
    int min=INT8_MAX,start1 = 0;
    for(int i=1; i<=v; i++){
        if(DJ[i][0] == 0){
        if(DJ[i][1] < min){
            min = DJ[i][1];
            start1 = i;
        }}
    }
    if(start1)
    Djikstra(G, v, DJ, start1);
}

void Print(int **G, int v){
    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Post_Order(vector<vector<int>>G, int idx, int *p_order, int &t, int *V, int v){
    if(V[idx] == 1)return;
    V[idx] = 1;
    for(int i=1;i<=v; i++){
        if(G[idx][i] !=0 ){
            if(V[i] == 0){
                Post_Order(G, i, p_order, t, V, v);
            }
        }
    }
    p_order[idx] = t;t++;
}

int main(){
    int v=7;
    vector<vector<int>>G;
    G = {
        {0,0,0,0,0,0,0,0},
        {0,0,2,4,1,0,0,0},
        {0,2,0,0,3,10,0,0},
        {0,4,0,0,2,0,5,0},
        {0,1,2,2,0,7,8,4},
        {0,0,10,0,7,0,0,6},
        {0,0,0,5,8,0,0,1},
        {0,0,0,0,4,6,1,0}
    };
    int p_order[11];
    int V[11]={0};
    int t=1;
    vector<vector<int>>MST;
    MST = {
        {0,0,0},
        {0,INT8_MAX,-1},
        {0,INT8_MAX,-1},
        {0,INT8_MAX,-1},
        {0,INT8_MAX,-1},
        {0,INT8_MAX,-1},
        {0,INT8_MAX,-1},
        {0,INT8_MAX,-1}
    };
    int sum=0;
    Djikstra(G, v, MST, 1);
    for(int i=1; i<=v; i++){
        if(MST[i][1]!=INT8_MAX)
        sum+=MST[i][1];
        for(int j=1; j<=v; j++){
            if(MST[j][2] == i){
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    cout<<sum<<endl;
}
