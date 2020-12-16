#include<iostream>
using namespace std;
const int m =5;
struct mstnode{
    int count =0;
    int key[m];
    struct mstnode* cptr[m+1]={NULL};
};

void Construct(mstnode* MT, int n){
    if(MT == NULL){
        MT = new(mstnode);
        MT->count += 1;
        MT->key[0] = n;
        return;
    }
    if(n>MT->key[MT->count -1]){
        if(MT->count == m-1){
            Construct(MT->cptr[MT->count-1], n);
            return;
        }else{
            MT->count++;
            MT->key[MT->count -1 ] = n;
            return;
        }
    }
    for(int i=0; i<MT->count-1; i++){
        if(n<MT->key[i]){
            Construct(MT->cptr[i], n);
            return;
        }
    }
}

void Print(mstnode* MT){
    if(MT == NULL)return;
    for(int i=0; i<MT->count; i++){
        Print(MT->cptr[i]);
        if(i<MT->count-1){
            cout<<MT->key[i]<<" ";
            return;}
    }
}

int main(){

}