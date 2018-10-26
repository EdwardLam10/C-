#include <iostream>
#include <vector>
#include "DisjSets.h"

using namespace std;

int main(int argc, char **argv) {
	if(argc != 2) {
		cout << "Usage: " << argv[0] << " <MAXIMUM_NUMBER_OF_NODES> " << endl;
		return 0;
	}
	const int MaxNodes = stoi(argv[1]);

	int x = 0;

	DisjSets DisjointSet(MaxNodes);
	srand(time(0)); //use current time as seed for random generator
	while ( DisjointSet.SubsetCounter() != 1 ) {
		const int random_variable = rand() % MaxNodes + 1;
		const int random_variable2 = rand() % MaxNodes + 1;
		DisjointSet.Union(random_variable, random_variable2);
	}
	DisjointSet.print();
}