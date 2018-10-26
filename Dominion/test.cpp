#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int rng(int i) { return rand()%i; }

void printWithAddress(vector<int> *tmp) {
	for(int i = 0; i < tmp->size(); i++) {
		cout << (*tmp)[i] << endl;
	}
}

int main() {
	vector<int> stuff;
	srand(unsigned(time(0)));
	stuff.push_back(1);
	stuff.push_back(2);
	stuff.push_back(3);
	stuff.push_back(4);
	stuff.push_back(5);
	stuff.push_back(6);
	for(int i = 0; i < stuff.size(); i++) {
		cout << stuff[i] << endl;
	}

	cout << "+++++++++++++++++++++++++++++++++" << endl;

	random_shuffle(stuff.begin(), stuff.end(), rng);
	
	for(int i = 0; i < stuff.size(); i++) {
		cout << stuff[i] << endl;
	}

	cout << "+++++++++++++++++++++++++++++++++" << endl;

	random_shuffle(stuff.begin(), stuff.end(), rng);
	
	for(int i = 0; i < stuff.size(); i++) {
		cout << stuff[i] << endl;
	}

	cout << "+++++++++++++++++++++++++++++++++" << endl;

	random_shuffle(stuff.begin(), stuff.end(), rng);
	
	for(int i = 0; i < stuff.size(); i++) {
		cout << stuff[i] << endl;
	}

	cout << "+++++++++++++++++++++++++++++++++" << endl;

	random_shuffle(stuff.begin(), stuff.end(), rng);
	
	for(int i = 0; i < stuff.size(); i++) {
		cout << stuff[i] << endl;
	}

	printWithAddress(&stuff);

	return 0;
}