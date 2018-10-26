#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
	if(argc != 2) {
		cout << "Usage: " << argv[0] << " <dimensionsFile> " << endl;
		return 0;
	}

	//Getting numbers from file.
	vector<int> numbers;
	ifstream openFile(argv[1]);
	while(!openFile.eof()) {
		string tmp;
		getline(openFile, tmp);
		numbers.push_back(stoi(tmp));
	}
	
	//Initializing the chart with 0
	int table[numbers.size()][numbers.size()] = {0};

	//Filling in the chart from the diagonal up.
	//Going through the chain lengths
	for(int chainLength = 2; chainLength < numbers.size(); chainLength++) {
		//2 ints used as a traversal
		for(int m = 1, n = chainLength; n < numbers.size(); m++, n++) {
			//Calculating both possibilities
			int tmp1 = table[m][n-1] + (numbers[m-1]*numbers[n-1]*numbers[n]);
			int tmp2 = table[m+1][n] + (numbers[m-1]*numbers[m]*numbers[n]);
			//Taking the smaller possibility
			if(tmp1 <= tmp2) {
				table[m][n] = tmp1;
			} else {
				table[m][n] = tmp2;
			}
		}
	}

	for(int i = 1; i < numbers.size(); i++) {
		for(int n = 1; n < numbers.size(); n++) {
			cout << table[i][n] << " " ;
		}
		cout << endl;
	}

	cout << "The optimal number of multiplications is: " << table[1][numbers.size()-1] << endl;

}