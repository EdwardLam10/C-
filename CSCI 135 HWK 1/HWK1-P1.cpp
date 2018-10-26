#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
	//initializations
	int input, product;
	ifstream inputstream;
	ofstream outputstream;
	inputstream.open("input.txt");
	
	//Reading the input from the text file
	inputstream >> input;
	
	//Creating the multiplication tables
	ostringstream filename;
    for (int i=0; i<10; i++)
    {
        filename.str("");
        filename << "Table" << i << ".txt";
        cout << filename.str() << endl;
	 	for (int counter = 1; counter <= input; counter++)
		{	
			for (int counter2 = 1; counter2 <= input; counter2++)
			{
				product = counter * counter2;
				outputstream << counter << " x " << counter2 << " = " << product << endl; 
			}
			outputstream << "==========================================" << endl << "==========================================" << endl;
		}
	}
	return 0;
}
