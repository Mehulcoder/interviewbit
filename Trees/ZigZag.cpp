vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {

if(A==NULL)
    return {{}};
vector<vector<int>> soln;
queue<TreeNode *> q;
q.push(A);
q.push(NULL);
vector<int> level;
int level_count=1;

while(q.size()>0){
    TreeNode * front = q.front();
    q.pop();
    
    if(front==NULL){
        
        if(level_count%2==1) // odd level, print as it is
            soln.push_back(level);
        else{ //even level, reverse level
            reverse(level.begin(), level.end());
            soln.push_back(level);
        }
        level_count++;
        level.clear();
        if(q.size()!=0)
            q.push(NULL);
    }
    else{
        if(front->left!=NULL)
            q.push(front->left);
        if(front->right!=NULL)
            q.push(front->right);
        level.push_back(front->val);
    }
}
return soln;
}