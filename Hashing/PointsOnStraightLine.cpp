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



int Solution::maxPoints(vector<int> &A, vector<int> &B) {

	map<pii, int> m1;
	int ans = INT_MIN;
	for (int i = 0; i < A.size()-1; ++i)
	{
		pii coord1 = mp(A[i], B[i]);
		int overlapStarting = 0;
		int perp = 0;
		int maxCount = 0;
		for (int j = i+1; j < A.size(); ++j)
		{
			pii coord2 = mp(A[j], B[j]);
			if (coord1 == coord2)
			{
				overlapStarting++;
				
			}else if (A[i] == A[j])
			{
				perp++;
			}else{
				int delY = (B[j]-B[i]);
				int delX = (A[j]-A[i]);

				int gcd = __gcd(delY, delX);
				delY = delY/gcd;
				delX = delX/gcd;
				pii slope = mp(delX, delY);
				m1[slope]++;
				maxCount = max(maxCount, m1[slope]);
			}
			maxCount = max(maxCount, perp);
		}

		ans = max(ans, maxCount+overlapStarting+1);
		m1.clear();
	}

	return ans;

}
	