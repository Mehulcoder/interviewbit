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

vector<int> ans;
vector<int> originalInput;
vector<vector<vector<bool>>> dp;
int totalSize;

bool isPossible(int start, int currSum, int currSize){
	//Base cases
	if (currSize==0)
	{
		return (currSum == 0);
	}
	//Exceeded the end of the Inputarray or if we have already calculated the result
	if (start>=totalSize || dp[start][currSum][currSize]==0)
	{
		return 0;
	}

	//Include the value at start ---> Because if we are able to include this we'll get the lexographically smallest
	if (currSum - originalInput[start]>=0)
	{
		ans.push_back(originalInput[start]);
		if (isPossible(start+1, currSum - originalInput[start], currSize-1 ))
		{
			return true;
		}
		//Result not found---->Backtrack
		ans.pop_back();
	}

	//Not including the current value
	//Do not forget to set the dp otherwise dp will be of no use and will get TLE
	return dp[start][currSum][currSize] = isPossible(start+1, currSum, currSize);

}


vector<vector<int> > avgset(vector<int> &A) {
	//Clear global variables
	originalInput.clear();
	dp.clear();
	ans.clear();

	originalInput = A;
	sort(all(originalInput));

	int totalSum = 0;
	totalSize = originalInput.size();
	rep(i, totalSize){totalSum+=A[i];}
	//The left most set will me max totalSize/2 (as it is always the smaller one)
	int leftSetMaxSize = totalSize/2;
	//Our final 2d vector which will have both the sets
	vector<vector<int>> finalAns;
	//Initialize dp to all true, in future we'll fetch false ones, and update true ones
	dp.resize(originalInput.size(), vector<vector<bool> > (totalSum + 1, vector<bool> (totalSize, true)));

	fr(i, 1, leftSetMaxSize){
		//If not an integer
		if ((totalSum*i)%totalSize!=0)
		{
			continue;
		}
		int sum = (totalSum*i)/totalSize;
		if (isPossible(0, sum, i))
		{
			
			vector<int> set2;
			sort(all(ans));
			
			//Fill up the second vector maintaing frequency to handle duplicates
			unordered_map<int,int> freq;
			trav(elem, originalInput){freq[elem]++;}
			rep(l, ans.size()){freq[ans[l]]--;}

			trav(elem, originalInput){
				if (freq[elem]>0)
				{
					set2.push_back(elem);
					freq[elem]--;
				}
			}
			sort(all(set2));
			//Push the first set and second set
			finalAns.push_back(ans);
			finalAns.push_back(set2);
			return finalAns;
		}

	}

	return finalAns;
	
}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	#ifdef mehul
    freopen("input.txt", "r", stdin);
	#endif

	int n;
	vector<int> v;
	cin>>n;
	rep(i, n){
		int a;
		cin>>a;
		v.push_back(a);
	}
	vector<vector<int>> ans = avgset(v);
	rep(i, ans.size()){
		trace(ans[i]);
	}

	#ifdef mehul
    end_routine();
	#endif
 
    return 0 ; 
}

