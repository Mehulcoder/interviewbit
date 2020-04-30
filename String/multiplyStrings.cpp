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

string add(vector<string> v1){
	int n = v1.size();
	string ans = "";
	string start = v1[0];
	if (n==1)
	{
		return start;
	}

	for (int i = 1; i < v1.size(); ++i)
	{
		int carry = 0;
		string temp;
		string second = v1[i];
		int p = start.size()-1;
		int q = second.size()-1;

		while(p>=0 && q>=0){
			int num1 = int(start[p]-'0');
			int num2 = int(second[q]-'0');
			int val = num1+num2+carry;
			// debug(val)
			carry = val/10;
			val = val%10;
			temp+=char(val+'0');
			// debug(temp)
			p--;
			q--;
		}

		while(p>=0){
			int num = int(start[p]-'0');
			int val = num+carry;
			carry = val/10;
			val = val%10;
			temp+=char(val+'0');
			p--;
		}


		while(q>=0){
			int num = int(second[q]-'0');
			int val = num+carry;
			carry = val/10;
			val = val%10;
			temp+=char(val+'0');
			q--;
		}
		reverse(all(temp));
		start = temp;
		// cout << temp << '\n';
		ans = temp;
	}
	return ans;
}

string multiply(string A, string B) {
	reverse(all(B));
	vector<string> strings;
	string addition = "";
	for (int i = 0; i < B.size(); ++i)
	{
		int carry = 0;
		int num = int(B[i]-'0');
		string temp = "";
		for (int j = A.size()-1; j >= 0; j--)
		{
			int num2 = int(A[j]-'0');
			int prod = num2*num+carry;
			carry = (prod)/10;
			int val = (prod)%10;
			temp += char(val+'0');
		}
		temp+=char(carry+'0');
		reverse(all(temp));
		temp+=addition;
		addition+='0';
		strings.push_back(temp);	
		// cout << temp << '\n';
		// cout << B.size() << '\n';
	}

	// return "";
	string ans = add(strings);
	while(ans.substr(0,1)=="0"){
		ans = ans.substr(1);
	}
	// cout << ans << '\n';
	if (ans.size()==0)
	{
		return "0";
	}
	return ans;

}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	string a,b;
	cin>>a>>b;

	cout<<multiply(a,b)<<endl;


	return 0 ; 



}

