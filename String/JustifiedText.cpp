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

string helper(vector<string> A, int n, int spaces,int start){
	string ans = "";
	if (n==1)
	{
		ans+=A[start];
		for (int i = 0; i < spaces; ++i)
		{
			ans+=" ";
		}
		return ans;
	}

	int stock = spaces%(n-1);
	// debug(spaces)
	for (int i = start; i < n+start; ++i)
	{
		ans+=A[i];
		int space_after = (spaces)/(n-1);
		if (stock>0)
		{
			space_after++;
			stock--;
		}
		// debug(space_after)
		// spaces = spaces - space_after;
		if (i!=n+start-1)
		{
			for (int i = 0; i < space_after; ++i)
			{
				ans+=" ";
			}
		}
		
	}
	// cout << ans << '\n';
	return ans;
	// int each = spaces/(n-1);

}


vector<string> fullJustify(vector<string> &A, int B) {
	vector<string>ans;
	if (A.size()==0)
	{
		return ans;
	}

	int sum = 0;
	string temp = "";
	int spaces = 0;
	int word_sum = 0;
	int word_count = 0;
	for (int i = 0; i < A.size(); ++i)
	{
		sum += A[i].size();
		word_sum += sum;
		word_count++;
		if (i==A.size()-1)
		{
			string temp2 = helper(A,1,B-A[i].size(),A.size()-1);
			ans.push_back(temp2);
		}
		for (int j = i+1; j < A.size(); ++j)
		{
			if (sum+1+A[j].size()>B)
			{
				spaces = B - word_sum;
				// debug(word_sum)
				// debug(spaces)
				// debug(i)
				string out = helper(A, word_count, spaces, i);
				i = j-1;
				ans.push_back(out);
				break;
			}
			word_sum+=A[j].size();
			spaces++;
			sum+=1+A[j].size();
			word_count++;
			if (j==A.size()-1)
			{
				// cout << "ehehhehhe" << '\n';
				string temp3 = "";
				for (int p = i; p < word_count+i-1; ++p)
				{
					temp3+=A[p];
					temp3+=" ";
				}
				temp3+=A[j];
				int rem_spacess = B-temp3.size();
				for (int l = 0; l < rem_spacess; ++l)
				{
					temp3+=" ";
				}
				ans.push_back(temp3);

				return ans;
				
			}
			
			// debug(word_count)

		}
		sum = 0;
		word_count = 0;
		word_sum = 0;
		spaces = 0;
	}
	return ans;

}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	

	int n;
	cin>>n;
	vector<string> v1;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin>>s;
		v1.push_back(s);
	}
	
	int b;
	cin>>b;

	vector<string> ans = fullJustify(v1,b) ;
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << '\n';
	}

	return 0 ; 
}

