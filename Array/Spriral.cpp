vector<vector<int> > Solution::generateMatrix(int A) {
    int n = A;
    int start = 1;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int one = 0;
    int two = 1;
    int three = 1;
    int four = 1;
    while(start<=A*A){
        
        for(int i = one;i<n-one && start<=A*A;i++){
            
            ans[one][i] = start;
            start++;
        }
        
        
        one++;
        
        for(int i = two; i<n-two && start<=A*A; i++){
            ans[i][n-two] = start;
            start++;
            
        }
        two++;
        
        for(int i = n-three;i>=three && start<=A*A;i--){
            ans[n-three][i] = start;
            start++;
            
        }
        three++;
        
        for(int i = n-four;i>=four && start<=A*A;i--){
            
            ans[i][four-1] = start;
            start++;
            
        }
        four++;
    }
    
  
    return ans;
}
