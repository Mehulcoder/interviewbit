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


string longestPalindrome(string a) {
	string A = "";
	

	for (int i = 0; i < a.size(); ++i)
	{
		A+='$';
		A+=a[i];
	}
	A+='$';

	vector<int> v1(A.size(), 0);
	int centre = 0;
	int left = 0;
	int right = 0;

	while(1){

		if (centre>=A.size())
		{
			break;
		}
		int flag = 0;
		int i = centre;
		int j = centre;

		//Getting the length around centre
		while(A[i]==A[j] && i>=0 && j<A.size()){
			flag = 1;
			i--;
			j++;
		}

		if (flag == 1)
		{
			i++;
			j--;
		}

		v1[centre] = j-i+1;
	

		//Look for new centre and if found continue else look fill up the rest of the array v1 <= right

		int q = centre+1;
		int p = centre-1;
		int flag2 = 0;
		

		while(p>=i && q<=j){
			
			if (p-(v1[p]-1)/2 == i)
			{
				centre = q;
				flag2 = 1;
				break;
			}

			v1[q] = min((j-q)*2+1, v1[p]);
			
			p--;
			q++;

		}
		if (flag2==1)
		{
			continue;
		}

		//If not found within, the centre will be the next element

		centre = j+1;
	}

	int ans = 1;
	int index = 0;
	for (int i = 0; i < A.size(); ++i)
	{
		if (v1[i]>ans)
		{
			index = i;
			ans = v1[i];
		}
		// ans = max(ans, v1[i]);
		// cout<<v1[i]<<" ";
	}

	// cout <<'\n';
	// cout << index << '\n';
	int start = (index-(ans)/2);

	string res = "";
	for (int i = start; i < start+ans; ++i)
	{
		if (A[i]!='$')
		{
			res+=A[i];
		}
	}

	return res;
}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	string a;
	cin>>a;
	
	cout << longestPalindrome(a) << '\n';


	return 0 ; 
}


