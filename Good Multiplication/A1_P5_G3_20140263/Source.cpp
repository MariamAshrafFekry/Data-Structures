#include<iostream>
using namespace std;
int t = 0;
long long int good_mul(long m, long  n)
{
	t++;
	cout << t << endl;

	if (n == 1)
	{
		return m;

	}
	else if (n % 2 == 0)
		return 2 * good_mul(m, n / 2);
	else if (n % 2 != 0)
		return 2 * good_mul(m, n / 2) + m;
}
int main()
{
	long x, y;
	long long int  z;
	cin >> x >> y;
	z = good_mul(x, y);
	cout << z << endl;
	system("pause");
	return 0;
}