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

string helper(vector<string> A, ll start, string s1){
	if (start>=A.size() || s1.size()==0)
	{
		return s1;
	}

	string s2 = A[start];
	string s3 = "";
	for (int i = 0; i < min(s1.size(), s2.size()); ++i)
	{
		if (s1[i]!=s2[i])
		{
			break;
		}

		s3+=s1[i];
	}

	string ans = helper(A, start+1, s3);

	return ans;

}

string Solution::longestCommonPrefix(vector<string> &A) {
	ll n = A.size();

	if (A.size()==0)
	{
		return NULL;
	}

	string s1 = A[0];
	ll start = 1;
	string ans = helper(A, start, s1);
	
	return ans;
}
