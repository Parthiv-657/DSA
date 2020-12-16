#include<bits/stdc++.h>
using namespace std;
int v = 6;
void Tarzan_DFS(vector<vector<int>>G, int *num, int *low, bool *stack1, stack<int>&s, int u, int &pre,  int *cnds, int &i1){
    num[u] = pre;
    s.push(u);
    stack1[u] = 1;
    low[u] = pre;
    pre++;
    for(int i=1; i<=v; i++){
        if(G[u][i] != 0){
            if(num[i] == -1){
                Tarzan_DFS(G, num, low, stack1, s, i, pre, cnds, i1);
                low[u]  = min(low[u], low[i]); 
            }else if(stack1[i] == 1){
                low[u] = min(low[u], num[i]);
            }
        }
    }
    if (low[u] == num[u]) 
    { 
        while (s.top() != u) 
        { 
            cnds[s.top()] = i1;
            stack1[s.top()] = 0;
            s.pop();
        } 
        cnds[s.top()] = i1;
        stack1[s.top()] = 0;
        s.pop(); 
        i1++;
    }
}
void Print_Condense(vector<vector<int>>G, vector<vector<int>>G1, int *cnds){
    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            if(G[i][j]!=0 && cnds[i] != cnds[j]){
                G1[cnds[i]][cnds[j]]++;
            }
        }
    }
    for(int i=1; i<G1.size(); i++){
        for(int j=1; j<G1[i].size(); j++){
            for(int k=0; k<G1[i][j]; k++){
                cout<<i<<" "<<j<<endl;
            }
        }
    }
}
void Tarzan(vector<vector<int>>G){
    int *num = new int[v+1];
    int *low = new int[v+1];
    bool *stack1 = new bool[v+1];
    bool *vistd = new bool[v+1];
    int *cnds = new int[v+1];
    for(int i=1; i<=v; i++){
        stack1[i] = 0;
        num[i] = low[i] = -1;
        vistd[i] = 0;
        cnds[i] = 0;
    }
    int i1=1;
    stack<int>s;
    int pre = 1;
    for(int u=1; u<=v; u++)
        if(num[u] == -1)
            Tarzan_DFS(G, num, low, stack1, s, u, pre, cnds, i1);
    /*for(int i=1; i<=v; i++){
        cout<<parent[i]<<" ";
    }cout<<endl;*/
    i1--;
    vector<vector<int>>G1;
    for(int i=0; i<=i1; i++){
        vector<int>temp(i1+1, 0);
        G1.push_back(temp);
    }
    Print_Condense(G, G1, cnds);
}
int main(){
    vector<vector<int>>G;
    G = {
        {0,0,0,0,0,0,0},
        {0,0,1,1,0,1,0},
        {0,0,0,1,0,1,0},
        {0,0,0,0,1,0,0},
        {0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,1,0}
    };
    Tarzan(G);
    /*cout<<"-------------------n---------------"<<endl;
    for(int i=1; i<=v; i++)
        cout<<num[i]<<" "<<low[i]<<endl;*/
}