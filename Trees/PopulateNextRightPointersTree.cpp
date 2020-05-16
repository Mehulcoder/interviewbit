/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
bool isLeaf(TreeLinkNode* A){
	return (!A->left && !A->right);
}

void Solution::connect(TreeLinkNode* A) {
	if (A==NULL)
	{
		return;
	}
	queue<TreeLinkNode*> q1;
	q1.push(A);
	q1.push(NULL);
	TreeLinkNode* prevHead = NULL;
	while(!q1.empty()){
		TreeLinkNode* head = q1.front();
		if (!prevHead && !head)
		{
			return;
		}
		if (prevHead!=NULL)
		{
			prevHead->next = head;
		}
		if (head == NULL)
		{
			
			q1.push(NULL);
			prevHead = head;
			q1.pop();
			continue;
		}

		if (head->left)
		{
			q1.push(head->left);
		}
		if (head->right)
		{
			q1.push(head->right);
		}
		prevHead = head;
		q1.pop();
	}
	
	return;
}
