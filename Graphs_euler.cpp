#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* next = NULL;
};

typedef struct node* lptr;

void Add(lptr L, lptr L1){
    lptr temp = L->next;
    L->next = L1;
    if(temp == NULL)return;
    while(L1->next != NULL){
        cout<<L->data<<endl;
        L1 = L1->next;
    }
    L1->next = temp;
    return;
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

 
void PrintLL(lptr L){
    if(L == NULL)return;
    cout<<L->data<<" ";
    PrintLL(L->next);
}
int main(){
    int v=11;
    vector<vector<int>>G;
    G = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0},//
        {0,0,0,1,1,0,0,0,0,0,0,0,0},//1
        {0,0,0,1,0,0,0,0,1,0,0,0,0},//2
        {0,1,1,0,1,0,1,1,0,1,0,0,0},//3
        {0,1,0,1,0,1,0,1,0,0,1,1,0},//4
        {0,0,0,0,1,0,0,0,0,0,1,0,0},//5
        {0,0,0,1,0,0,0,0,0,1,0,0,0},//6
        {0,0,0,1,1,0,0,0,0,1,1,0,0},//7
        {0,0,1,0,0,0,0,0,0,1,0,0,0},//8
        {0,0,0,1,0,0,1,1,1,0,1,0,1},//9
        {0,0,0,0,1,1,0,1,0,1,0,1,1},//10
        {0,0,0,0,1,0,0,0,0,0,1,0,0},//11
        {0,0,0,0,0,0,0,0,0,1,1,0,0} //12
    };
    int outd[v+1]={0};
    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            if(G[i][j] != 0){
                outd[i]++;
            }
        }
    }
    lptr L = new(node);
    L->data = 1;
    Euler(G, v, outd, L);
    PrintLL(L);
}