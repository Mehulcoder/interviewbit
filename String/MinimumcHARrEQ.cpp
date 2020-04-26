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

ll helper(string A){
    if (A.size()==1)
    {
        return 1;
    }else if (A.size()==0)
    {
        return 0;
    }

    ll i = 0;
    ll j = A.size()-1;
    ll flag = 0;

    while(A[i]==A[j] && i<=j){
        i++;
        j--;
        flag = 1;
    }
    
    if(flag == 0){
        j--;
    }

    if (i>j)
    {
        return A.size();
    }

    return helper(A.substr(0, j+1));
}

int Solution::solve(string A) {
    ll n = A.size();
    if (A.size()==1|| A.size()==0)
    {
        return 0;
    }

    ll len = helper(A);

    return A.size()-len;
}

