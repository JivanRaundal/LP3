// N-Queen Problem :- (Optimal Solution)
// Time Complexity = O(N!)
// Space Complexity = O(N)

#include<bits/stdc++.h>
using namespace std;

void recSolveNQ(int col, vector<vector<int>>& board, vector<int>& leftRow, vector<int>& lowerDiagonal,
				vector<int>& upperDiagonal, int n)
{
	if(col == n)
	{
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
				cout<<board[i][j]<<" ";
			cout<<endl;
		}
		cout<<"----------\n";
		return;
	}
	for(int row=0; row<n; row++)
	{
		if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[(n-1)+col-row]==0)
		{
			board[row][col] = 1;
			leftRow[row] = 1;
			lowerDiagonal[row+col] = 1;
			upperDiagonal[(n-1)+col-row] = 1;
			
			recSolveNQ(col+1, board, leftRow, lowerDiagonal, upperDiagonal, n);
			
			board[row][col] = 0;
			leftRow[row] = 0;
			lowerDiagonal[row+col] = 0;
			upperDiagonal[(n-1)+col-row] = 0;
		}
	}
}

void solveNQ(int n)
{
	vector<vector<int>> board(n);
	for(int i=0; i<n; i++)
	{
		board[i] = vector<int>(n, 0);
	}
	
	vector<int> leftRow(n, 0);
	vector<int> upperDiagonal(2*n-1, 0);
	vector<int> lowerDiagonal(2*n-1, 0);
	
	recSolveNQ(0, board, leftRow, lowerDiagonal, upperDiagonal, n);
}

int main()
{
	int N;
	cout<<"\nEnter board size : ";
	cin>>N;
	
	solveNQ(N);
	
	
	return 0;
}
