void Solution::merge(vector<int> &A, vector<int> &B) {
   int n = A.size();
   int m = B.size();

   int i = 0;
   int j = 0;
   vector<int> ans;

   while(i<n && j<m){
   		if (A[i]<=B[j])
   		{
   			ans.push_back(A[i]);
   			i++;
   		}else{
   			ans.push_back(B[j]);
   			j++;
   		}
   }

   while(i<n){
   	ans.push_back(A[i]);
   	i++;
   }

   while(j<m){
   	ans.push_back(B[j]);
   	j++
   }

   A = ans;

}
