/***************************************************************
Title: date.h
Author: Edward Lam
Date Created: 03/13/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Assignment #2
Description: date class contains both ints and strings for easy
             access when comparing or printing dates.
***************************************************************/

#ifndef DATE_H
#define DATE_H

#include <string>

using namespace std;

class date
{
 public:
  void makeDate(string date);
  
  int getMonth();
  int getDay();
  int getYear();
  
  string getDate();
  
 private:
  int month_;
  int day_;
  int year_;
  string date_;
};

#endif
