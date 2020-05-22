
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

#define INF 4557430888798830399ll
#define MOD 1000000007
#define EPS 1e-7
#define PI acos(-1)


#define sz(x) (int)(x).size()
 
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define trav(a, x) for(auto& a : x)
#define fil(ar, val) memset(ar, val, sizeof(ar))  // 0x3f for inf, 0x80 for -INF can also use with pairs
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

int solver(vector<int>A)
{
	int n = A.size();

    unordered_map<int, int> prevSum;
	int res = 0; 
    int currsum = 0; 
  
	for (int i = 0; i < n; i++) { 
  
        // Add current element to sum so far. 
        currsum += A[i]; 

        if (currsum == 0)  
            res++;         

        if (prevSum.find(currsum) !=  prevSum.end())  
            res += (prevSum[currsum]); 

        prevSum[currsum]++; 
    } 

    return res; 
    
}

int Solution::solve(vector<vector<int> > &A) {
	int n = A.size();
	if (n==0) return 0;
	int m = A[0].size();
	if(m==0)return 0;
	int count = 0;
	vector<vector<int>> dp(n, vector<int>(m, 0));

	rep(j, m){
		dp[0][j] = A[0][j];
	}
	
	fr(i, 1, n-1){
		rep(j, m){
			dp[i][j]=A[i][j]+dp[i-1][j];
		}
	}

	rep(i, n){
		fr(j, i, n-1){
			vector<int> helper(m, 0);
			rep(k, m){
				helper[k]+=dp[j][k];
				if (i-1>=0)
				{
					helper[k]-=dp[i-1][k];
				}
			}
			count+=solver(helper);
		}
	}

	
	return count;
}
