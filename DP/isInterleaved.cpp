/*

                Name: Mehul Chaturvedi
                IIT-Guwahati

*/

/*
                PROBLEM STATEMENT

*/

#include <bits/stdc++.h>
using namespace std;
#include <chrono> 
#ifndef mehul
#pragma GCC optimize("Ofast")
#endif

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
#define repr(i, n) for (int i = n; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define trav(a, x) for(auto& a : x)
#define fil(ar, val) memset(ar, val, sizeof(ar))  // 0x3f for inf, 0x80 for -INF can also use with pairs

#ifdef mehul
template<typename T>
void __p(T a) { cout << a << " "; }
template<typename T>
void __p(std::vector<T> a) { cout << "{ "; for (auto p : a) __p(p); cout << "}"; }
template<typename T, typename F>
void __p(pair<T, F> a) { cout << "{ "; __p(a.first); __p(a.second); cout << "}"; }
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) { __p(a1); __p(a...); }
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : ";__p(arg1);cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	int bracket=0,i=0;
	for(; ;i++)
		if(names[i]==','&&bracket==0)
			break;
		else if(names[i]=='(')
			bracket++;
		else if(names[i]==')')
			bracket--;
	const char *comma=names+i;
	cout.write(names,comma-names)<<" : ";
	__p(arg1);
	cout<<"| ";
	__f(comma+1,args...);
}
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
int begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
#else
#define endl '\n'
#define trace(...)
#define end_routine()
#endif


// https://www.interviewbit.com/problems/interleaving-strings/

int Solution::isInterleave(string A, string B, string C) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int a = A.size(), b = B.size(), c = C.size();
    
    if((a + b) != c){
        return 0;
    }
    
    vector<vector<int> > temp(a+1, vector<int>(b+1, 0));
    
    temp[0][0] = 1;
    
    for(int i = 1; i < temp.size(); i++){
        if(C[i-1] == A[i-1]){
            temp[i][0] = temp[i-1][0];
        }
    }
    
    for(int i = 1; i < temp[0].size(); i++){
        if(C[i-1] == B[i-1]){
            temp[0][i] = temp[0][i-1];
        }
    }
    
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if((C[i+j-1] == A[i-1]) && (C[i+j-1] == B[j-1])){
                temp[i][j] = max(temp[i-1][j], temp[i][j-1]);
            }
            else if(C[i+j-1] == A[i-1]){
                temp[i][j] = temp[i-1][j];
            }
            else if(C[i+j-1] == B[j-1]){
                temp[i][j] = temp[i][j-1];
            }
        }
    }
    
    // for(int i = 0; i <= a; i++){
    //     for(int j = 0; j <= b; j++){
    //         cout << temp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
        
    
    return temp[a][b];
}