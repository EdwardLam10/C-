/***************************************************************
Title: shopping.h
Author: Edward Lam
Date Created: 03/13/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Assignment #2
Description: shopping class that inherits from generic class.
***************************************************************/

#ifndef SHOPPING_H
#define SHOPPING_H

#include <string>
#include <vector>

#include "date.h"
#include "generic.h"

class shopping : public generic
{
 public:
  shopping(string dateStr, string descStr);
  shopping(string dateStr, string descStr, vector<string> rhs);
  void enterList();
  
  void printTask();
  void printDetail();
  string makeString();
 protected:
  vector<string> shoppingList_;
};

#endif

