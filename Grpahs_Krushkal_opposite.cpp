#include<bits/stdc++.h>
using namespace std;
struct sde{
    int s;
    int d;
    int e;
};
void swap(sde &a, sde&b){
    sde c = a;
    a = b;
    b = c;
}
struct hnode{
    sde data[100];
    int size=-1;
    void Percolate_UP(int n){
        if(n == 0)return;
        int up = (n-1)/2;
        if(data[up].e < data[n].e){
            swap(data[up], data[n]);
            Percolate_UP(up);
        }else return;
    }
    void Percolate_DOWN(int n){
        if(2*n + 1 > size)return;
        int ch = n;int a = 2*n+1;int b = 2*n+2;
        if(data[ch].e < data[a].e)
            ch = a;
        if(b<=size && data[ch].e < data[b].e)
            ch = b;
        if(ch!=n){
            swap(data[n], data[ch]);
            Percolate_DOWN(ch);
        }
    }
    sde Delete(){
        sde temp = data[0];
        data[0] = data[size--];
        Percolate_DOWN(0);
        return temp;
    }
    void Add(sde n){
        data[++size] = n;
        Percolate_UP(size);
    }
};
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

bool Djikstra(vector<vector <int>>G, int v, int **DJ, int start, int end){
    if(start == end){
        return true;
    }
    if(DJ[start][0] == 1)return false;
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
            start1 = i;
        }
    } 
    if(start1)
    return Djikstra(G, v, DJ, start1, end);
    return false;
}

bool Path_Finder(vector<vector <int>>G, int v, int start, int end){
    int **DJ;
    DJ = new int*[v+1];
    for(int i=1; i<=v; i++)
        DJ[i] = new int[3];
    for(int i=1; i<=v; i++){
        DJ[i][0] = 0;
        DJ[i][1] = INT8_MAX;
        DJ[i][2] = -1;
    }
    return Djikstra(G, v, DJ, start, end);
}
void Graph_to_Heap(vector<vector<int>>G, hnode &H, int v){
    for(int i=1; i<=v; i++){
        for(int j=i+1; j<=v; j++){
            if(G[i][j] != 0){
                sde temp;
                temp.s = i;
                temp.d = j;
                temp.e = G[i][j];
                H.Add(temp);
            }
        }
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
bool isReachable(vector<vector<int>>adj, int V,  int s, int d) 
{ 
    if (s == d) 
      return true; 
    bool *visited = new bool[V+1]; 
    for (int i = 1; i <= V; i++) 
        visited[i] = false; 
    list<int> queue; 
    visited[s] = true; 
    queue.push_back(s); 
    while (!queue.empty()) 
    { 
        s = queue.front(); 
        queue.pop_front(); 
        for (int i=1; i<=V; i++) 
        {
            if(adj[s][i] == 0)continue;
            if (i == d) 
                return true; 
            if (!visited[i]) 
            { 
                visited[i] = true; 
                queue.push_back(i); 
            } 
        } 
    }
    return false; 
} 
void Opposite(vector<vector<int>>&G, int v, hnode &H, int edge){
    while(edge != v-1){
        sde temp = H.Delete();int a = G[temp.s][temp.d];
        G[temp.s][temp.d] = 0;
        G[temp.d][temp.s] = 0;
        if(isReachable(G, v, temp.s, temp.d)){
            edge--;
        }else{
            G[temp.s][temp.d] = a;
            G[temp.d][temp.s] = a;
        }
    }
}
int main(){
    int v=7;
    vector<vector<int>>G;
    G = {
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0}
    };
    int i1[]={1,1,1,2,2,3,3,4,4,4,5,6};
    int i2[]={2,3,4,4,5,4,6,5,6,7,7,7};
    int i3[]={2,4,1,3,10,2,5,7,8,4,6,1};
    for(int i=0;i<12;i++)
    {
        G[i1[i]][i2[i]]=G[i2[i]][i1[i]]=i3[i];
    }
    int edge = 0;
    for(int i=1; i<=v; i++){
        for(int j=i+1; j<=v; j++){
            if(G[i][j] != 0){
                edge++;
            }
        }
    }
    hnode H;
    Graph_to_Heap(G, H, v);int count =0;
    Opposite(G, v, H, edge);
    for(int i=1; i<=v; i++){
        for(int j=i+1; j<=v; j++){
            if(G[i][j] != 0){
                cout<<i<<" "<<j<<endl;
            }
        }
    }
}