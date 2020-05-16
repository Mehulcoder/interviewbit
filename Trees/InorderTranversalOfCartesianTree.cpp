/*
First take a couple of examples and find their preorder  and inorder.Soon you'll be able figure out the pattern which ig you already have done. Next 

1) Pick an element from Preorder. Increment a Preorder Index Variable (preIndex ) to pick next element in next recursive call.

2) Create a new tree node  with the data as picked element.
3) Find the picked element’s index in Inorder. Let the index be inIndex.
4) Call build for elements before inIndex and make the built tree as left subtree of tNode.
5) Call build for elements after inIndex and make the built tree as right subtree of tNode.
6) return Node.

*for step 3 create a separate function called say Find with takes the inorder as input,the starting and ending index. Within the given start and end find the required element in the inorder and return the index.The start will be :

TreeNode* node = new TreeNode(preorder[p++]);

    int in = find(inorder, i, j, node->val);

    node->left = makeTree(preorder, inorder, i, in-1, p);

    node->right = makeTree(preorder, inorder, in+1, j, p);

    return node;

 
*/



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