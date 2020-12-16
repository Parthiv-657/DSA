#include<bits/stdc++.h>
using namespace std;

void DFS(int **G, int *V, int v, int idx, int *a, int i, int *V1){
    if(V[idx] == 1){
        if(idx == a[0]){
            bool flag = 0;
            for(int temp = 0; temp<i; temp++){
                if(V1[a[temp]] == 1)
                    flag = 1;
            }
            if(flag == 1)return;
            for(int temp = 0; temp<i; temp++){
                cout<<a[temp]<<" ";
            }
            cout<<idx<<endl;
        }return;
    }
    V[idx] = 1;
    a[i] = idx;
    for(int temp=0; temp<=v; temp++){
        if(G[idx][temp] != 0){
            DFS(G, V, v, temp, a, i+1, V1);
        }
    }
    V[idx] = 0;
}

int main(){
    freopen("input.txt", "r", stdin);
    int v,e;
    cin>>v>>e;
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
    int a,b,c;
    for(int i=0; i<e; i++){
        cin>>a>>b;
        ind[b]++;
        outd[a]++;  
        G[a][b] = 1;
    }
    int V1[v+1];
    int arrr[100];
    for(int i=1; i<=v;i++){
        int V[v+1]={0};
        DFS(G, V, v, i, arrr, 0, V1);
        V1[i] = 1;
    }
}
