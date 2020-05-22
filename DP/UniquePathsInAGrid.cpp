
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

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
	int n = A.size();
	int m = A[0].size();

	A[n-1][m-1] = (A[n-1][m-1] == 0);
	frr(i,m-2, 0){
		if (A[n-1][i]==1)
		{
			A[n-1][i] = 0;
			continue;
		}
		A[n-1][i] = A[n-1][i+1];
	}

	frr(i,n-2, 0){
		if (A[i][m-1]==1)
		{
			A[i][m-1] = 0;
			continue;
		}
		A[i][m-1] = A[i+1][m-1];
	}

	frr(i, n-2, 0){
		frr(j, m-2, 0){
			if (A[i][j] == 1)
			{
				A[i][j] = 0;
				continue;
			}
			A[i][j] = A[i+1][j]+A[i][j+1];
		}
	}
	

	return A[0][0];
}
