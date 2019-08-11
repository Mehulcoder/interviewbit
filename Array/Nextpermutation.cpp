/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers.

If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.

The replacement must be in-place, do not allocate extra memory.

Examples:

1,2,3 → 1,3,2

3,2,1 → 1,2,3

1,1,5 → 1,5,1

20, 50, 113 → 20, 113, 50
Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

 Warning : DO NOT USE LIBRARY FUNCTION FOR NEXT PERMUTATION. Use o

*/


#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

using namespace std;

void reverse(vector<int> &A, int index){
    int n = A.size();
    
    for (int i = index; i <=index+ (n-1-index)/2; ++i)
    {
        int temp = A.at(i);
        A.at(i) = A.at(n-1-(i-index));
        A.at(n-1-(i-index)) = temp;
    }

    return;


}

void swap(vector<int> &A, int index){
   int to_be_swapped = index-1;
    if (index - 1 < 0)
    {
        return;
    }
    for (int i = index; i < A.size(); ++i)
    {
        if (A.at(i)>A.at(to_be_swapped))
        {
            int temp  = A.at(to_be_swapped);
            A.at(to_be_swapped) = A.at(i);
            A.at(i) = temp;
            return;
        }
    }
    return;



}
void Solution::nextPermutation(vector<int> &A) {

    int n = A.size();
    int index = n-1;
   // cout<<"teest"<<endl;
    for (int i = n-1; i > 0; i--)
    {
        if (A.at(i)>A.at(i-1))
        {
            break;
        }
        index--;
        
    }

    reverse(A, index);
    swap(A, index);
    
}