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

void Creatre_OBV(bnode* T, int a, bnode* left, bnode* right, OBV* &ex){
    OBV* extra = new(OBV);bool flag = 0;
    for(int i=0; i<T->count; i++){
        if(T->key[i]<a){
            extra->key[i] = T->key[i];
            extra->cptr[i] = T->cptr[i];
        }else{
            if(flag == 0){
                extra->key[i] = a;
                extra->cptr[i] = left;
                extra->cptr[i+1] = right;
                flag = 1;
                i--;
            }else{
                extra->key[i+1] = T->key[i];
                extra->cptr[i+2] = T->cptr[i+1];
            }
        }
    }
    if(flag == 0){
        extra->key[d-1] = a;
        extra->cptr[d] = T->cptr[T->count];
    }
    /*cout<<"Ikada";
    for(int i=0; i<d; i++){
        cout<<extra->key[i]<<" ";
    }
    cout<<endl;*/
    ex = extra;
    return;
}

bool Shift_Helper(OBV* t, bnode* curr, bnode* parent, int i){
    if(i!=0 && parent->cptr[i-1]->count<d-1){
        bnode* temp = parent->cptr[i-1];
        temp->key[temp->count++] = parent->key[i-1];
        parent->key[i-1] = t->key[0];
        for(int i=0; i<curr->count; i++){
            curr->key[i] = t->key[i+1];
        }
        return true;
    }else if(i!=parent->count && parent->cptr[i+1]->count<d-1){
        bnode* temp = parent->cptr[i+1];
        for(int i=temp->count; i>=1; i--){
            temp->key[i] = temp->key[i-1];
        }
        temp->count++;
        temp->key[0] = parent->key[i];
        parent->key[i] = t->key[d-1];
        for(int i=0; i<curr->count; i++){
            curr->key[i] = t->key[i];
        }
        return true;
    }
    return false;
}

void Add_Helper(OBV* t, bnode* curr, bnode* &T1, stack<bnode*>s, stack<int>s2){
    if(!s.empty() && Shift_Helper(t, curr,s.top(), s2.top()))return;
    OBV* temp = new(OBV);
    bnode* left = new(bnode);
    bnode* right = new(bnode);
    for(int i=0; i<d/2 ; i++){
        left->count++;
        left->key[i] = t->key[i];
        left->cptr[i] = t->cptr[i];
    }
    left->cptr[d/2] = t->cptr[d/2];
    int j=0;
    for(int i=(d/2)+1; i<d; i++,j++){
        right->count++;
        right->key[j] = t->key[i];
        right->cptr[j] = t->cptr[i];
    }
    right->cptr[j] = t->cptr[d];
    if(s.empty()){
        bnode* T = new(bnode);
        T->count = 1;
        T->key[0] = t->key[d/2];
        T->cptr[0] = left;
        T->cptr[1] = right;
        T1 = T;
    }else{
        bnode* parent = s.top();s.pop();
        if(parent->count == d-1){
            Creatre_OBV(parent, t->key[d/2], left, right, temp);
            s2.pop();
            Add_Helper(temp, parent, T1, s, s2);
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

bnode* Search(bnode* T, int a, stack<bnode*>&s, stack <int>&s2){
    if(T == NULL){
        bnode* temp = s.top();
        s.pop();
        s2.pop();
        return temp;
    }
    s.push(T);
    if(a>T->key[T->count-1]){
        s2.push(T->count);
        return Search(T->cptr[T->count], a, s, s2);
    }
    for(int i=0; i<T->count; i++){
        if(a<T->key[i]){
            s2.push(i);
            return Search(T->cptr[i], a, s, s2);
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
    stack<bnode*>s1;
    stack<int>s2;
    bnode* curr = Search(T, _a, s1, s2);
    if(curr->count<d-1){
        Insert_Sorter(curr, _a);
        curr->count++;
        return;
    }
    OBV* extra;
    Creatre_OBV(curr, _a, NULL, NULL, extra);
    Add_Helper(extra, curr, T, s1, s2);
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
    return;
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
    freopen64("input.txt","r",stdin);
    bnode* T = NULL;
    int n;
    while(cin>>n, n!=0){
        Add_(T, n);
    }
    queue<bnode*>q;q.push(T);
    Level_Printer(q);
}
//4 7 22 21 35 12 23 39 16 32 29 46 28 43 64 9 49 53 40 42 24 60 