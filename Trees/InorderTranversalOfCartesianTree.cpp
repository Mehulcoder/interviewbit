TreeNode* insert(vector<int> &A, int &left, int right, int currMax){
    if (left==right)
    {
        return new TreeNode(A[left]);
    }
    if (right<left)
    {
        return NULL;
    }
    int start = left+1;
    int end = left+1;
    TreeNode* head = new TreeNode(A[left]);
    currMax = A[left];
    while(start<=right){
        if (A[start]<currMax)
        {
            end = start;
            while(end<=right && A[end]<currMax){
                end++;
            }
            if (end>right || A[end]>currMax)
            {
                end--;
            }
            head->right = insert(A, start, end, currMax);
            start++;
        }
        if (A[start]>currMax)
        {
            
            currMax = A[start];
            TreeNode* root = new TreeNode(A[start]);
            root->left = head;
            head = root;
            start++;
        }
    }

    return head;
    
}


TreeNode* Solution::buildTree(vector<int> &v) {
    int i = 0;
    return insert(v, i, v.size()-1, INT_MIN);
}