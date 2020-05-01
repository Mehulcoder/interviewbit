int Solution::removeDuplicates(vector<int> &A) {
// Do not write main() function.
// Do not read input, instead use the arguments to the function.
// Do not print the output, instead return values as specified
// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

int l=A.size();
int i=0,j=1;
while(j<l){
    if(A[i]==A[j]){
        j=j+1;
    }
    else if(A[i]!=A[j]){
        A[i+1]=A[j];
        i++;
        j++;
    }
}

A.resize(i+1);
return i+1;
}