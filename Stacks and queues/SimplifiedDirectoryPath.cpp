string Solution::simplifyPath(string A) {
    stack<string> s;

    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i]=='.')
        {
            if (i+1<A.size() && A[i+1]=='.')
            {
                if(!s.empty()){
                    s.pop();
                }
                i++;
                continue;
            }
        }else if (A[i] != '/' && A[i]!='.')
        {
            string s2 = "";
            while(i<A.size() && A[i] != '/' && A[i]!='.'){
                s2+=A[i];
                i++;
            }
            i--;
//             cout<<s2<<endl;
            s.push(s2);
        }
    }
    if(s.empty()){
        return "/";
    }
    vector<string> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    reverse(ans.begin(), ans.end());

    string out = "";
    for (int i = 0; i < ans.size(); ++i)
    {
        out+="/";
        out+=ans[i];
    }

    return out;
}
