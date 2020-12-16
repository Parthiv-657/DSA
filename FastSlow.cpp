#include<iostream>
using namespace std;

struct node{
    int data;
    struct node * next;
};

typedef struct node* lptr;

void Insert(lptr &L)
{
    int n;lptr l;
    while(cin>>n,n!=-1)
    {
        lptr temp = new(node);
        temp->data = n;
        temp->next = NULL;
        if(L== NULL)
        {
        	L = temp;
        	l = temp;
        }else{
        	l->next = temp;
        	l = l->next;
        }
    }
}

void FastSlow(lptr L)
{
	lptr fast = L;
	lptr slow = L;
	while(fast->next!=NULL && fast->next->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	cout<<slow->data<<" "<<fast->data<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE 
  
    // For getting input from input.txt file 
    freopen("input.txt", "r", stdin); 
  
    // Printing the Output to output.txt file 
    freopen("output.txt", "w", stdout); 
#endif 
    return 0; 
}