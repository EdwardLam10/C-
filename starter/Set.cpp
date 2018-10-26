#include "Set.h"
#include <iostream>

using namespace std;

bool Set::empty() const {
	if (size() == 0){
		return true;
	} else {
		return false;
	}
}

unsigned int Set::size() const {
	return vector_.size();
}

bool Set::insert(const int& data) {
	if (contains(data)) {
		return false;
	} else {
		vector_.push_back(data);
		return true;
	}
}

bool Set::contains(const int& data) const {
	for (int counter = 0; counter <= vector_.capacity(); counter++) {
		if (vector_.getInt(counter) == data) {
			return true;
		} else {
			return false;
		}
	}
}

bool Set::remove(const int& data) {
	if (contains(data)) {
		vector_.remove(data);
		return true;
	} else {
		return false;
	}
}

void Set::clear() {
	vector_.clear();
}
