#include<iostream>
using namespace std;

void swap(int &a, int &b){
    int c= a;
    a = b;
    b = c;
}

struct MinHeap{
    int top = -1;
    int elements[100];

    bool isEmpty(){
        if(top == -1)
            return true;
        return false;
    }

    void Perculate_Down(int t)
    {
        int l = 2*t+1;
        int r = 2*r+2;
        int h = t;
        if(elements[l]<elements[h])
            h = l;
        if(elements[h]<elements[r])
            h = r;
        if(h!=t){
            swap(elements[t],elements[h]);
            Perculate_Down(h);
        }
    }

    void Perculate_Up(int t)
    {
        int h = t+1/2;
        if(elements[h]>elements[t]){
            swap(elements[t],elements[h]);
            Perculate_Down(h);
        }
    }

    void Add_Element(int a)
    {
        elements[top++] = a;
        Perculate_Up(top);
    }
    
    int Delete()
    {
        int i = elements[0];
        elements[0] = elements[top--];
        Perculate_Down(0);
    }
    void Print(){
        for(int i=0; i<=top; i++){
            cout<<elements[i]<<" ";
        }
    }
};



int main()
{
    int n;
    cin>>n;
    int **arr;
    *arr = new int[n];
    for(int i = 0; i<n ; i++){
        arr[i] = new int[n];
    }
    for(int i =0; i<n*n; i++){
        cin>>arr[i/n][i%n];
    }
    MinHeap H[n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++){
            H[i].Add_Element(arr[i][j]);
        }
    }
}