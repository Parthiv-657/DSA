#include<bits/stdc++.h>
using namespace std;
int d;
struct bnode{
    int count = 0;
    int * key;
    bnode** cptr;
};
void allocate_(bnode* &T, int x){
    T = new(bnode);
    T->key = new int[x];
    T->cptr = new bnode*[x+1];
    for(int i=0; i<=x; i++)
        T->cptr[i] = NULL;
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
    queue<bnode*>q1;
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
void Insert_Sorter(bnode* curr, int _a, bnode* l, bnode* r){
    if(curr->count!=d-1){
        if(_a>curr->key[curr->count-1]){
            curr->key[curr->count++] = _a;
            curr->cptr[curr->count-1] = l;
            curr->cptr[curr->count] = r;
            return;
        }
        for(int i=0; i<curr->count; i++){
            if(_a<curr->key[i]){
                for(int j=i+1; j<=curr->count; j++){
                    curr->key[j] = curr->key[j-1];
                }
                curr->cptr[i] = l;
                curr->key[i] = _a;
                curr->cptr[i+1] = r;
                curr->count++;
                return;
            }
        }
    }
}
void Creatre_OBV(bnode* T, int a, bnode* left, bnode* right, bnode* &ex){
    bnode* extra;allocate_(extra, d+1);bool flag = 0;
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
        extra->cptr[d-1] = left;
        extra->cptr[d] = right;
    }
    /*cout<<"Ikada";
    for(int i=0; i<d; i++){
        cout<<extra->key[i]<<" ";
    }
    cout<<endl;*/
    ex = extra;
    return;
}
void collect_cptr(bnode* parent, queue<bnode*>&q){
    for(int i=0; i<parent->count+1; i++){
        bnode* temp = parent->cptr[i];
        for(int j=0; j<=temp->count; j++){
            q.push(temp->cptr[i]);
        }
    }
    return;
}
void num_collector(bnode* parent, int *a, int &size){
    for(int i=0; i<parent->count+1; i++){
        bnode* temp = parent->cptr[i];
        for(int j=0; j<temp->count; j++){
            a[size++] = temp->key[j];
        }
        if(i!=parent->count){
            a[size++] = parent->key[i];
        }
    }
    /*cout<<"ikada"<<endl;
    for(int i=0; i<size; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;*/
    return;
}
void Distributor(bnode* parent){
    //cout<<parent->key[0]<<endl;
    queue<bnode*>q;
    int a[100],size=0;
    collect_cptr(parent, q);
    num_collector(parent, a, size);
    int sum=0,divi,rem;
    for(int i=0; i<parent->count+1; i++)
        sum+=parent->cptr[i]->count;
    //cout<<sum<<" "<<parent->count<<endl;
    divi = sum/(parent->count+1);
    rem = sum%(parent->count+1);bool flag =0;
    for(int i=0; i<parent->count+1; i++){
        if(rem!=0){
        if(parent->cptr[i]->count > divi+1)
            flag = 1;}
        else{
            if(parent->cptr[i]->count != divi)
            flag = 1;
        }
    }
    if(flag == 0)return;
    //cout<<"haha"<<endl;
    for(int i=0; i<parent->count+1; i++){
        parent->cptr[i]->count = divi;
        if(rem){
            parent->cptr[i]->count++;
            rem--;
        }
    }
    int idx = 0;
    for(int i=0; i<=parent->count; i++){
        bnode* temp = parent->cptr[i];
        for(int j=0; j<=temp->count; j++){
            temp->cptr[j] = q.front();q.pop();
            if(j!=temp->count)
                temp->key[j] = a[idx++];
        }
        if(i!=parent->count)
            parent->key[i] = a[idx++];
    }
}
void split(bnode* t, bnode* &left, bnode* &right){
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
}
void Add_Helper(bnode* t, bnode* curr, bnode* &T1, stack<bnode*>s, stack<int>s2){
    //cout<<"haha"<<endl;
    bnode* temp ; allocate_(temp, d+1);
    bnode* left ; allocate_(left, d);
    bnode* right ; allocate_(right, d);
    split(t, left, right);
    //Print(left);cout<<endl;
    //Print(right);cout<<endl;
    if(s.empty()){
        bnode* T;allocate_(T, d);
        T->count = 1;
        T->key[0] = t->key[d/2];
        T->cptr[0] = left;
        T->cptr[1] = right;
        T1 = T;
        
    }else{
        bnode* parent = s.top();s.pop();
        if(parent->count == d-1){
            //cout<<"dontprint";
            Creatre_OBV(parent, t->key[d/2], left, right, temp);
            Distributor(temp);
            s2.pop();
            Add_Helper(temp, parent, T1, s, s2);
            return;
        }else{
            //cout<<"Im here"<<endl;
            int pi = t->key[d/2];
            Insert_Sorter(parent, pi, left, right);
            Distributor(parent);
        }
    }
}
bnode* Search(bnode* T, int a, stack<bnode*>&s, stack <int>&s2){
    if(T == NULL){
        bnode* temp = s.top();
        s.pop();
        s2.pop();
        return temp;
    }else{
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
    }return NULL;}
}
void Add_(bnode* &T, int _a){
    if(T == NULL){
        allocate_(T, d);
        T->count = 1;
        T->key[0] = _a;
        return;
    }
    stack<bnode*>s1;stack<int>s2;
    bnode* curr = Search(T, _a, s1, s2);
    if(curr->count<d-1){
        Insert_Sorter(curr, _a, NULL, NULL);
        return;
    }
    bnode* extra;
    Creatre_OBV(curr, _a, NULL, NULL, extra);
    Add_Helper(extra, curr, T, s1, s2);
}
int main(){
    cin>>d;
    bnode* T = NULL;
    int n;
    while(cin>>n, n!=0){
        Add_(T, n);
    }
    queue<bnode*>q;q.push(T);
    Level_Printer(q);
    cin>>n;
    cout<<"after adding "<<n<<endl;
    Add_(T, n);
    Level_Printer(q);
}
//4 7 22 21 35 12 23 39 16 32 29 46 28 43 64 9 49 53 40 42 24 60 
//5 2 4 12 14 16 6 21 9 30 0 18
//5 2 4 12 14 9 6 18 21 25 15 30 8 16 36 0 32
/*
        if(n == 36 || n==32){
        cout<<n<<endl;}
        Add_(T, n);
        if(n == 38||n == 32){
        queue<bnode*>q;q.push(T);
        Level_Printer(q);
        cout<<endl;}
*/