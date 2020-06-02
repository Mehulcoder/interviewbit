/*

                Name: Mehul Chaturvedi
                IIT-Guwahati

*/

/*
                PROBLEM STATEMENT

*/

#include <bits/stdc++.h>
using namespace std;
#include <chrono> 
#ifndef mehul
#pragma GCC optimize("Ofast")
#endif

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;

#define debug(x) cout << '>' << #x << ':' << x << endl;
#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

#define INF 4557430888798830399ll
#define MOD 1000000007
#define EPS 1e-7
#define PI acos(-1)


#define sz(x) (int)(x).size()
 
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define trav(a, x) for(auto& a : x)
#define fil(ar, val) memset(ar, val, sizeof(ar))  // 0x3f for inf, 0x80 for -INF can also use with pairs

#ifdef mehul
template<typename T>
void __p(T a) { cout << a << " "; }
template<typename T>
void __p(std::vector<T> a) { cout << "{ "; for (auto p : a) __p(p); cout << "}"; }
template<typename T, typename F>
void __p(pair<T, F> a) { cout << "{ "; __p(a.first); __p(a.second); cout << "}"; }
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) { __p(a1); __p(a...); }
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cout<<name<<" : ";__p(arg1);cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    int bracket=0,i=0;
    for(; ;i++)
        if(names[i]==','&&bracket==0)
            break;
        else if(names[i]=='(')
            bracket++;
        else if(names[i]==')')
            bracket--;
    const char *comma=names+i;
    cout.write(names,comma-names)<<" : ";
    __p(arg1);
    cout<<"| ";
    __f(comma+1,args...);
}
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
int begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
#else
#define endl '\n'
#define trace(...)
#define end_routine()
#endif

int Solution::isMatch(const string A, const string B) {

    //in B replace multiple * with a single *
    int n = B.size();
    int m = A.size();
    string s1 = A;
    string s2 =  "";
    int flag = 0;
    rep(i, n){
        if (!flag && B[i]=='*')
        {
            s2+='*';
            flag = 1;
        }else if (B[i]!='*')
        {
            flag = 0;
            s2+=B[i];
        }
    }

    m = s2.size();
    n = A.size();

    vector<vector<bool>> dp(n, vector<bool>(m, 0));

    //Filling 0,0
    if (s2[0] == '*' || (s2[0]==s1[0] || s2[0]=='?'))
    {
        dp[0][0] = 1;
    }

    //Filling col 0
    fr(i, 1, n-1){
        if (s2[0]=='*')
        {
            dp[i][0] = 1;
        }else{
            break;
        }
    }

    //Filling row 0
    int count = 0;
    if (s2[0]!='*')
    {
        count = 1;
    }
    fr(j, 1, m-1){
        if (count)
        {
            if (s2[j]!='*')
            {
                dp[0][j] = 0;
            }else{
                dp[0][j] = dp[0][j-1];
            }
            continue;
        }
        if (s2[j]=='?')
        {
            count++;
            dp[0][j] = dp[0][j-1];
        }else if (s2[j]!='*')
        {
            count++;
            dp[0][j] = (s2[j]==s1[0])?(dp[0][j-1]):0;
        }else{

            dp[0][j] = 1;
        }
    }

    fr(i, 1, n-1){
        fr(j, 1, m-1){
            if (s2[j]=='?' || s2[j]==s1[i])
            {
                dp[i][j] = dp[i-1][j-1];
            }else if (s2[j] == '*')
            {
                //Include star as curr char or as blank
                dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
            }else{
                dp[i][j] = 0;
            }
        }
    }

//     rep(i, n){
//         trace(dp[i]);
//     }
    return dp[n-1][m-1];
}

