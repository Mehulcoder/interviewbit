TreeNode* build(vector<int>&inorder, vector<int> &preorder, int inStart, int inEnd, int preStart, int preEnd, unordered_map<int, int>m1){
    if(preStart>preEnd){
        return NULL;
    }
    
    int index;
    for (int i = inStart; i <= inEnd; i++){
        if (inorder[i] == preorder[preStart]){
            index = i;
            break;
        }
    }
 
    TreeNode* head = new TreeNode(preorder[preStart]);
    // int index = m1[preorder[preStart]];
    int boxSize = index - inStart;
    head->left = build(inorder, preorder, inStart, index-1, preStart+1, preStart+boxSize, m1);
    head->right = build(inorder, preorder, index+1, inEnd, preStart+boxSize+1, preEnd, m1);
 
    return head;
}
 
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    unordered_map<int, int> m1;
 
    return build(B, A, 0, A.size()-1, 0, A.size()-1, m1);
}