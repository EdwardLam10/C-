#include <iostream>
#include <queue>
#include <utility>

using namespace std;

struct cow {
	int nipples;
	pair<int, double> stuff;
};

struct comparator {
	bool operator()(cow *lhs, cow *rhs) {
		return lhs->nipples < rhs->nipples;
	}
};


int main() {
	int i = 0;
	int z = 1;
	i,z += 1;
	cout << i << " " << z << endl;
}