/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/



/*
				PROBLEM STATEMENT
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Example :

Input : [1, 10, 5]
Output : 5 
Return 0 if the array contains less than 2 elements.

You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
You may also assume that the difference will not overflow.

*/


/*
							SOLUTION APPROACH

http://www.stokastik.in/leetcode-maximum-gap/

This problem has a naive solution using sort and linear scan. The suggested solution uses the idea of bucket sort. 
The following is a C++ implementation of the suggested solution.

Suppose all the n elements in nums fall within [l, u], the maximum gap will not be smaller
 than gap = (u - l) / (n - 1).However, this gap may become 0 and so we take the maximum of it 
 with 1 to guarantee that the gap used to create the buckets 
 is meaningful.

Then there will be at most m = (u - l) / gap + 1 buckets. For each number num, it will fall in
 the k = (num - l) / gap bucket. After putting all elements of nums in the corresponding buckets,
  we can just scan the buckets to compute
  the maximum gap.

The maximum gap is only dependent on the maximum number of the current bucket and the minimum number of the
 next neighboring bucket (the bucket should not be empty). So we only store the minimum and the maximum of
  each bucket. Each bucket is initialized as {minimum = INT_MAX, maximum = INT_MIN} and then updated while 
  updating the buckets.

Putting these together, we can have the following solution, barely a straight-forward implementation of the 
suggested solution.

*/

/*

1) Let's say that the minimum is min, and maximum is max. Also say that total number of elements is n.
2) Then we can say that the maximum gap b/w elements is surely not less than the decimal value of mindiff = (max-min)/(n-1).
3) Let's start from "min" to understand the process. Put all the elements b/w min and min+mindiff in one bucket and keep track of maximum element and minimum element in that bucket.Why?
    -> Because of statement 1, say if we choose left as "min", for our ans, right is obviously >= min+mindiff
    -> Why maximum and minimum need to be stored? As we are looking for differeces between elements when they are
    sorted. Therefore only candidates are max from left bucket and min from right bucket(Alternate in sorted array)
    -> No need to check bucket ke andar ke diff because answer usse bada hi aaega,
3) Just like ["min" to "min+mindiff") make buckets [min+mindiff to min+2*mindiff]........

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::int maximumGap(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return 0;
    auto lu = minmax_element(nums.begin(), nums.end());
    int l = *lu.first, u = *lu.second;
    int gap = max((u - l) / (n - 1), 1);
    int m = (u - l) / gap + 1;
    vector<int> bucketsMin(m, INT_MAX);
    vector<int> bucketsMax(m, INT_MIN);
    for (int num : nums) {
        int k = (num - l) / gap;
        if (num < bucketsMin[k]) bucketsMin[k] = num;
        if (num > bucketsMax[k]) bucketsMax[k] = num;
    }
    int i = 0, j; 
    gap = bucketsMax[0] - bucketsMin[0];
    while (i < m) {
        j = i + 1;
        while (j < m && bucketsMin[j] == INT_MAX && bucketsMax[j] == INT_MIN)
            j++;
        if (j == m) break;
        gap = max(gap, bucketsMin[j] - bucketsMax[i]);
        i = j;
    }
    return gap;
}