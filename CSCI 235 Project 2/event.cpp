/***************************************************************
Title: event.cpp
Author: Edward Lam
Date Created: 03/13/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Assignment #2
Description: Event class is another task class that inherits from 
             generic.
***************************************************************/

#include <iostream>
#include <string>

#include "date.h"
#include "event.h"
#include "generic.h"

using namespace std;

event::event(string dateStr, string descStr, string locStr, string timeStr)  
  : generic(dateStr, descStr) {
  location_ = locStr;
  time_ = timeStr;
}

string event::getLoc() { return location_; }

string event::getTime() { return time_; }

void event::printTask() {
  cout << date_.getDate() << " - [Event] " << description_ << endl;
}

void event::printDetail() {
  cout << date_.getDate() << " - [Event] " << description_ << endl;
  cout << " WHERE: " << location_ << endl;
  cout << " WHEN: " << time_ << endl;
}

string event::makeString() {
  string saveString;
  saveString = "E|" + getDate()->getDate() + "|" + description_ + "|" + location_ + "|" + time_;
  return saveString;
}
