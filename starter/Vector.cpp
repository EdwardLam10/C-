#include "Vector.h"
#include <iostream>

using namespace std;

Vector::Vector(unsigned int capacity) {
  arr_ = new int[capacity];
  size_ = 0;
  capacity_ = 3;
}

Vector::Vector(const Vector& rhs) {
  size_ = rhs.size_;
  capacity_ = rhs.capacity_;
  arr_ = new int[capacity_];
  for (int counter = 0; counter <= capacity_; counter++) {
  	arr_[counter] = rhs.arr_[counter];
	}
}

Vector&  Vector::operator=(const Vector& rhs) {
  size_ = rhs.size_;
  capacity_ = rhs.capacity_;
  arr_ = new int[capacity_];
  for (int counter = 0; counter <= capacity_; counter++) {
  	arr_[counter] = rhs.arr_[counter];
	}	
}

Vector::~Vector(){
	delete[] arr_;
}

bool Vector::remove(const int& data) {
	for (int counter = 0; counter <= capacity_; counter++) {
		if (arr_[counter] == data) {
			for(int counter2 = counter; counter2 <= capacity_; counter2++) {
				arr_[counter2] = arr_[counter2 + 1];
			}
			size_ -= 1;
			return true;
		}
	}
}

void Vector::clear() {
	size_ = 0;
  capacity_ = 3;
}

unsigned int Vector::capacity() const {
  return capacity_;
}

unsigned int Vector::size() const {
  return size_;
}

void Vector::push_back(const int& data) {
  if (size_ == capacity_) {
		int* tempArray = new int[capacity_];
		for (int counter = 0; counter <= capacity_; counter++) {
			tempArray[counter] = arr_[counter];
		}
		delete[] arr_;
		int temp = capacity_;
		capacity_ = capacity_ * 2;
		arr_ = new int[capacity_];
		for (int counter = 0; counter <= temp; counter++) {
			arr_[counter] = tempArray[counter];
		}
		delete[] tempArray;
		size_++;
  } else {
  	arr_[size_] = data;
  	size_++;
  }
}

int& Vector::operator[](unsigned int pos){
  return arr_[pos];
}

int& Vector::getInt(unsigned int pos) const{
  return arr_[pos];
}

bool Vector::at(unsigned int pos, int& data) const {
  if (pos <= size_) {
  	data = arr_[pos];
  	return true;
  } else {
  	return false;
  }
}

bool Vector::empty() const {
  if (size_ == 0){
  	return true;
  } else {
  	return false;
  }
}
 
