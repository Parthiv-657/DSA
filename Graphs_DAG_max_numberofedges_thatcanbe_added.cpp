#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector <int>>G, int *V, int v, int idx){
    if(V[idx] == 1){return;}
    V[idx] = 1;
    cout<<idx<<" ";
    for(int i=1; i<=v; i++){
        if(G[idx][i] == 1)
        {
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

void Djikstra(vector<vector <int>>G, int v, int **DJ, int start, int end){
    if(start == end){
        cout<<start<<" ";
        while(DJ[start][2] != 0){
            cout<<DJ[start][2]<<" ";
            start = DJ[start][2];
        }
        return;
    }
    DJ[start][0] = 1;
    for(int i=1; i<=v; i++){
        if(i == start)continue;
        if(G[start][i] != 0){
            int a = G[start][i];
            if(DJ[start][1] != INT8_MAX)
                a += DJ[start][1];
            if(DJ[i][1] > a){
                DJ[i][1] = a;
                DJ[i][2] = start;
            }
        }
    }
    int min=100,start1 = 0;
    for(int i=1; i<=v; i++){
        if(DJ[i][0] == 1)continue;
        if(i+1 == start)continue;
        if(DJ[i][1] < min){
            min = DJ[i][1];
            start1 = i+1;
        }
    } 
    Djikstra(G, v, DJ, start1, end);
}

void Print(vector<vector<int>>G, int v){
    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
}

void post_Order(vector<vector<int>>G, int idx, int *p_order, int &t, int *V, int v){
    if(V[idx] == 1)return;
    V[idx] = 1;
    for(int i=1;i<=v; i++){
        if(G[idx][i] !=0 ){
            if(V[i] == 0){
                post_Order(G, i, p_order, t, V, v);
            }
        }
    }
    p_order[idx] = t;t++;
}

void Post_Order(vector<vector<int>>G, int v, int * p_order){
    int t=1, V[v+1]={0};
    for(int i=1; i<=v; i++){
        if(V[i] == 0)
            post_Order(G, i, p_order, t, V, v);
    }
}

void Transpose(vector<vector<int>>&G, int v){
    for(int i=1;i<=v; i++){
        for(int j=i+1; j<=v; j++){
            G[i][j] = G[i][j] + G[j][i];
            G[j][i] = G[i][j] - G[j][i];
            G[i][j] = G[i][j] - G[j][i];
        }
    }return;
}
void Max_Edges(vector<vector<int>> G, int v, int *outd, int *ind, queue<int>q, int left, int &count){
    if(q.empty())return;
    queue<int>q;
    int left = v;
    for(int i=1; i<=v; i++){
        if(ind[i] == 0){
            q.push(i);left--;}
    }
    int count=0;
    queue<int>q1;
    while(!q.empty()){
        int temp = q.front();q.pop();
        count += (left-outd[temp]);
        for(int i=1; i<=v; i++){
            if(G[temp][i]!=0){
                q1.push(i);
            }
        }
    }

}
int main(){
    int v=10;
    vector<vector<int>>G;
    G = {
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,0,1,0,0,0,0,0,0},
        {0,0,0,1,0,0,1,0,0,0,0},
        {0,1,0,0,1,1,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,0,1,0,0},
        {0,0,0,0,0,0,1,0,0,0,1},
        {0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,0,0,1,0}
    };
    int p_order[11];
    map<int, int>m;
    Post_Order(G, v, p_order);
    for(int i=1; i<=v; i++)
        m[p_order[i]] = i;
    Transpose(G, v);
    int V[v+1]={0};
    for(int i=v; i>=1; i--){
        if(V[m[i]] == 0){
            DFS(G, V, v, m[i]);
            cout<<endl;
        }
    }
}