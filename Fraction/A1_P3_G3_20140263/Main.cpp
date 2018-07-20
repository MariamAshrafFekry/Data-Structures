#include<iostream>
#include<math.h>
#include<algorithm>
#include"Fraction.h"
using namespace std;
class FractionCalculator
{
public:
	Fraction x, y, z;
	void runcalculator()
	{
		cout << "Enter the first fraction ";
		cin >> x;
		cout << "Enter the second fraction";
		cin >> y;
		z = x.operator+(y);
		cout << x << " + " << y << " = " << z;
		cout << "Fraction after reducing: " << z.reduce() << endl;
		z = x.operator-(y);
		cout << x << " - " << y << " = " << z;
		cout << "Fraction after reducing: " << z.reduce() << endl;
		z = x.operator*(y);
		cout << x << " * " << y << " = " << z;
		cout << "Fraction after reducing: " << z.reduce() << endl;
		z = x.operator/(y);
		cout << x << " / " << y << " = " << z;
		cout << "Fraction after reducing: " << z.reduce() << endl;
		if (x.operator>(y))
			cout << x << " is greater than " << y << endl;
		if (x.operator<(y))
			cout << x << " is less than " << y << endl;
		if (x.operator==(y))
			cout << x << " is equal to " << y << endl;
		if (x.operator<=(y))
			cout << x << " is less than or equal " << y << endl;
		if (x.operator>=(y))
			cout << x << " is greater than or equal " << y << endl;

		/*z = x + y;
		cout << x << " + " << y << " = " << z << " after reducing = ";
		cout<<z.reduce()<<endl;
		z = x - y;
		cout << x << " - " << y << " = " << z << " after reducing = ";
		cout<< z.reduce() << endl;
		z = x*y;
		cout << x << " * " << y << " = " << z << " after reducing = ";
		cout<< z.reduce() << endl;
		z = x / y;
		cout << x << " / " << y << " = " << z << " after reducing = ";
		cout<< z.reduce() << endl;
		if (x > y)
		cout << x << " is greater than " << y  << endl;
		if (x < y)
		cout << x << "is less than " << y << endl;
		if (x == y)
		cout << x << " is equal to " << y << endl;
		if (x >= y)
		cout << x << " is greater than or equal " << y << endl;
		if (x <= y)
		cout << x << " is less than or equal " << y << endl;
		cout << x << "is reduced=";
		cout<< x.reduce() << endl;
		cout << y << "is reduced =";
		cout<< y.reduce() << endl;*/
	}
};
int main()
{
	FractionCalculator t;
	t.runcalculator();
	system("pause");
	return 0;
}