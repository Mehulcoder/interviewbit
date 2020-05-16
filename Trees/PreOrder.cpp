/*
Space Optimized Solution: The idea is to start traversing the tree from root node, and keep printing the left child while 
exists and simultaneously, push right child of every node in an auxiliary stack. Once we reach a null node, pop a right child 
from the auxiliary stack and repeat the process while the auxiliary stack is not-empty.

Below is the implementation of the above approach:
-> Push Root
-> while(stack is not empty || you don't reach a null node)
    keep printing left child and push right child to stack
*/

class Solution {
    public:
        vector<int> preorderTraversal(TreeNode *root) {
            vector<int> res;
            stack<TreeNode*> nodeStack;

            while (nodeStack.size() != 0 || root != NULL) {
                if(root == NULL) {
                    root = nodeStack.top();
                    nodeStack.pop();
                } else {
                    res.push_back(root->val);
                    if(root->right != NULL)
                        nodeStack.push(root->right);
                    root = root->left;
                }
            }
            return res;
        }
};