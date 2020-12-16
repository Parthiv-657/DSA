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
        if(data[up].e > data[n].e){
            swap(data[up], data[n]);
            Percolate_UP(up);
        }else return;
    }
    void Percolate_DOWN(int n){
        if(2*n + 1 > size)return;
        int ch = n;int a = 2*n+1;int b = 2*n+2;
        if(data[ch].e > data[a].e)
            ch = a;
        if(b<=size && data[ch].e > data[b].e)
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

void Print(vector<vector<int>>G, int v){
    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
}
int find(int a[], int i){
    if(a[i] == -1)return i;
    return a[i] = find(a, a[i]);
}
bool Union(int a[], int m, int n){
    int m1 = find(a, m);
    int n1 = find(a, n);
    if(m1!=n1){
        a[m1] = n1;
        return true;
    }
    return false;
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
void Krushkal(hnode &H, int *arr, int v, int &sum){
    int count =0;
    while(count!=v-1){
        sde temp = H.Delete();
        //cout<<temp.s<<" "<<temp.d<<" "<<temp.e<<endl;
        if(Union(arr, temp.s, temp.d)){
            cout<<temp.s<<" "<<temp.d<<endl;
            count++;
            sum+=temp.e;
        }
    }
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
    hnode H;
    Graph_to_Heap(G, H, v);
    int count = 0;
    /*while(H.size != -1){
        sde temp = H.Delete();
        cout<<temp.s<<" "<<temp.d<<" "<<temp.e<<endl;
        count++;
    }*/
    int arr[v+1]={-1};
    for(int i=1; i<=v; i++){
        arr[i] = -1;
    }int sum =0;
    Krushkal(H, arr, v, sum);
    cout<<sum<<endl;
}