 // A-1] Fibonacci Series
// Using Recursion : Time Complexity => O(2^N) i.e. exponential
//					 Space Complexity => O(N)		due to internal stack

#include<iostream>
using namespace std;

int fibo(int n)
{
	if(n <= 1)
	{
		return n;
	}
	return fibo(n-1) + fibo(n-2);
}

int main()
{
	int n;
	cout<<"\nEnter the number : ";
	cin>>n;
	
	cout<<"\n\nFibonacci Series\n";
	for(int i=0; i<n; i++)
	{
		cout<<fibo(i)<<" ";
	}
	
	return 0;
}
