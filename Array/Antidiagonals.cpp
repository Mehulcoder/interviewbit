/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/


/*
				PROBLEM STATEMENT


Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:

		
Input: 	

1 2 3
4 5 6
7 8 9

Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]


Input : 
1 2
3 4

Return the following  : 

[
  [1],
  [2, 3],
  [4]
]

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size();
    vector<vector<int> > ans(2*n-1);

    for (int i = 0; i <= n-1; ++i)
    {
        int temp = i;
        while(temp>=0){
            ans.at(i).push_back(A.at(i-temp).at(temp));
            temp--;
        }
    }
   // return ans;

    for (int i = 0; i < n-1 ; ++i)
    {
        int temp = i+1;
        while(temp<=n-1){
            ans.at(n+i).push_back(A.at(temp).at(n-(temp-i)));
            temp++;
        }
    }

    return ans;


}

