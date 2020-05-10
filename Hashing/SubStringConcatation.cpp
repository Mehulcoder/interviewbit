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



vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    vector<int> output;
    
    unordered_map<string, vector<int>> substring;
    int length = 0;
    unordered_map<string, int> pattern;

    for (int i = 0; i < B.size(); ++i)
    {
    	pattern[B[i]]++;
    	length+=B[i].size();
    }

    if (A.size()<length)
    {
    	return output;
    }

    for (int i = 0; i <= A.size()-length; ++i)
    {
    	substring[A.substr(i, length)].push_back(i);
    }

    for(auto it: substring){
    	unordered_map<string, int> tempMap(pattern);
    	string s1 = it.first;
    	vector<int> indexArray = it.second;
    	bool success = 1;
    	for (int i = 0; i < s1.size(); i+=B[0].size())
    	{
    		string temp = s1.substr(i, B[0].size());
    		if (tempMap[temp] == 0)
    		{
    			success = 0;
    			break;
    		}else{
    			tempMap[temp]--;
    		}
    	}
    	if (success)
    	{
    		for(auto it2:tempMap){
    			if (it2.second > 0)
    			{
    				success = 0;
    				break;
    			}
    		}

    		if (success)
    		{
    			for (int i = 0; i < indexArray.size(); ++i)
    			{
    				output.push_back(indexArray[i]);
    			}
    		}
    	}
    }

    return output;
}