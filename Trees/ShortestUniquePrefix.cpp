class node
{
public:
	char c;
	unordered_map<char, node*> child;
	int frequency;
};

node* createNewNode(char x){
	node* newTrieNode = new node;
	newTrieNode->frequency = 1;
	newTrieNode->c = x;
	return newTrieNode;
}

/*
			H--->E--->L--->P
					  |
					  |
					  L
					  |
					  |
					  O 
*/			

vector<string> Solution::prefix(vector<string> &A) {
	node* newNode  = createNewNode('$');
	vector<string> ans;
	for (int i = 0; i < A.size(); ++i)
   	{
   		node* ptr = newNode;
   		string word = A[i];
   		for (int j = 0; j < word.size(); ++j)
   		{
   			if ((ptr->child).find(A[i][j])==(ptr->child).end())
			{
				ptr->child[A[i][j]] = createNewNode(A[i][j]);		
			}else{
				(ptr->child[A[i][j]]->frequency)++;
			}
			ptr = ptr->child.at(A[i][j]);
   		}
   	}

   	for (int i = 0; i < A.size(); ++i)
   	{
   		node* ptr = newNode;
   		string str;
   		for (int j = 0; j < A[i].size(); ++j)
   		{
   			str += A[i][j];
   			if (ptr->child.at(A[i][j])->frequency == 1)
   			{
   				ans.push_back(str);
   	// 			ptr = ptr->child->at(A[i][j]);
   				break;
   			}
			ptr = ptr->child.at(A[i][j]);
   		}
   	}

   	return ans;
}