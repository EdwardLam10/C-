#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "graphs.h"

using namespace std;

int main(int argc, char **argv) {
	if(argc != 3) {
		cout << "Usage: " << argv[0] << " <graphFile> <startingVertex> " << endl;
		return 0;
	}
	string graphFileName = argv[1];
	int startingVertex = stoi(argv[2]);

	//Creating the graph
	string inputString;
	ifstream inputFile(graphFileName);
	getline(inputFile, inputString);
	int tmp =  stoi(inputString);
	graphs Graph1;
	while(getline(inputFile, inputString)) {
		Graph1.insertVertex(inputString);
	}

	Graph1.makeDijkstraChart(startingVertex);
}