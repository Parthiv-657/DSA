#include<iostream>
using namespace std;

int partition(int l,int h,int a[])
{
    int pivot=a[h];
    int i=(l-1);
    for (int j=l;j<=h-1;j++)
    {
        if (a[j] < pivot)
        {  
            i++;
            int c=a[j];
            a[j]=a[i];
            a[i]=c;
        }
    }
    int c=a[h];
    a[h]=a[i+1];
    a[i+1]=c;
    return (i+1);
}
void quicksort(int l,int h,int a[],struct stack *s){
    
    int pi=partition(l,h,a);
    if(l<pi-1){
        push(s,pi-1);
        push(s,l);
    }if(pi+1<h)
    {
        push(s,h);
        push(s,pi+1);
    }
    while(s->top!=-1){
        int low =pop(s);
        int high =pop(s);
        int par = partition(low,high,a);
        if(low <par-1){
        push(s,par-1);
        push(s,low);
        }if(pi+1<high)
        {
            push(s,high);
            push(s,par+1);
        }
    }

}

int main(){
    int a[]={1,6,4,6,8,3,2,5,6};
    struct stack *s=new(stack);
    quicksort(0,8,a,s);
}


