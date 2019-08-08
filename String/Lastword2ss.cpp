/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/


#include <bits/stdc++.h>

using namespace std;
int lengthOfLastWord(const string A) {
	stringstream ss;
    
    ss<<A; //Add string to string stream object
    
    string c=""; //Make an empty string
    while(!ss.eof()){  //Loop till end of ss
        ss>>c;			//read and put words from ss to c and keep on updating till
   						//last word
    }
    return c.length();


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
