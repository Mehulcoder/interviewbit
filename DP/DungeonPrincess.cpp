/*

                Name: Mehul Chaturvedi
                IIT-Guwahati

*/

/*
                PROBLEM STATEMENT

*/

#include <bits/stdc++.h>
using namespace std;

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
#define MOD 1000000007
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

template<typename T>
void __p(T a) { cout << a << " "; }
template<typename T>
void __p(std::vector<T> a) { cout << "{ "; for (auto p : a) __p(p); cout << "}"; }
template<typename T, typename F>
void __p(pair<T, F> a) { cout << "{ "; __p(a.first); __p(a.second); cout << "}"; }
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) { __p(a1); __p(a...); }


int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();

    int** dp = new int*[n];
    for (int i = 0; i < n; ++i)
    {
        dp[i] = new int[m];
        for (int j = 0; j < m; ++j)
        {
            dp[i][j] = -1;
        }
    }

    if (A[n-1][m-1] > 0)
    {
        dp[n-1][m-1] = 1;
    }else{
        dp[n-1][m-1] = abs(A[n-1][m-1])+1;
    }

    for (int i = n-2; i >= 0; --i)
    {
        dp[i][m-1] = max(dp[i+1][m-1]-A[i][m-1], 1);
    }

    for (int i = m-2; i >= 0; --i)
    {
        
        dp[n-1][i] = max(dp[n-1][i+1]-A[n-1][i], 1);
    }


    for (int i = n-2; i >= 0; --i)
    {
        for (int j = m-2; j >= 0; --j)
        {
            int onExit = min(dp[i+1][j], dp[i][j+1]);
            dp[i][j] = max(onExit-A[i][j], 1);
        }
    }


    return dp[0][0];

}
