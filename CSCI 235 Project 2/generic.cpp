#include <iostream>
/***************************************************************
Title: generic.cpp
Author: Edward Lam
Date Created: 03/13/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Assignment #2
Description: The base class that all the other tasks inherit from.
***************************************************************/

#include <string>

#include "date.h"
#include "generic.h"

using namespace std;

generic::generic(string dateStr, string descStr) {
  date_.makeDate(dateStr);
  description_ = descStr;
}

date* generic::getDate() { return &date_; }

int generic::getComplete() { return complete_; }

void generic::printTask() {
  cout << date_.getDate() << " - " << description_ << endl;
}

void generic::printDetail() {
  cout << date_.getDate() << " - " << description_ << endl;
}

void generic::printCompleted() {
  if (complete_ == 1) {
    printTask();
  }
}

void generic::completeTask() { complete_ = 1; }

//makeString will be inherited to every task as virtual
//makeString, in a sense, prepares a string that will have all the task's info to be inserted into a file.
string generic::makeString() {
	string saveString;
	saveString = "G|" + getDate()->getDate() + "|" + description_;
	return saveString;
}

