#include<iostream>
#include<time.h>
using namespace std;
int temp[1000000];

void Merge(int a[], int low, int mid, int high)
{
	int size = high - 1;
	for (int i = low; i <= high; i++)
	{
		temp[i] = a[i];
	}
	int i = low;
	int j = mid + 1;
	int k = low;
	while (i <= mid&&j <= high)
	{
		if (temp[i] < temp[j])
		{
			a[k] = temp[i];
			i++;
		}
		else
		{
			a[k] = temp[j];
			j++;
		}
		k++;
	}
	while (i <= mid)
	{
		a[k] = temp[i];
		k++;
		i++;
	}
}
void MergeSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(arr, low, mid);
		MergeSort(arr, mid + 1, high);
		Merge(arr, low, mid, high);
	}
}
void QuickSort(int a[], int low, int high)
{
	int i = low;
	int j = high;
	int pivot = a[(low + high) / 2];
	if (i > j)return;
	else
	{
		while (i < j)
		{
			while (a[i] < pivot)
				i++;
			while (a[j] > pivot)
				j--;
			if (i <= j)
			{
				swap(a[i], a[j]);
				i++;
				j--;
			}
		}
	}
	if (low < j)
		QuickSort(a, low, j);
	if (i < high)
		QuickSort(a, i, high);
}
int main()
{
	int n, nRAND;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}

	/*for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;*/

	clock_t x;
	x = clock();
	MergeSort(a, 0, n - 1);
	cout << "time in seconds for MERGE SORT = " << double(clock() - x) / CLOCKS_PER_SEC << " second " << endl;
	/*for (int j = 0; j < n; j++)
	cout << a[j] << " ";
	cout<< endl;*/
	clock_t t;
	t = clock();
	QuickSort(a, 0, n - 1);
	cout << "time in seconds for QUICK SORT = " << double(clock() - t) / CLOCKS_PER_SEC << " second " << endl;
	system("pause");
	return 0;
}