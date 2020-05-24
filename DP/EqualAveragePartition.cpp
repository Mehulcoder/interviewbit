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

vector<vector<int> > avgset(vector<int> &A) {
	sort(all(A));
	int sum = 0;
	int n = A.size();
	rep(i, n){sum+=A[i];}
	int lsize = (n)/2;
	vector<vector<int>> temp;
	vector<unordered_map<int, vector<int>>>dp(lsize+1);
	dp[0][0] = {};
	// trace(A);
	rep(k, n){
		frr(i, lsize, 1){
			trav(b, dp[i-1]){
				vector<int> temp = b.s;
				temp.push_back(k);
				int summm = b.f+A[k];
				dp[i][summm] = temp;
			}
		}
	}
	trav(a, A){
		
	}

	// trace(lsize);
	// trav(ele, dp[2]){
	// 	trace(ele.f, ele.s);
	// }
	// return temp;
	fr(i, 1, lsize){
		int needSum = (sum*i)/n;
		if (sum*i%n!=0)
		{
			continue;
		}
		rep(j, n){
			int toLook = needSum-A[j];
			if (dp[i-1].find(toLook)!=dp[i-1].end() && std::find(all(dp[i-1][toLook]), j)==dp[i-1][toLook].end())
			{
				vector<int> temp3 = dp[i-1][toLook];
				trav(index, temp3){
					index = A[index];
				}
				// trace(temp3, A[j]);
				temp3.push_back(A[j]);
				sort(all(temp3));
				// trace(dp[i-1].f, dp[i]);
				temp.push_back(temp3);
				unordered_map<int, int> freq;
				trav(el, A){
					freq[el]++;
				}
				trav(el, temp3){
					freq[el]--;
				}
				vector<int> temp4;
				trav(el, A){
					if (freq[el]>0)
					{
						temp4.push_back(el);
						freq[el]--;
					}
				}
				sort(all(temp4));
				temp.push_back(temp4);
				// return temp;
			}
		}
	}
	trav(elee, temp){
		trace(elee);
	}
	if (temp.size()==0)
	{
		return temp;
	}
	vector<int> junk(A.size(), INT_MAX);
	vector<int> junk2;
	for (int i = 0; i < temp.size(); i=i+2)	
	{
		if (junk.size()>temp[i].size())
		{
			junk = temp[i];
			junk2 = temp[i+1];
		}else if (junk.size()==temp[i].size())
		{
			
			rep(j, junk.size()){
				if (junk[j]<temp[i][j])
				{
					break;
				}
				if (junk[j]>temp[i][j])
				{
					junk = temp[i];
					junk2 = temp[i+1];
					break;
				}
			}
			
		}
	}
	temp.clear();
	temp.push_back(junk);
	temp.push_back(junk2);
	return temp;
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

