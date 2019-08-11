/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.

Note that if you end up using an additional array, you will only receive partial score.

Example:

If the array is

[
    [1, 2],
    [3, 4]
]
Then the rotated array becomes:

[
    [3, 1],
    [4, 2]
]
*/

#include <bits/stdc++.h>

using namespace std;




void Solution::rotate(vector<vector<int> > &A) {
    int n=A.size();
    int k=n*n/4;
    int i=0,j=0,a;
    while(k){
        int y=A[i][j],a=4;
        int p=i,q=j;
        while(a){
           int x=A[q][n-p-1];
           A[q][n-p-1]=y;
           y=x;
           a--;
           int t=p;
           p=q;
           q=n-t-1;
        }
        if(j<n-i-2) j++;
        else{i++;j=i;}
        k--;
     }
}


