// Fractional Knapsack  (using greedy algorithm)
//	Time Complexity: O(N * log N)
//	Auxiliary Space: O(N)

#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2)
{
	//find the profit per unit (i.e. value / weight)
	double x1 = (double)p1.first / (double)p1.second;
	double x2 = (double)p2.first / (double)p2.second;
	return x1 > x2;
}

double knapsack(vector<pair<int,int>>& arr, int W, int n)
{
	//sort the elements in array in decreasing order based on (profit per unit)
	sort(arr.begin(), arr.end(), compare);
	
	//now fill the items in knapsack such that profit is maximum
	double profit = 0.0;
	for(int i=0; i<n; i++)
	{
		//if weight of item <= capacity of knapsack
		if(arr[i].second <= W)
		{
			profit += arr[i].first;
			W -= arr[i].second;
		}
		//if weight of item > capacity of knapsack, then add the fraction of item in knapsack
		if(arr[i].second > W)
		{
			profit += W * ((double)arr[i].first / (double)arr[i].second);		// capacity * profit per unit
			W = 0;
			break;
		}
	}
	return profit;
}

int main()
{
	int n;
	int W;
	cout<<"\nEnter the number of items : ";
	cin>>n;
	vector<pair<int,int>> arr(n);		//pair<value, weight>
	
	cout<<"\nEnter value and weight of items\n";
	for(int i=0; i<n; i++)
	{
		cin>>arr[i].first;				//value
		cin>>arr[i].second;				//weight
	}
	cout<<"\nEnter capacity of knapsack : ";
	cin>>W;
	
	cout<<"\nMaximum Profit = "<<knapsack(arr, W, n);
	
	return 0;
}
