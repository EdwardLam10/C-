#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	//initializations
	int input, product;
	ifstream inputstream;
	ofstream outputstream;
	inputstream.open("input.txt");
	outputstream.open("output.txt");
	
	//Inputting the number from the text file.
	inputstream >> input;
	
	//Creating the multiplication tables
	for (int counter = 1; counter <= input; counter++)
	{	
		for (int counter2 = 1; counter2 <= input; counter2++)
		{
			product = counter * counter2;
			outputstream << counter << " x " << counter2 << " = " << product << endl; 
		}
		outputstream << "==========================================" << endl << "==========================================" << endl;
	}
	
	inputstream.close();
	outputstream.close();
	
	return 0;
}
