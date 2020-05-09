bool rowColCheck(int row, int col, const vector<string> &A){
	int count = 0;
	for (int i = 0; i < A[0].size(); ++i)
	{
		if (A[row][i] == A[row][col])
		{
			count++;
		}
	}
	if (count>1)
	{
		return 0;
	}

	count = 0;
	for (int i = 0; i < A.size(); ++i)
	{
		if (A[i][col] == A[row][col])
		{
			count++;
		}
	}

	if (count>1)
	{
		return 0;
	}

	return 1;
}


bool squareCheck(int row, int col, const vector<string> &A){
	int squareNumHoriz = col/3;
	int posInSquareHori = col%3;

	int squareNumVert = row/3;
	int posInSquareVerti = row%3;
	
	int startRow = 3*(row/3);
	int startCol = 3*(col/3);
	int count = 0;
	for (int i = startRow; i < startRow+3; ++i)
	{
		for (int j = startCol; j < startCol+3; ++j)
		{
			if (A[i][j] == A[row][col])
			{
				count++;
			}
		}
	}

	if (count>1)
	{
		return 0;
	}

	return 1;

}

int Solution::isValidSudoku(const vector<string> &A) {
	for (int i = 0; i < A.size(); ++i)
	{
		for (int j = 0; j < A[i].size(); ++j)
		{
			if (A[i][j]!='.')
			{
				if (squareCheck(i,j,A) && (rowColCheck(i,j,A)))
				{
					continue;
				}else{
					return 0;
				}
			}
		}
	}
	return 1;
}
