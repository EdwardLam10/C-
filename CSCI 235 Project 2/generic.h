/***************************************************************
Title: generic.h
Author: Edward Lam
Date Created: 03/13/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Assignment #2
Description: The base class that all the other tasks inherit from.
***************************************************************/

#ifndef GENERIC_H
#define GENERIC_H

#include <string>

#include "date.h"

using namespace std;

class generic
{
 public:
  generic(string dateStr, string descStr);
  
  date* getDate();  //Returns a pointer to a date object in order to access the date.
  int getComplete();
  
  virtual void printTask();    //Both print functions have been made virtual
  virtual void printDetail();  //all tasks will print different amounts of things.
  void printCompleted();       
  
  void completeTask();

  virtual string makeString();
  
 protected:
  int complete_ = 0;
  string description_;
  date date_;
};

#endif

