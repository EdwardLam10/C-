/***************************************************************
Title: Set.cpp
Author: Edward Lam
Date Created: 2/14/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Project 1
Description: Source file for the set.h header file. Set Class 
implements the vector class to create a set of unique integers.
***************************************************************/
#include <iostream>
#include "Set.h"

using namespace std;

//Returns size of the set
unsigned int Set::size() const {
	return vector_.size();
}

//Checks if the set is empty, returns bool
bool Set::empty() const {
	if (vector_.size() == 0){
		return true;
	} else {
		return false;
	}
}

//Checks if the set contains 'data', returns bool
bool Set::contains(const int& data) const {
	for (int counter = 0; counter <= vector_.capacity(); counter++) {
		if (vector_.getInt(counter) == data) {
			return true;
		} 
	}
	return false;
}

//Checks for the uniqueness of int 'data' and inserts it, returns a bool value
//depending on success
bool Set::insert(const int& data) {
	if (contains(data)) {
		return false;
	} else {
		vector_.push_back(data);
		return true;
	}
}

//Checks if int 'data' is contained in the set, and removes it, returns a bool
//value depending on success
bool Set::remove(const int& data) {
	if (contains(data)) {
		vector_.remove(data);
		return true;
	} else {
		return false;
	}
}

//Empties the set
void Set::clear() {
	vector_.clear();
}
