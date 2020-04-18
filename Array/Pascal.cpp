vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> ans;
    if(A==0){
        return ans;
    }
    // vector<int> temp(1,1);
    // ans.push_back(temp);
    // if(A==1){
    //     return ans;
    // }
    int start = 1;
    for(int i = 0;i<A;i++){
        vector<int> row;
        for(int j = 0;j<start;j++){
            if(j==start-1 || j==0){
                row.push_back(1);
                continue;
            }
            row.push_back(ans[start-2][j]+ans[start-2][j-1]);
        }
        ans.push_back(row);
        start++;
    }
    
    return ans;
}
