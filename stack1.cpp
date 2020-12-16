#include<iostream>
using namespace std;
class Queue {
	private:
		int front;
		int rear;
		int count;
		int capacity;
		int a[10];
	public:
		Queue(){
			front = -1;
		    rear = -1;
		    count = 0;
		    capacity = 5;
		}
	    int size(){
	    	return count;
		}
		bool isFull(){
			if(count==capacity){
				return true;
			}
			else{
				return false;
			}
		}
		bool isEmpty(){
			if(count==0){
				return true;
			}
			else{
				return false;
			}
		}
		bool enqueue(int g){
			if(isFull()){
				return false;
			}
			if(isEmpty()){
				front = 0;
				rear = 0;
				a[rear] = g;
				count++;
				return true;
			}
			else{
				rear = (rear + 1)%capacity;
				a[rear] = g;
				count++;
				return true;
			}
		}
		int dequeue(){
			if(isEmpty()){
				return INT_MAX;
			}
			if(count==1){
				int y = a[front];
				front = -1;
				rear = -1;
				count--;
				return y;
			}
			else{
				int y = a[front];
				front = (front + 1)%capacity;
				count--;
				return y;
			}
		}
		int peek(){
			if(isEmpty()){
				return INT_MAX;
			}
			else{
				int z = a[front];
				return z;
			}
		}
		void print(){
			if(isEmpty()){
				cout<<"QUEUE IS EMPTY"<<endl;
			}
			else{
				int p = front;
				for(int i=front;i<front+count;i++){
					cout<<a[i]<<endl;
				}
			}
		}
		
};
int main(){
	Queue q1;
	Queue q2;
	int e=0,v,x;
	while( e < 8 )
	{   int h = 1;
		
		cout<<"PRESS 1 FOR PUSH 2 FOR POP 3 FOR DISPLAY 4 FOR ISEMPTY 5 FOR IS FULL 6 FOR SIZE 7 FOR PEEK AND 8 FOR EXIT "<<endl;
		cin>>e;
		switch( e ){
			case 1:
		    	cout<<"PUSH:";
	            cin>>v;
			    if(q1.isFull()){
				cout<<"PUSH UNSUCCESSFUL"<<endl;
		   	    }
		   	    else{
					q1.enqueue(v);
				}
		   	    break;
			case 2:
				v = q1.dequeue();
				if(v==INT_MAX){
					cout<<"POP UNSUCCESSUL"<<endl;
				}
				else{
					while(q1.size()>1){
						x=q1.dequeue();
		   	    		q2.enqueue(x);
					}
					cout<<q1.dequeue()<<endl;
					while(!q2.isEmpty()){
						x=q2.dequeue();
		   	    		q1.enqueue(x);
					}
				}
				break;
			case 3:
				for(int i=0;i<q1.size();i++){
					while(q1.size()!=1){
						x=q1.dequeue();
		   	    		q2.enqueue(x);
					}
					cout<<q1.peek()<<endl;
					while(!q2.isEmpty()){
						x=q2.dequeue();
		   	    		q1.enqueue(x);
					}
				}
				break;
			case 4:
				if(q1.isEmpty()){
					cout<<"STACK IS EMPTY"<<endl;
				}
				else{
					cout<<"STACK IS NOT EMPTY"<<endl;
				}
				break;
			case 5:
				if(q1.isFull()){
					cout<<"STACK IS FULL"<<endl;
				}
				else{
					cout<<"STACK IS NOT FULL"<<endl;
				}
				break;	
			case 6:
				cout<<"SIZE :"<<q1.size()<<endl;
				break;
			case 7:
				v = q1.peek();
				if(v!=INT_MAX){
					while(q1.size()!=1){
						x=q1.dequeue();
		   	    		q2.enqueue(x);
					}
					cout<<q1.peek()<<endl;
					x=q1.dequeue();
					q2.enqueue(x);
					while(!q2.isEmpty()){
						x=q2.dequeue();
		   	    		q1.enqueue(x);
					}
				}
				else{
					cout<<"PEEK UNSUCCESSFUL"<<endl;
				}
				break;
		}
	}
	return 0;
}
