/***************************************************************
Title: Vector.h
Author: Edward Lam
Date Created: 2/14/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Project 1
Description: header file for the Vector.cpp source file. The Vector
class was made by using dynamic arrays to imitate a Vector. 
***************************************************************/
#ifndef __CS235_VECTOR_H_
#define __CS235_VECTOR_H_

class Vector {
 public:
	Vector(unsigned int capacity = DEFAULT_CAPACITY);
	~Vector();
	Vector(const Vector& rhs);
	Vector& operator=(const Vector& rhs);

	unsigned int capacity() const;
	unsigned int size() const;
	bool empty() const;

	void push_back(const int& data);
	bool remove(const int& data);
	
	void clear();

	int& operator[](unsigned int pos);
	int& getInt(unsigned int pos) const;
	bool at(unsigned int pos, int& data) const;


private:
	int* arr_;
	unsigned int size_;
	unsigned int capacity_;

	static const unsigned int DEFAULT_CAPACITY = 3;

	void resize(unsigned int capacity);
	
};

#endif
