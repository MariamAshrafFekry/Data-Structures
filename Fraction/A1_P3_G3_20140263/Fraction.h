#include<iostream>
using namespace std;
class Fraction
{
private:
	int num;
	int dem;
public:
	Fraction();
	Fraction(int n, int d);
	Fraction(Fraction & f1);
	~Fraction();
	Fraction operator+(Fraction & f1);
	Fraction operator-(Fraction & f1);
	Fraction operator*(Fraction & f1);
	Fraction operator/(Fraction & f1);
	Fraction operator=(Fraction & f1);
	bool operator<(Fraction & f1);
	bool operator>(Fraction & f1);
	bool operator==(Fraction & f1);
	bool operator>=(Fraction & f1);
	bool operator<=(Fraction & f1);
	Fraction reduce();
	friend istream & operator>>(istream & is, Fraction & f1);
	friend ostream & operator<<(ostream & os, Fraction  &f1);
};