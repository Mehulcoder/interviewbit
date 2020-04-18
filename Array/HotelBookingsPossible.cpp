bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int k) {
    vector<pair<int,int> >v;
    int n=arrive.size();
    for(int i=0;i<n;i++){
        v.push_back(make_pair(arrive[i],1));
        v.push_back(make_pair(depart[i],-1));
    }
    sort(v.begin(),v.end());
    int count=0;
    for(int i=0;i<2*n;i++){
        count+=v[i].second;
        if(count>k)
         return false;
    }
    return true;
}