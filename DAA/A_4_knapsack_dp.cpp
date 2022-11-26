// 0/1 - knapsack Memoization

//constraints given 
// 0 < n <= 1000
// 0 < W <= 1000
// Note:- memset() function is used to initialize block of memory
//        Syntax = memset(memory_name, value, size_of_memory_block);

// Time Complexity => O(N*W) 		[N - no of items, W - Capacity of knapsack]
// Space Complexity => O(N*W)+O(N)	[O(N*W) for 2D array & O(N) is auxilary space]

#include<bits/stdc++.h>
using namespace std;

int dp[1002][1002];			//dp matrix for Memoization (declared as global)

void fun()
{
	memset(dp, -1, sizeof(dp));			//initializing matrix with -1
}

int knapsack(int wt[],int val[],int W,int n)
{
	// Base Condition (think of smallest possible input)
	if(n==0 || W==0)
	{
		return 0;
	}
	
	// check if we have already calculated value for n & W
	if(dp[n][W] != -1)
	{
		return dp[n][W];
	}
	
	// if wt[n-1](weight of an item) <= W(capacity of knapsack)
    // then we have choice to include that item or not
	if(wt[n-1] <= W)
	{
		return dp[n][W] = max( val[n-1]+knapsack(wt,val,W-wt[n-1],n-1), knapsack(wt,val,W,n-1) );
	}
	
	// if wt[n-1](weight of an item) > W(capacity of knapsack)
    // then we have no choice (don't include that item)
	else if(wt[n-1] > W)
	{
		return dp[n][W] = knapsack(wt,val,W,n-1);
	}
}

int main()
{
	int *wt,*val;
	int W,n;
	cout<<"\nHow many items? ";
	cin>>n;
	wt = new int[n];
	val = new int[n];
	cout<<"\nEnter wt array\n";
	for(int i=0; i<n; i++)
	{
		cin>>wt[i];
	}
	cout<<"\nEnter val array\n";
	for(int i=0; i<n; i++)
	{
		cin>>val[i];
	}
	cout<<"\nEnter capacity of bag : ";
	cin>>W;
	
	fun();				//to initialize dp matrix
	cout<<"\n\nMaximum Profit = "<<knapsack(wt, val, W, n);
	
	return 0;
}
