#include <iostream>

using namespace std;

//Is it Odd or Even function
bool oddoreven(int input)
{
	if(input%2 == 0)
	{
		cout << "The number is even" << endl;
	}
	else
	{
		cout << "The number is odd" << endl;
	}
}

//Is it Prime of Composite function
bool primeorcomposite(int input)
{
	int prime = 0;
	for(int a=2; a<input-1; a++)
	{
		if(input%a == 0)
		{
			prime++;
		}
	}
	if(input < 0)
	{
		cout << "Google says that prime numbers cannot be negative";
	}
	else if(prime == 0)
	{
		cout << "The number is prime";
	}
	else if(input == 1)
	{
		cout << "The number is prime";
	}
	else
	{
		cout << "The number is composite";
	}
}

//Is it divisible by 7 function
bool divideby7(int input)
{
	if(input%7 == 0)
	{
		cout << "The number is divisble by 7";
	}
	else
	{
		cout << "The number is not divisible by 7";
	}
}

int main()
{
	//initializations
	int input;
	char choice;
	
	//Getting the inputs
	cout << "input an integer: ";
	cin >> input;
	
	//Main Menu
	cout << "Press (a) to check if the number is even or odd" << endl << "Press (b) to check if the number is prime or compposite" << endl << "Press (c) to check if the number is divisible by 7." << endl;
	cin >> choice;
	
	//Choosing an option
	switch (choice)
		{
			case 'a':
				oddoreven(input);
				break;
			case 'b':
				primeorcomposite(input);
				break;
			case 'c':
				divideby7(input);
				break;
			default:
				cout << "Invalid choice.";
		}
	
	return 0;
}
