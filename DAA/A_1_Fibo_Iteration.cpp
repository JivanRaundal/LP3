// A-1] Fibonacci Series
// Using Iteration : Time Complexity => O(N)
//					 Space Complexity => O(1)

#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"\nEnter the number : ";
	cin>>n;
	
	cout<<"\n\nFibonacci Series\n";
	int t1=0, t2=1, t=0;
	for(int i=1; i<=n; i++)
	{
		if(i==1)
		{
			cout<<t1<<" ";
			continue;
		}
		if(i==2)
		{
			cout<<t2<<" ";
			continue;
		}
		t = t1 + t2;
		t1 = t2;
		t2 = t;
		cout<<t<<" ";
	}
	
	return 0;
}
