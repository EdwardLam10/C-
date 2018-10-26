#include <iostream>
#include <assert.h>

#include "Set.h"
#include "Vector.h"

using namespace std;

int main() {
	//Testing Construction
	Vector aVec;
	assert(aVec.empty());
	assert(aVec.size() == 0);
	assert(aVec.capacity() == 3);

	//Testing Push Back
	aVec.push_back(5);
	aVec.push_back(3);
	
	assert(aVec.size() == 2);
	assert(!aVec.empty());

	//Testing accessors
	assert(aVec[0] == 5);
	
	int data; 
	assert(aVec.at(0, data));
	assert(data == 5);

	assert(aVec.at(3, data) == false);
	assert(aVec.at(-1, data) == false);

	//Testing Copy & Assignment 
	Vector vectorB(aVec);
	Vector vectorC;
	vectorC = vectorB;

	assert(vectorB.size() == 2);
	assert(vectorC.size() == 2);
	assert(vectorB[0] == 5);
	assert(vectorC[0] == 5);

	//Testing Remove
	assert(!vectorC.remove(10));
	vectorC.push_back(5);
	assert(vectorC.size() == 3);
	assert(vectorC.remove(5));
	assert(vectorC.size() == 2);
	assert(vectorC[0] == 3);
	assert(vectorC[1] == 5);
	vectorC.push_back(6);
	assert(vectorC.remove(5));
	assert(vectorC[0] == 3);
	assert(vectorC[1] == 6);

	//Testing Resize
	vectorC.push_back(1);
	vectorC.push_back(2);
	vectorC.push_back(3);
	vectorC.push_back(4);
	vectorC.push_back(5);

	//Testing Clear
	aVec.clear();
	assert(aVec.empty());


	//Testing Set Construction
	Set aSet;
	assert(aSet.empty());
	assert(aSet.size() == 0);

	//Testing Insert
	assert(aSet.insert(19));
	assert(aSet.size() == 1);
	assert(aSet.insert(29));
	assert(!aSet.insert(19));
	assert(aSet.size() == 2);
	assert(aSet.contains(19));
	assert(aSet.contains(29));
	assert(!aSet.contains(39));

	//Testing Remove
	assert(aSet.remove(19));
	assert(!aSet.contains(19));
	assert(aSet.size() == 1);
	assert(aSet.insert(19));
	assert(aSet.contains(19));

	//Testing Clear
	aSet.clear();
	assert(aSet.empty());
	
	return 0;
}

