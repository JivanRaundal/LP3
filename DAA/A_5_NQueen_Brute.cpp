// N-Queen (Brute Force)
// Time Complexity => O(N!)
// Auxilary Space => O(N^2)

#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>>& board, int n)
{
	//store duplicates
	int r = row;
	int c = col;
	
	//check for left row
	while(col >= 0)
	{
		if(board[row][col] == 1)
			return false;
		col--;
	}
	//check for upper left diagonal
	row = r;
	col = c;
	while(row>=0 && col>=0)
	{
		if(board[row][col] == 1)
			return false;
		row--;
		col--;
	}
	//check for lower left diagonal
	row = r;
	col = c;
	while(row<n && col>=0)
	{
		if(board[row][col] == 1)
			return false;
		row++;
		col--;
	}
	//else it is safe to place queen at given row & col
	return true;
}

void recSolveNQ(int col, vector<vector<int>>& board, int n)
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
		if(isSafe(row, col, board, n))
		{
			board[row][col] = 1;
			recSolveNQ(col+1, board, n);
			board[row][col] = 0;
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
	recSolveNQ(0, board, n);
}

int main()
{
	int N;
	cout<<"\nEnter board size : ";
	cin>>N;
	
	solveNQ(N);
	
	
	return 0;
}
