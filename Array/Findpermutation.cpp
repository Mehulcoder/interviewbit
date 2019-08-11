/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/


/*
				PROBLEM STATEMENT
Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.

D means the next number is smaller, while I means the next number is greater.

Notes

Length of given string s will always equal to n - 1
Your solution should run in linear time and space.
Example :

Input 1:

n = 3

s = ID

Return: [1, 3, 2]

*/	

#include <bits/stdc++.h>

using namespace std;

vector<int> Solution::findPerm(const string A, int B) {
    
    vector<int> ans;
    int dee = B;
    int ie = 1;
    
    
    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i]=='D')
        {
            ans.push_back(dee);
            dee--;
        }else{
            ans.push_back(ie);
            ie++;
        }
    }
    if(A[A.size()-1]=='D'){
        ans.push_back(ie);
    }else{
        ans.push_back(dee);
    }

    return ans;
}



