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

//Calculate with x as the smallest bar in the rectangle
int getMaxHist(vector<int> A){
	stack<int> s1;

	int i = 0;
	int ans =INT_MIN;
	int area_with_top;
	while(i<A.size()){
		if (s1.empty() || A[i]>=A[s1.top()])
		{
			s1.push(i);
			i++;
		}else{
			tp = s1.top();  // store the top index 
            s1.pop();  // pop the top 
  
            // Calculate the area with hist[tp] stack  
            // as smallest bar 
            area_with_top = hist[tp] * (s1.empty() ? i :  
                                   i - s1.top() - 1); 
  
            // update max area, if needed 
            ans = max(ans, area_with_top)

		}
	}

	 while (s1.empty() == fals1e) 
    { 
        tp = s1.top(); 
        s1.pop(); 
        area_with_top = his1t[tp] * (s1.empty() ? i :  
                                i - s1.top() - 1); 
  
        ans = max(ans, area_with_top);
    } 

    return ans;

}


int Solution::maximalRectangle(vector<vector<int> > &A) {
	int n = A.size();
	int m = A[0].size();
	int ans = INT_MIN;

	rep(i, n){
		if (i==0)
		{
			continue;
		}
		rep(j, m){
			if (A[i][j] == 0)
			{
				continue;
			}
			A[i][j]+=A[i-1][j];
		}
	}

	rep(i, n){
		int temp = getMaxHist(A[i]);
		ans = max(ans, temp);
	}

	return ans;
}
