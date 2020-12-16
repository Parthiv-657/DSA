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

void Topo(int **G, int v, int **DJ, int start){
    if(G[start][3] == 0)return;
    DJ[start][0] = 1;
    for(int i=0; i<v; i++){
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
        if(i == start)continue;
        if(DJ[i][1] < min){
            min = DJ[i][1];
            start1 = i+1;
        }
    } 
    Topo(G, v, DJ, start1);
}

void Print(int **G, int v){
    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    int v;
    cin>>v;
    int **G = new int*[v];int **DJ = new int*[v];
    for(int i=0; i<v; i++){
        G[i] = new int[v+1];
        DJ[i] = new int[4];
    }
    for(int i=0; i<v; i++){
        DJ[i][0] = 0;
        DJ[i][1] = INT8_MAX;
        DJ[i][2] = 0;
        for(int j=0; j<v; j++){
            G[i][j] = 0;
        }
    }
    int ind[v]={0};int outd[v]={0};
    int a,b,c;
    while(cin>>a,a!=-1){
        cin>>b;
        cin>>c;
        DJ[a][0]++; 
        DJ[a][3]++; 
        G[a][b] = c;
    }
    int V[v]={0};
    cin>>a>>b;
    Topo(G, v, DJ, a, b);
}