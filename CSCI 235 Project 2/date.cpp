/***************************************************************
Title: date.cpp
Author: Edward Lam
Date Created: 03/13/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Assignment #2
Description: date class contains both ints and strings for easy
             access when comparing or printing dates.
***************************************************************/

#include "date.h"

using namespace std;

void date::makeDate(std::string date) {
  date_ = date;
  string month = date.substr(0,3);
  string day = date.substr(3,5);
  string year = date.substr(6,10);

  month_ = stoi(month);
  day_ = stoi(day);
  year_ = stoi(year); 
}

int date::getDay() { return day_; }

int date::getMonth() { return month_; }

int date::getYear() { return year_; }

std::string date::getDate() { return date_; }

