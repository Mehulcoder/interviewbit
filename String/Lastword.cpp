/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/


#include <bits/stdc++.h>

using namespace std;
int lengthOfLastWord(const string A) {
	int ans = 0;
	cout << A.length() << '\n';

	for (int i = 0; i < A.size();)
	{
		
		while (A[i]==' ')
		{
			if(i==A.size()-1){
				return ans;
			}
			if(A[i+1]!=' '){
			ans = 0;
			}
			i++;
			continue;
		}
		ans++;
		i++;
	}

	return ans;


}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	string s="";
	getline(cin, s);

	cout << lengthOfLastWord(s)  << '\n';


	return 0 ; 



}
