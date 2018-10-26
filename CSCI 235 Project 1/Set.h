/***************************************************************
Title: Set.h
Author: Edward Lam
Date Created: 2/14/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Project 1
Description: Header file for the set.cpp soure file. Set Class 
implements the vector class to create a set of unique integers.
***************************************************************/
#ifndef __CS235_SET_H_
#define __CS235_SET_H_

#include "Vector.h"

class Set {
public:
	unsigned int size() const;
	bool empty() const;
	
	bool contains(const int& data) const;
		
	bool insert(const int& data);
	bool remove(const int& data);

	void clear();

private:
	Vector vector_;

};

#endif
