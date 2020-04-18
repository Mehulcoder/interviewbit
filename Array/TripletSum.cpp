// 1> Prepare the window of size 3 with the first 3 elements
// 2> IF (array.len <= 3): CHECK IF window-sum is in the range (1,2), then RETURN accordingly
// 3> FOR i = 3 UPTO (array.len-1)
// 3.1> SORT the window (3log3 = constant time operation)
// 3.2> IF window-sum is in the range (1,2): RETURN 1 or TRUE
// 3.3> ELSE IF window-sum < 1: Replace the smallest element in the window (window[0]) with array[i]
// 3.4> ELSE IF window-sum > 2: Replace the largest element in the window (window[2]) with array[i]
// 4> Outside the loop, check the FINAL window sum and RETURN accordingly.

/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
Given an array of real numbers greater than zero in form of strings.
Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 .
Return 1 for true or 0 for false.

Example:

Given [0.6, 0.7, 0.8, 1.2, 0.4] ,

You should return 1

as

0.6+0.7+0.4=1.7

1<1.7<2

Hence, the output is 1.

O(n) solution is expected.

Note: You can assume the numbers in strings don’t overflow the primitive data type and there are no leading zeroes in numbers. Extra memory usage is allowed.

*/





int Solution::solve(vector<string> &A) {
    int n = A.size();
    if(n<3){
        return 0;
    }

    vector<double> window;
    for(int i = 0;i<3;i++){
        window.push_back(stod(A[i]));
    }
    
    sort(window.begin(), window.begin()+3);
    double sum = window[0]+window[1]+window[2];
    // cout<<sum<<endl;
    
    for(int i = 3;i<n;i++){
        if(sum<2 && sum>1 ){
            return 1;
        }
        
        if(sum>=2){
            window[2] = stod(A[i]);
            sort(window.begin(), window.end());
            sum = window[0]+window[1]+window[2];
        }else{
            window[0] = stod(A[i]);
            sort(window.begin(), window.end());
            sum = window[0]+window[1]+window[2];
        }
    }
    
    if(sum<2 && sum>1 ){
        return 1;
    }
    
    return 0;
}
