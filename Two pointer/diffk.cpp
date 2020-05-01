int Solution::diffPossible(vector<int> &A, int B) {
    int n = A.size();
    // int i = 0;
    // int j = n-1;
    if (A.size()==0 || A.size()==1)
    {
        return 0;
    }
    for (int i = 0; i < n-1; i++)
    {
        // cout<<"n: "<<n<<endl;
        int to_find = abs(B+A[i]);

        int index = lower_bound(A.begin()+i+1, A.end(), to_find)-A.begin();
        // cout<<"i: "<<i<<" "<<to_find<<endl;
        // cout<<"index: "<<index<<" "<<A[index]<<endl;
// //         return 0;
        if(index>n-1){
            return 0;
        }
        if (A[index]!=to_find)
        {
            continue;
        }else{
            return 1;
        }
    }
}
