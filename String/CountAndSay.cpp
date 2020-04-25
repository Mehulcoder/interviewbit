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


string Solution::countAndSay(int A) {
    if (A==1)
    {
    	return "1";
    }

    string s1 = countAndSay(A-1);
    string ans="";
    
    char count = '1';
    char temp = s1[0];
    
    for (int i = 1; i < s1.size(); ++i)
    {
    	if (s1[i]!=temp)
    	{
    		ans+=count;
    		ans+=temp;
    		count = '1';
    		temp = s1[i];
    		continue;
    	}else{
    		count++;
    	}

    }
    
    ans+=count;
    ans+=temp;

    return ans;
}

