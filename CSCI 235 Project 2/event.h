/***************************************************************
Title: event.h
Author: Edward Lam
Date Created: 03/13/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Assignment #2
Description: Event class is another task class that inherits from
             generic.
***************************************************************/

#ifndef EVENT_H
#define EVENT_H

#include <string>

#include "date.h"
#include "generic.h"

using namespace std;

class event : public generic
{
 public:
  event(string dateStr, string descStr, string locStr, string timeStr);
  string getLoc();  //gets deleted
  string getTime(); //gets deleted

  void printTask();
  void printDetail();
  string makeString();

 protected:
  string location_;
  string time_;
};

#endif

