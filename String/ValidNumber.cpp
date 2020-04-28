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


int isNumber(const string str) {
	int i = 0, j = str.length() - 1; 
  
    // Handling whitespaces 
    while (i < str.length() && str[i] == ' ') 
        i++; 
    while (j >= 0 && str[j] == ' ') 
        j--; 
  
    if (i > j) 
        return 0; 
  
    // if string is of length 1 and the only 
    // character is not a digit 
    if (i == j && !(str[i] >= '0' && str[i] <= '9')) 
        return 0; 
  
    // If the 1st char is not '+', '-', '.' or digit 
    if (str[i] != '.' && str[i] != '+'
        && str[i] != '-' && !(str[i] >= '0' && str[i] <= '9')) 
        return 0; 
  
    // To check if a '.' or 'e' is found in given 
    // string. We use this flag to make sure that 
    // either of them appear only once. 
    bool flagDotOrE = false; 
  
    for (i; i <= j; i++) { 
        // If any of the char does not belong to 
        // {digit, +, -, ., e} 
        if (str[i] != 'e' && str[i] != '.'
            && str[i] != '+' && str[i] != '-'
            && !(str[i] >= '0' && str[i] <= '9')) 
            return 0; 
  
        if (str[i] == '.') { 
            // checks if the char 'e' has already 
            // occurred before '.' If yes, return 0. 
            if (flagDotOrE == true) 
                return 0; 
  
            // If '.' is the last character. 
            if (i + 1 > str.length()) 
                return 0; 
  
            // if '.' is not followed by a digit. 
            if (!(str[i + 1] >= '0' && str[i + 1] <= '9')) 
                return 0; 
        } 
  
        else if (str[i] == 'e') { 
            // set flagDotOrE = 1 when e is encountered. 
            flagDotOrE = true; 
  
            // if there is no digit before 'e'. 
            if (!(str[i - 1] >= '0' && str[i - 1] <= '9')) 
                return 0; 
  
            // If 'e' is the last Character 
            if (i + 1 > str.length()) 
                return 0; 
  
            // if e is not followed either by 
            // '+', '-' or a digit 
            if (str[i + 1] != '+' && str[i + 1] != '-'
                && (str[i + 1] >= '0' && str[i] <= '9')) 
                return 0; 
        } 
    } 
  
    /* If the string skips all above cases, then  
    it is numeric*/
    return 1;
}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	string s;
	cin>>s;

	cout <<   isNumber(s) <<endl;



	return 0 ; 
}

