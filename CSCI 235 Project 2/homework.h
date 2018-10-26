/***************************************************************
Title: homework.h
Author: Edward Lam
Date Created: 03/13/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Assignment #2
Description: Another task class that inherits from generic
***************************************************************/

#ifndef HOMEWORK_H
#define HOMEWORK_H

#include <string>

#include "date.h"
#include "generic.h"

class homework : public generic
{
 public:
  homework(string dateStr, string descStr, string subjStr);
  
  void printTask();
  void printDetail();
  string makeString();
 protected:
  string subject_;
};

#endif

