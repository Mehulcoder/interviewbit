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

int Solution::isPalindrome(string A) {
    ll n = A.size();
    
    transform(A.begin(), A.end(), A.begin(), ::tolower); 

    string s1 = "";

    for (ll i = 0; i < n; ++i)
    {
        // cout<<"A[i]: "<<ll(A[i])<<endl;
        if ((ll(A[i])<=122 && ll(A[i])>=97)||(A[i]<=57 && A[i]>=48))
        {
            s1+=A[i];
        }
    }
    

    ll i = 0;
    ll j = s1.size()-1;

    while(i<=j){
        if (s1[i]!=s1[j])
        {
            return 0;
        }
        i++;
        j--;
    }

    return 1;
}

