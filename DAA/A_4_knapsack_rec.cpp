// 0/1 - knapsack Recursive
// Time Complexity => O(2^N)	i.e. exponential
// Space Complexitu => O(1) + O(N) (NOTE:- O(N) is auxilary space used for recursion)


#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt[],int val[],int W,int n)
{
	// Base Condition (think of smallest possible input)
	if(n==0 || W==0)
	{
		return 0;
	}
	// if wt[n-1](weight of an item) <= W(capacity of knapsack)
    // then we have choice to include that item or not
	if(wt[n-1] <= W)
	{
		return max ( val[n-1]+knapsack(wt,val,W-wt[n-1],n-1), knapsack(wt,val,W,n-1) );
	}
	// if wt[n-1](weight of an item) > W(capacity of knapsack)
    // then we have no choice (don't include that item)
	else if(wt[n-1] > W)
	{
		return knapsack(wt,val,W,n-1);
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
	
	cout<<"\n\nMaximum Profit = "<<knapsack(wt, val, W, n);
	
	return 0;
}
