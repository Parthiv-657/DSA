#include<bits/stdc++.h>
using namespace std;
const int d = 3;

struct bnode{
    int count = 0;
    int key[d-1];
    bnode* cptr[d]={NULL};
};

void Print(bnode*);

struct OBV{
    int key[d];
    bnode* cptr[d+1] = {NULL};
};

void Add_Helper(OBV* t, bnode* &T1, stack<bnode*>s, bool flag){
    OBV* temp = new(OBV);
    bnode* left = new(bnode);
    bnode* right = new(bnode);
    for(int i=0; i<d/2 ; i++){
        left->count++;
        left->key[i] = t->key[i];
        if(i!=d/2)
        left->cptr[i] = t->cptr[i];
    }
    left->cptr[d/2] = t->cptr[d/2];
    int j=0;
    if(flag == 0){
    for(int i=(d/2); i<d; i++,j++){
        right->count++;
        right->key[j] = t->key[i];
        if(i!=d-1)
        right->cptr[j] = t->cptr[i+1];
    }}
    else{
    for(int i=(d/2)+1; i<d; i++,j++){
        right->count++;
        right->key[j] = t->key[i];
        right->cptr[j] = t->cptr[i];
    }}
    right->cptr[j] = t->cptr[d];
    if(s.empty()){
       // cout<<"hilulu"<<endl;
        bnode* T = new(bnode);
        T->count = 1;
        T->key[0] = t->key[d/2];
        T->cptr[0] = left;
        T->cptr[1] = right;
        T1 = T;
        /*cout<<T1->key[0]<<endl;
        cout<<T1->cptr[0]->key[0]<<" "<<T1->cptr[1]->key[0]<<endl;*/
    }else{
        int pi = t->key[d/2];
        //cout<<pi<<endl;
        bnode* parent = s.top();s.pop();
        if(parent->count == d-1){
            //cout<<"Im here"<<endl;
            int j=0;bool flag = 0;
            for(int i=0; i<d; i++){
                if(pi>parent->key[i] && i<parent->count){
                    temp->key[i] = parent->key[j];
                    temp->cptr[i] = parent->cptr[j];
                    j++;
                }
                else{
                    //cout<<i<<" "<<j<<endl;
                    if(flag == 0){
                        temp->key[i] = pi;
                        temp->cptr[i] = left;
                        temp->cptr[i+1] = right;
                        flag = 1;
                    }else{

                        temp->key[i] = parent->key[j];
                        temp->cptr[i+1] = parent->cptr[j+1];
                        /*if(j==1){
                            cout<<"haha"<<endl;
                            Print(parent->cptr[j+1]);cout<<endl;
                        }*/
                        j++;
                    }
                }
            }
            Add_Helper(temp, T1, s,1);
            return;
        }else{
            //cout<<"Im here"<<endl;
            int pi = t->key[d/2];
            int i=0;
            while(i<parent->count && parent->key[i] < pi){
                i++;
            }
            for(int j=parent->count ; j>i; j--){
                parent->key[j] = parent->key[j-1];
            }
            for(int j=parent->count+1 ; j>i+1; j--){
                parent->cptr[j] = parent->cptr[j-1];
            }
            parent->key[i] = pi;
            parent->cptr[i] = left;
            parent->cptr[i+1] = right; 
            parent->count++;
        }
    }
}

void Insert_Sorter(bnode* curr, int _a){
    if(curr->count!=d-1){
        if(_a>curr->key[curr->count-1]){
            curr->key[curr->count] = _a;
            return;
        }
        for(int i=0; i<curr->count; i++){
            if(_a<curr->key[i]){
                for(int j=i+1; j<=curr->count; j++){
                    curr->key[j] = curr->key[j-1];
                }
                curr->key[i] = _a;
                return;
            }
        }
    }
}

void Add_(bnode* &T, int _a){
    if(T == NULL){
        T = new(bnode);
        T->count = 1;
        T->key[0] = _a;
        return;
    }
    bnode* temp = T;
    bnode* t = NULL;
    stack<bnode*>s;
    while(temp != NULL){
        if(t)
        s.push(t);
        t = temp;
        if(_a>temp->key[temp->count-1]){
            temp = temp->cptr[temp->count];
            continue;
        }
        for(int i=0; i<temp->count; i++){
            if(_a<temp->key[i]){
                temp = temp->cptr[i];
                break;
            }
        }
    }
    bnode* curr = t;
    if(curr->count<d-1){
        Insert_Sorter(curr, _a);
        curr->count++;
        return;
    }
    OBV* extra  = new(OBV);bool flag = 0;
    for(int i=0; i<curr->count;i++){
        if(_a>curr->key[i]){
            extra->key[i] = curr->key[i];
        }else{
            if(flag == 0){
                extra->key[i] = _a;
                i--;
                flag = 1;
            }else{
                extra->key[i+1] = curr->key[i];
            }
        }
    }
    if(flag == 0){
        extra->key[d-1] = _a;
    }
    /*cout<<"Here it starts"<<endl;
    for(int i=0; i<d; i++){
        cout<<extra->key[i]<<" ";
    }cout<<"Here it ends"<<endl;*/
    Add_Helper(extra, T, s, 0);
}

void Print(bnode* MT){
    if(MT == NULL)return;
    //cout<<MT->count<<endl;
    for(int i=0; i<=MT->count; i++){
        Print(MT->cptr[i]);
        if(i<MT->count){
            cout<<MT->key[i]<<" ";
        }
    }
}

void Level_Printer(queue<bnode*>q){
    if(q.empty())return;
    queue<bnode* >q1;
    while(!q.empty()){
        bnode* temp = q.front();q.pop();
        for(int i=0; i<temp->count; i++){
            cout<<temp->key[i]<<" ";
            if(temp->cptr[i])q1.push(temp->cptr[i]);
        }
        if(temp->cptr[temp->count])q1.push(temp->cptr[temp->count]);
    }
    cout<<endl;
    Level_Printer(q1);
}

int main(){
    //freopen64("input.txt","r",stdin);
    bnode* T = NULL;
    int n;
    for(int i=0; i<10; i++){
        cin>>n;
        Add_(T, n);
        queue<bnode*>q;q.push(T);
    }
    queue<bnode*>q;q.push(T);
    Level_Printer(q);
}
//4 7 22 21 35 12 23 39 16 32 29 46 28 43 64 9 49 53 40 42 24 60 