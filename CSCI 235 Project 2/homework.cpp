/***************************************************************
Title: homework.cpp
Author: Edward Lam
Date Created: 03/13/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Assignment #2
Description: Another task class that inherits from generic
***************************************************************/

#include <iostream>
#include <string>

#include "date.h"
#include "generic.h"
#include "homework.h"

using namespace std;

homework::homework(string dateStr, string descStr, string subjStr) 
  : generic(dateStr, descStr) {
  subject_ = subjStr;
}

void homework::printTask() {
  cout << date_.getDate() << " - [Homework] " << description_ << endl;
}

void homework::printDetail() {
  cout << date_.getDate() << " - [Homework] " << description_ << endl;
  cout << " Subject:  " << subject_ << endl;
}

string homework::makeString() {
  string saveString;
  saveString = "H|" + getDate()->getDate() + "|" + description_ + "|" + subject_;
  return saveString;
}
