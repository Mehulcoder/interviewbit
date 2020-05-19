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


vector<int> Solution::solve(int A, vector<int> &B) {
	int maxCount = A/(*min_element(all(B)));
	int minValue = *(min_element(all(B)));
	vector<int> ans;
	int start = 0;
	int count = 0;
	while(start<B.size()){
		if (start == min_element(all(B))-B.begin())
		{
			for (int i = 0; i < maxCount; ++i)
			{
				ans.push_back(start);
			}
			break;
		}
		int n = (A-maxCount*minValue)/(B[start]-minValue);
		if (n>=maxCount)
		{
		    n=maxCount;
		}
		for (int i = 0; i < n; ++i)
		{
			ans.push_back(start);
			A-=B[start];
			maxCount--;
		}
		start++;
	}

	return ans;

}
