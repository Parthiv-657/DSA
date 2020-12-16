#include<bits/stdc++.h>
using namespace std;
int v = 9;
void Tarzan_DFS(vector<vector<int>>G, int *num, int *low, bool *vistd, int *parent, bool *tz, int u, int &pre){
    num[u] = pre;
    vistd[u] = 1;
    low[u] = pre;
    int ch = 0;
    pre++;
    for(int i=1; i<=v; i++){
        if(G[u][i] != 0){
            if(vistd[i] == 0){
                ch++;
                parent[i] = u;
                Tarzan_DFS(G, num, low, vistd, parent, tz, i, pre);
                low[u]  = min(low[u], low[i]); 
                if(parent[u] != -1 && num[u] <= low[i]){
                    tz[u] = 1;
                }
                if (low[i] > num[u]) 
                    cout << u <<" " << i << endl; 
            }else if(parent[u] != i){
                low[u] = min(low[u], num[i]);
            }
        }
    }
    if(parent[u] == -1 && ch>1){
        tz[u] = 1;
    }
}
void Tarzan(vector<vector<int>>G){
    int *num = new int[v+1];
    int *low = new int[v+1];
    int * parent = new int[v+1];
    bool *vistd = new bool[v+1];
    bool *tz = new bool[v+1];
    for(int i=1; i<=v; i++){
        parent[i] = -1;
        num[i] = low[i] = 0;
        vistd[i] = 0;
        tz[i] = 0;
    }
    int pre = 1;
    Tarzan_DFS(G, num, low, vistd, parent, tz, 1, pre);
    /*for(int i=1; i<=v; i++){
        cout<<parent[i]<<" ";
    }cout<<endl;*/
    for(int i=1; i<=v; i++){
        if(tz[i] == 1)
            cout<<i<<" ";
    }cout<<endl;
}
int main(){
    vector<vector<int>>G;
    G = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0,0,0,0},
        {0,1,0,1,0,0,0,0,0,0},
        {0,1,1,0,1,0,1,0,0,0},
        {0,0,0,1,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,0,1,0,0,0,1,0,1},
        {0,0,0,0,0,0,1,0,1,0},
        {0,0,0,0,0,0,0,1,0,1},
        {0,0,0,0,0,0,1,0,1,0}
    };
    Tarzan(G);
    /*cout<<"-------------------n---------------"<<endl;
    for(int i=1; i<=v; i++)
        cout<<num[i]<<" "<<low[i]<<endl;*/
}