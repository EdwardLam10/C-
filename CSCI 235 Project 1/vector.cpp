/***************************************************************
Title: Vector.cpp
Author: Edward Lam
Date Created: 2/14/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Project 1
Description: Source file for the Vector.h header file. The Vector
class was made by using dynamic arrays to imitate a Vector. 
***************************************************************/
#include "Vector.h"
#include <iostream>

using namespace std;

//Vector Class constructor
Vector::Vector(unsigned int capacity) {
	arr_ = new int [capacity];
	size_ = 0;
	capacity_ = capacity;
}

//Vector Class Destructor
Vector::~Vector() {
	delete[] arr_;
}

//Vector Class Copy Constructor
Vector::Vector(const Vector& rhs) {
  size_ = rhs.size_;
  capacity_ = rhs.capacity_;
  arr_ = new int[capacity_];
  for (int counter = 0; counter <= capacity_; counter++) {
  	arr_[counter] = rhs.arr_[counter];
	}
}

//Vector Class Copy Assignment Operator
Vector&  Vector::operator=(const Vector& rhs) {
  size_ = rhs.size_;
  capacity_ = rhs.capacity_;
  arr_ = new int[capacity_];
  for (int counter = 0; counter <= capacity_; counter++) {
  	arr_[counter] = rhs.arr_[counter];
	}	
}

//Returns the capacity of the vector
unsigned int Vector::capacity() const {
  return capacity_;
}

//Returns the size of the vector
unsigned int Vector::size() const {
  return size_;
}

//Checks if the vector is empty, returns bool
bool Vector::empty() const {
  if (size_ == 0){
  	return true;
  } else {
  	return false;
  }
}

//Adds an int 'data' to the next open spot in the vector, if vector is at max 
//capacity, a new vector is created to replace the old one with a new max 
//capacity and the same members that were in the previous vector.
void Vector::push_back(const int& data) {
	if (size_ == capacity_) {
		int* tempArray = new int[capacity_];
		for (int counter = 0; counter <= capacity_; counter++) {
			tempArray[counter] = arr_[counter];
		}
		delete[] arr_;
		capacity_ = capacity_ * 2;
		int* arr = new int[capacity_];
	} else {
		arr_[size_] = data;
		size_++;
	}
}

//If int 'data' is in the vector, it will be removed. The rest of the vector 
//will be pushed foward to replace the gap, if applicable.
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
	return false;
}

//Resets the vector to default state.
void Vector::clear() {
	size_ = 0;
  capacity_ = 3;
}

//Allow [] operator for vector in order to easily access vector members
int& Vector::operator[](unsigned int pos){
  return arr_[pos];
}

//Second function to access vector members due to a problem in the Set class
int& Vector::getInt(unsigned int pos) const{
	return arr_[pos];
}

//Checks if 'pos' is a valid position in the vector and assigns the value at 
//'pos' to 'data'.
bool Vector::at(unsigned int pos, int& data) const {
  if (pos <= size_) {
  	data = arr_[pos];
  	return true;
  } else {
  	return false;
  }
}


