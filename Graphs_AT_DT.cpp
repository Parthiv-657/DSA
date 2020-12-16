#include<bits/stdc++.h>
using namespace std;

void DFS(int **G, int *V, int v, int idx){
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

void BFS(int **G, int *V, int v, queue<int>q){
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

void Djikstra(int **G, int v, int **DJ, int start, int end){
    if(start == end){
        cout<<start<<" ";
        while(DJ[start-1][2] != 0){
            cout<<DJ[start - 1][2]<<" ";
            start = DJ[start - 1][2];
        }
        return;
    }
    DJ[start-1][0] = 1;
    for(int i=1; i<=v; i++){
        if(i == start)continue;
        if(G[start][i] != 0){
            int a = G[start][i];
            if(DJ[start - 1][1] != INT8_MAX)
                a += DJ[start - 1][1];
            if(DJ[i-1][1] > a){
                DJ[i-1][1] = a;
                DJ[i-1][2] = start;
            }
        }
    }
    int min=100,start1 = 0;
    for(int i=0; i<v; i++){
        if(DJ[i][0] == 1)continue;
        if(i+1 == start)continue;
        if(DJ[i][1] < min){
            min = DJ[i][1];
            start1 = i+1;
        }
    } 
    Djikstra(G, v, DJ, start1, end);
}

void Print(int **G, int v){
    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
}

void AT_DT(int **G, int **AD, int V[], int v, int &t, int i){
    if(V[i] == 1)return;;
    V[i] = 1;
    AD[i][0] = t;
    t++;
    for(int idx = 0; idx<v; idx++){
        if(i == idx)continue;
        if(G[i][idx]!=0 && V[idx] == 0){
            AT_DT(G, AD, V, v, t, idx);
        }
    }
    AD[i][1] = t;
    t++;
}

int main(){
    freopen("input.txt", "r", stdin);
    int v,e;
    cin>>v>>e;
    int **G = new int*[v];int **AD = new int*[v];
    for(int i=0; i<v; i++){
        G[i] = new int[v];
        AD[i] = new int[2];
    }
    for(int i=0; i<v; i++){
        AD[i][1] = -1;
        AD[i][0] = -1;
        for(int j=1; j<=v; j++){
            G[i][j] = 0;
        }
    }
    int a,b,c;
    for(int i=0; i<e; i++){
        cin>>a>>b; 
        G[a][b] = 1;
    }
    int V[v]={0};
    int t=0;
    for(int i=0; i<v; i++){
        if(V[i] == 0){
            cout<<i<<endl;
            AT_DT(G, AD, V, v, t, i);
        }
    }
    for(int i=0; i<v; i++){
        cout<<i<<" "<<AD[i][0]<<" "<<AD[i][1]<<endl;
    }
}