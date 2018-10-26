#include <iostream>
using namespace std;

int add(int a, int b)
{
	int c;
	c = a + b;
	return c;
}

int main()
{
	
	int a = 0;
	int b = 1;
	int fibb;
	int c;
	
	cout << "How many numbers of Fibonacci do you want? ";
	cin >> c;
	cout << b << endl;
	for(int x = 2; x <= c; x++)
	{
		int fibb = add  (a,b);
		a = b;
		b = fibb;
		cout << fibb << endl;
	}
	
	return 0;
}
