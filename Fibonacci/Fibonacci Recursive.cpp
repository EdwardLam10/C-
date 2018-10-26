#include <iostream>
using namespace std;

int fibb(int a)
{
	if (a == 0)
	{
		return 0;
	}
	else if (a == 1)
	{
		return 1;
	}
	else
	{
		return fibb(a-1) + fibb(a-2);
	}
}

int main()
{
	int b;
	cout << "Enter the nth number of Fibonacci" << endl;
	cin >> b;
	fibb (b);
	cout << b << endl;
	return 0;
}
