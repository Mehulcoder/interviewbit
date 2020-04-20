// https://www.youtube.com/watch?v=-MpL0X3AHAs


long long mod = 1000003;
int Solution::findRank(string A) {
    vector<vector<int>> rep(A.size());
    vector<int> ranklessthan(A.size());
    // vector<int> rank;
    int n = A.size();
    long double logfact[n+1];
    logfact[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        logfact[i] = log(i)+(logfact[i-1]);
        // fact[i] = fact[i];
    }
    
    
    for(int i=A.size()-1;i>=0;i--){
        int rankless = 0;
        for (int j = i+1; j < A.size(); ++j)
        {
            // cout<<"A[j] "<<A[j]<<" "<<A[i]<<" ";
            if (A[j]<A[i])
            {
                rankless++;
            
            }
        }
        ranklessthan[i] = rankless;
        // cout<<rankless<<" ";
    }
    
    // for(int i=0;i<n;i++){
    //     cout<<ranklessthan[i]<<" ";
    // }
    // cout<<endl;
    

    unordered_map<char, int> m1;
    for(int i=A.size()-1;i>=0;i--){
        int reps = 1;
        m1[A[i]]++;

        for(auto j=m1.begin();j!=m1.end();j++){
            rep[i].push_back(j->second);
        }
    }
   
//   for(int i=0;i<n;i++){
//         for(int j=0;j<rep[i].size();j++){
//             cout<<rep[i][j]<<" ";
//         }
        
//         cout<<endl;
//     }

    long double ans = 0;
    for (int i = 0; i < n; ++i)
    {
        long double num = ranklessthan[i];
        if(num==0){
            continue;
        }
        num = log(num);
        // cout<<"ranklessthan: "<<num<<endl;
        num = (num)+(logfact[n-i-1]);
        // cout<<"fact[n-i-1]: "<<fact[n-i-1]<<" "<<endl;
        // num = num;
        // cout<<" num: "<<num<<endl;
        long double divide = 0;
        for (int j = 0; j < rep[i].size(); ++j)
        {
            divide = (divide)+((logfact[rep[i][j]]));
            // divide = divide;
            // num = num/(fact[rep[i][j]]);
            // cout<<rep[i][j]<<" ";
        }
        // cout<<"divide: "<<divide<<" ";
        num = num-divide;
        num = pow(e, num);
        num = int(num)%1000003;
        // cout<<endl;
        // cout<<num<<" ";
        ans+=num;
        // cout<<"ans: "<<ans<<endl;
        ans = int(ans)%1000003;
    }

    return (int)((int)(ans+1)%1000003);
}
