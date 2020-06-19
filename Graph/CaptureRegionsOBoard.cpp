// correct one

bool val(int i, int j, int r, int c) {
    return (i >= 0 && i < r && j >= 0 && j < c);
}

void dfsForBoundary(int i, int j, int r, int c, vector<vector<char>> &A)
{
    A[i][j] = '-';

    if (val(i + 1, j, r, c) && A[i + 1][j] == 'O') 
        dfsForBoundary(i + 1, j, r, c, A);
    
    if (val(i - 1, j, r, c) && A[i - 1][j] == 'O') 
        dfsForBoundary(i - 1, j, r, c, A);
    
    if (val(i, j + 1, r, c) && A[i][j + 1] == 'O') 
       dfsForBoundary(i, j + 1, r, c, A);
    
    if (val(i, j - 1, r, c) && A[i][j - 1] == 'O') 
        dfsForBoundary(i, j - 1, r, c, A);
    

    return;
}

void Solution::solve( vector<vector<char>> &N)
{
    
    
        // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

   int R = N.size(), C = N[0].size();
   

   for( int i = 0; i < C; i++)
   {
      if( N[0][i] == 'O')
       dfsForBoundary(0, i, R, C, N );
  
      if(N[R-1][i] == 'O')  
       dfsForBoundary(R-1, i, R, C, N );

   }

   for( int j = 0; j < R; j++)
   {
     if(N[j][0] == 'O')
       dfsForBoundary(j, 0, R, C, N );
    
     if(N[j][C-1] == 'O')
       dfsForBoundary(j, C-1, R, C, N );

   }

   // substituting surrounded 'O' by 'X'
   for( int i = 0; i < R; i++)
     for( int j = 0; j < C; j++)
        {
          if( N[i][j] == '-')
             N[i][j] = 'O';
          else //if( N[i][j] == 'O')
             N[i][j] = 'X';
        }
return;
}