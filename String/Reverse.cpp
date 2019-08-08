/*
Given a string A.

Return the string A after reversing the string word by word.

NOTE:

A sequence of non-space characters constitutes a word.

Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.

If there are multiple spaces between words, reduce them to a single space in the reversed string.

*/
#include <bits/stdc++.h>

using namespace std;
void reverseWords(int i, string &A){
//recursive
    string first_word="";


    int firstlength = 0;
    int j=0;
    for (j = i; A[j]!=' ' && (j)!=A.size() ; ++j)
    {
    	firstlength++;
    	first_word = first_word+A[j];
    }
    
     //Base case
    if (firstlength == A.size()-i)
    {
    	return;
    }
    /*cout << firstlength << '\n';
    return;*/

    

    reverseWords(j+1, A);

    A = A.substr(firstlength+1) + ' ' + first_word;

    return;



}


void reverseWords(string &A) {
    reverseWords(0, A);


}

/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/
//Input file added

#include <bits/stdc++.h>

using namespace std;


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	

	string input;
	getline(cin, input);

	reverseWords(input);
	cout << input << '\n';

	return 0 ; 



}




