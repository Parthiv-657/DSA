#include<iostream>
using namespace std;

struct queue{
    int size;
    int f;
    int r;
    int elements[100];
    bool isQEmpty()
    {
            if(f == -1&&r == -1)
            return true;
        return false;
    }
    
    bool isQFull()
    {
        if((r+1)%size == f)
            return true;
        return false;
    }
    
    void EnQueue(int a){
        if(!isQFull())
        {
            if(f == -1)
            {
                f = 0;
                r = 0;
                elements[r] = a;
            }else{
                r = (r+1)%size;
                elements[r] = a;
            }
        }else{
            cout<<"FULL"<<endl;
            //return -100;
        }
    }
    
    int DeQueue()
    {
        if(!isQEmpty())
        {
            if(f == r)
            {
                int t= elements[f];
                f = -1;
                r = -1;
                return t;
            }else{
                int t = elements[f];
                f = (f+1)%size;
                return t;
            }
        }
    }
    };

