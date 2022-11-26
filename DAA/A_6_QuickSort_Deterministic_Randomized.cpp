/* Quick Sort

1] Deterministic :
Time Complecity => 1) Best & Average Case = O(N*log(N))
				   2) Worst Case = O(N^2)
Space Complexity => O(N)

2] Randomized : (Better than Deterministic)
Time Complexity => Best, Average & Worst Case = O(N*log(N))
Spacce Complexity => O(N)
*/

#include<bits/stdc++.h>
using namespace std;

void swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}

int partition(int arr[], int low, int up)
{
	int pivot = arr[low];
	int p = low+1;
	int q = up;
	
	while(p <= q)
	{
		while(arr[p] <= pivot && p <= up)
			p++;
		
		while(arr[q] > pivot)
			q--;
		
		if(p < q)
			swap(arr[p], arr[q]);
	}
	swap(arr[low], arr[q]);		//Note: arr[low] is pivot
	return q;
}

int partition_r(int arr[], int low, int up)
{
	//generate random number in between low...high
	srand(time(NULL));
	int random = low + rand() % (up - low);
	
	swap(arr[random], arr[low]);
	
	return partition(arr, low, up);
}

void quickSort(int arr[], int low, int up)
{
	int k;
	if(low < up)
	{
		//k = partition(arr, low, up);					//for the Deterministic QuickSort
		k = partition_r(arr, low, up);					//for the Randomized QuickSort
		quickSort(arr, low, k-1);
		quickSort(arr, k+1, up);
	}
}

int main()
{
	int n;
	cout<<"\nHow many elements? ";
	cin>>n; 
	int * arr = new int[n];
	cout<<"\nEnter the array elements\n";
	for(int i=0; i<n; i++)	
		cin>>arr[i];
	
	cout<<"\n\nArray Before Sorting\n";
	for(int i=0; i<n; i++)
		cout<<"  "<<arr[i];
		
	quickSort(arr, 0, n-1);			// quickSort(array, start_index, last_index);
	
	cout<<"\n\nArray After Sorting\n";
	for(int i=0; i<n; i++)
		cout<<"  "<<arr[i];
		
	return 0;
}
