#include<iostream>
#include<math.h>
#include<algorithm>
#include"Fraction.h"
using namespace std;
Fraction::Fraction()
{
	num = 0;
	dem = 1;
}
Fraction::Fraction(int n, int d)
{
	num = n;
	dem = d;
}
Fraction::Fraction(Fraction & f1)
{
	num = f1.num;
	dem = f1.dem;
}
Fraction::~Fraction()
{
	//died object
}
Fraction Fraction::operator+(Fraction & f1)
{
	Fraction f2;
	f2.num = f1.num*dem + f1.dem*num;
	f2.dem = f1.dem*dem;
	return f2;
}
Fraction Fraction::operator-(Fraction & f1)
{
	Fraction f2;
	f2.num = f1.dem*num - f1.num*dem;
	f2.dem = f1.dem*dem;
	return f2;
}
Fraction Fraction::operator*(Fraction & f1)
{
	Fraction f2;
	f2.num = f1.num*num;
	f2.dem = f1.dem*dem;
	return f2;
}
Fraction Fraction::operator/(Fraction & f1)
{
	Fraction f2;
	f2.num = f1.dem*num;
	f2.dem = f1.num*dem;
	return f2;
}
Fraction Fraction::operator=(Fraction & f1)
{
	num = f1.num;
	dem = f1.dem;
	return *this;
}
bool Fraction:: operator<(Fraction & f1)
{
	return((num*1.0 / dem)<(f1.num*1.0 / f1.dem));
}
bool Fraction:: operator>(Fraction & f1)
{
	return((num*1.0 / dem)>(f1.num*1.0 / f1.dem));
}
bool Fraction::operator==(Fraction & f1)
{
	return((f1.num*1.0 / f1.dem) == (num*1.0 / dem));
}
bool Fraction:: operator>=(Fraction & f1)
{
	return((num*1.0 / dem) >= (f1.num*1.0 / f1.dem));
}
bool Fraction::operator<=(Fraction & f1)
{
	return((num*1.0 / dem) <= (f1.num*1.0 / f1.dem));
}
Fraction Fraction::reduce()
{
	for (int i = 2; i <= min(abs(num), abs(dem)); i++)
	{
		while (num%i == 0 && dem%i == 0)
		{
			num /= i;
			dem /= i;

		}

	}
	return *this;
}
istream & operator>>(istream & is, Fraction & f1)
{
	char ch;
	is >> f1.num;
	is >> ch;
	is >> f1.dem;
	return is;
}
ostream & operator<<(ostream &os, Fraction & f1)
{
	if (f1.dem == 0)
		os << "Error division by zero";
	else if (f1.num == 0)
		os << 0;
	else
		os << f1.num << "/" << f1.dem;
	return os;
}
