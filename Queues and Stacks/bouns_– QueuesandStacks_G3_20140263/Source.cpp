#include <bits/stdc++.h>
using namespace std;
template<class T>
class Queue
{
private:
	stack<T>s;
	T q;
public:
	T first()
	{

		return q;
	}
	bool isempty()
	{
		return s.empty();
	}
	void enqueue(T e)
	{
		if (isempty())
			q = e;
		s.push(e);
	}
	void dequeue()
	{
		stack<T> z;
		while (!s.empty())
		{
			z.push(s.top());
			s.pop();
		}
		z.pop();
		if (!z.empty())
			q = z.top();
		while (!z.empty())
		{
			s.push(z.top());
			z.pop();
		}
	}
	void clear()
	{
		while (!s.empty())
		{
			s.pop();
		}
	}
};

int main(){
	int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Queue <int>q;
	for (int i = 0; i < 10; ++i)
		q.enqueue(a[i]);
	q.dequeue();
	q.enqueue(0);
	while (!q.isempty())
	{
		cout << q.first() << endl;
		q.dequeue();
	}
	system("pause");
}