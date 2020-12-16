    if(present.empty() && Q.empty()){
        for(int i=0; i<ST.size(); i++){
            for(int j=0; j<ST[i].size(); j++){
                Print(ST[i][j]);cout<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    if(present.empty()){
        idx.pop();
        queue<int>temp = Q.front();Q.pop();
        Func(G, v, ST, temp, Q, idx, haha, 0);
    }else{
        int t1 = present.front();present.pop();
        int h = idx.front()-present.size();
        for(int i=six; i< h; i++){
            vector<int>temp = ST[i];
            ST[i].push_back(t1);
            Func(G, v, ST, present, Q, idx, haha, i+1);
            ST[i] = temp;            
        }
    }