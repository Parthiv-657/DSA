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
void Djikstra(int **G, int v, int **DJ, int start, int end, int &count, int k){
    if(start == 0)return;
    if (count == k) return;
    if(start == end){
        cout<<start<<" ";
        while(DJ[start-1][2] != 0){
            cout<<DJ[start - 1][2]<<" ";
            start = DJ[start - 1][2];
        }
        cout<<endl;
        count++;
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
    while(count!=k){
        int min=100,start1 = 0;int min2 = 100;int start2 = 0;
        for(int i=0; i<v; i++){
            if(DJ[i][0] == 1)continue;
            if(i+1 == start)continue;
            if(DJ[i][1] < min){
                min2 = min;
                start2 = start1;
                min = DJ[i][1];
                start1 = i+1;
            }else if(DJ[i][1] < min2){
                min2 = DJ[i][1];
                start2 = i+1;
            }
        } 
        Djikstra(G, v, DJ, start1, end, count, k);
    }  
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
    int v,e,k;
    cin>>v>>e>>k;
    int **G = new int*[v+1];int **DJ = new int*[v];
    for(int i=1; i<=v; i++){
        G[i] = new int[v+1];
        DJ[i-1] = new int[3];
    }
    for(int i=1; i<=v; i++){
        DJ[i-1][0] = 0;
        DJ[i-1][1] = INT8_MAX;
        DJ[i-1][2] = 0;
        for(int j=1; j<=v; j++){
            G[i][j] = 0;
        }
    }
    int ind[v+1]={0};int outd[v+1]={0};
    int V[v+1]={0};
    a = 1;
    b = 6;
    int count = 0;
    Djikstra(G, v, DJ, a, b, count, k);
}