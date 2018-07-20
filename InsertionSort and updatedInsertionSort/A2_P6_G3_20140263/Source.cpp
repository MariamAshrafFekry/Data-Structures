#include<iostream>
#include<algorithm>
#include<time.h>
using namespace std;
void InsertionSort(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j >= 0; j--)
		{
			if (a[j - 1]>a[j])
				swap(a[j - 1], a[j]);
		}
	}
}
void NewInsertionSort(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 2; j >= 0; j--)
		{
			if (a[j] > a[j + 1])
			{
				if (a[j] > a[j + 2])
					swap(a[j], a[j + 2]);
			}
			if (a[j + 1] >= a[j])
			{
				if (a[j + 1] > a[j + 2])
					swap(a[j + 1], a[j + 2]);
			}
		}
		for (int i = 0; i<size / 2; i++)
		if (a[i]>a[i + 1])
			swap(a[i], a[i + 1]);
	}
}
int main()
{
	int n;
	cin >> n;
	int *x = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		x[i] = rand() % n;
	}
	clock_t t;
	t = clock();
	InsertionSort(x, n);
	t = clock() - t;
	cout << "time per seond in old insertion = " << double(t) / CLOCKS_PER_SEC << " seconds" << endl;

	clock_t c;
	c = clock();
	InsertionSort(x, n);
	c = clock() - c;
	cout << "time per seond in new insertion = " << double(c) / CLOCKS_PER_SEC << " seconds" << endl;
	
	system("pause");
	return 0;
}