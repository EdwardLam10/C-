#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "graphs.h"

using namespace std;

int main(int argc, char **argv) {
	if(argc != 3) {
		cout << "Usage: " << argv[0] << " <graphFile> <queryFile> " << endl;
		return 0;
	}
	string graphFileName = argv[1];
	string queryFileName = argv[2];

	//Creating the graph
	string inputString;
	ifstream inputFile(graphFileName);
	getline(inputFile, inputString);
	int tmp =  stoi(inputString);
	graphs Graph1;
	while(getline(inputFile, inputString)) {
		Graph1.insertVertex(inputString);
	}

	ifstream inputFile2(queryFileName);
	while(getline(inputFile2, inputString)) {
		string temp = inputString.substr(0,1);
		int firstNum = stoi(temp);
		temp = inputString.substr(1,2);
		int secNum = stoi(temp);
		Graph1.check(firstNum, secNum);
	}
}