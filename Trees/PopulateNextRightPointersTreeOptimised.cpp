/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
TreeLinkNode* getNext(TreeLinkNode* A){
	TreeLinkNode* temp = A->next;
	while(temp){
		if (temp->left)
		{
			return temp->left;
		}
		if (temp->right)
		{
			return temp->right;
		}
		temp = temp->next;
	}
	
	return NULL;
}

void Solution::connect(TreeLinkNode* A) {
	if (A==NULL)
	{
		return;
	}

	TreeLinkNode* p = A;
	A->next = NULL;
	//Go down down to fetch childs
	while(p){
		TreeLinkNode* q = p;
		//Connect childs of all at a same level
		while(q){
			if (q->left)
			{
				if (q->right)
				{
					q->left->next = q->right;
				}else{
					q->left->next = getNext(q);
				}
			}

			if (q->right)
			{
				q->right->next = getNext(q);
			}

			q = q->next;
		}
		
		if (p->left)
		{
			p = p->left;
		}else if (p->right)
		{
			p = p->right;
		}else{
			p = getNext(p);
		}
	}

	return;
}
