#include<iostream>
using namespace std;

typedef struct multinode {
    int tag;
    union{
        char cdata;
        multinode * dlink;
    } data;
    multinode* next;
} *mlptr ;



void Insert(mlptr &ML , string s , int l , int h )
{
    mlptr ml = ML ;
    while(ml!=NULL && ml->next != NULL)
        ml = ml->next;
    for( int i = l+1 ; i < h ; i++ )
    {
        mlptr temp = new(multinode) ;
        temp->next = NULL;
        if(s[i]=='{')
        {
            temp->tag = 1 ;
            temp->data.dlink = NULL ;
            ml->next = temp;
            ml = ml->next;
            int low = l , high = l ;
            while(s[h+1]!='}')
            h++;
            Insert(ml->data.dlink , s , l, h );
        }
        else{
            if(ML==NULL)
            {
                temp->tag = 0;
                temp->data.cdata = s[i];
                ML = temp ;
                ml = ML;
            }else{
                temp->tag = 0;
                temp->data.cdata = s[i];
                ml->next = temp ;
                ml = ml->next;
            }
        }
    }
}

void Print( mlptr ML )
{
    cout<<"{";
    while(ML != NULL)
    {
        if(ML->tag == 0)
        {
            cout<<ML->data.cdata;
            ML = ML->next;
        }
        else{
            Print(ML->data.dlink);
        }
    }
    cout<<"}";
}

int main()
{
    string s;
    cin>>s;
    mlptr ML = NULL;
    Insert(ML,s,0,s.size()-1) ;
    Print(ML) ;
}