#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
    int t= b;
    b = a;
    a = t;
}

struct Min_Heap{
    int size = -1;
    int element[100];

    void Percolate_Down(int i)
    {
        while(true)
        {
            if(2*i+1>size)
            break;
            if(2*i+2<=size)
            {
                if(element[i]>element[2*i+1] && element[i]>element[2*i+1])
                {
                    if(element[2*i+2] < element[2*i+1]){
                        swap(element[i], element[2*i+2]);
                        i = 2*i+2;
                    }else{
                        swap(element[i], element[2*i+1]);
                        i = 2*i+1;
                    }
                }else if(element[i]>element[2*i+1]){
                    swap(element[i], element[2*i+1]);
                    i = i*2+1;
                }else if(element[i]>element[2*i+2]){
                    swap(element[i], element[2*i+2]);
                    i = i*2 + 2;
                }else break;
            }else if(2*i+1<=size){
                swap(element[i],element[2*i+1]);
                break;
            }
        }
    }

    void Percolate_Up( int i)
    {
        if(i<=0||element[i]>element[(i-1)/2])
        return;
        swap(element[i], element[(i-1)/2]);
        Percolate_Up( (i-1)/2);
    }
};

struct Max_Heap{
    int size = -1;
    int element[100];

    void Percolate_Down(int i)
    {
        while(true)
        {
            if(2*i+1>size)
            break;
            if(2*i+2<=size)
            {
                if(element[i]<element[2*i+1] && element[i]<element[2*i+2])
                {
                    if(element[2*i+2] < element[2*i+1]){
                        swap(element[i], element[2*i+2]);
                        i = 2*i+2;
                    }else{
                        swap(element[i], element[2*i+1]);
                        i = 2*i+1;
                    }
                }else if(element[i] < element[2*i+1]){
                    swap(element[i], element[2*i+1]);
                    i = i*2+1;
                }else if(element[i] < element[2*i+2]){
                    swap(element[i], element[2*i+2]);
                    i = i*2 + 2;
                }else break;
            }else if(2*i+1<=size){
                swap(element[i],element[2*i+1]);
                break;
            }
        }
    }

    void Percolate_Up( int i)
    {
        if(i<=0||element[i] < element[(i-1)/2])
        return;
        swap(element[i], element[(i-1)/2]);
        Percolate_Up((i-1)/2);
    }
};

void Median(Max_Heap H1, Min_Heap H2)
{
    if(H1.size == H2.size){
        cout<<float( H1.element[0] + H2.element[0] )/2<<endl;
    }else{
        if(H1.size>H2.size){
            cout<<H1.element[0]<<endl;
        }else{
            cout<<H2.element[0]<<endl;
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    int n;
    Max_Heap H1;
    Min_Heap H2;
    cin>>n;
    H1.element[++H1.size] = n;
    cout<<n<<endl;
    cin>>n;
    if(n<H1.element[H1.size]){
        H2.element[++H2.size] = H1.element[H1.size];
        H1.element[H1.size] = n;
    }
    else 
    H2.element[++H2.size] = n;
    Median(H1, H2);
    while(cin>>n,n!=-1)
    {
        if(H1.size == H2.size)
        {
            int me = (H1.element[0]+ H2.element[0])/2;
            if(n<=me){
                H1.element[++H1.size] = n;
                H1.Percolate_Up(H1.size);
            }else{
                H2.element[++H2.size] = n;
                H2.Percolate_Up(H2.size);
            }
        }else if(H1.size>H2.size){
            if(n>H1.element[0]){
                H2.element[++H2.size] = n;
                H2.Percolate_Up(H2.size);
            }else{
                H2.element[++H2.size] = H1.element[0];
                H2.Percolate_Up(H2.size);
                H1.element[0] = n;
                H1.Percolate_Down(0);
            }
        }else{
            if(n<H2.element[0]){
                H1.element[++H1.size] = n;
                H1.Percolate_Up(H1.size);
            }else{
                H1.element[++H1.size] = H2.element[0];
                H1.Percolate_Up(H1.size);
                H2.element[0] = n;
                H2.Percolate_Down(0);
            }
        }
        Median(H1,H2);
    }
}