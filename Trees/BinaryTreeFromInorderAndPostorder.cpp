/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Use unordered map for storing indexes 

TreeNode* build(vector<int> &inorder, vector<int> &postorder, int intStart, int inEnd, int postStart, int postEnd){
    if (postStart>postEnd)
    {
        return NULL;
    }

    TreeNode* head = new TreeNode(postorder[postEnd]);

    int val = postorder[postEnd];
    int temp = intStart;
    while(temp<=inEnd && inorder[temp]!=val){
        temp++;
    }
    

    head->left  = build(inorder, postorder, intStart, temp-1, postStart,postStart-(intStart - temp+1 ));
    head->right  = build(inorder, postorder, temp+1, inEnd, postEnd-(inEnd - temp),postEnd-1);

    return head;

}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int head = B.size()-1;
    return build(A, B, 0, A.size()-1, 0, A.size()-1);
}
