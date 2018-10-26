/***************************************************************
Title: shopping.cpp
Author: Edward Lam
Date Created: 03/13/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Assignment #2
Description: Shopping class that inherits from the generic class.
***************************************************************/

#include <iostream>
#include <string>
#include <vector>

#include "date.h"
#include "generic.h"
#include "shopping.h"

using namespace std;

shopping::shopping(string dateStr, string descStr) 
  : generic(dateStr, descStr) {
  enterList();  
}

shopping::shopping(string dateStr, string descStr, vector<string> rhs) 
  : generic(dateStr, descStr) {
  for(int i = 0; i != rhs.size(); i++) {
    shoppingList_.push_back(rhs[i]);
  } 
}

void shopping::enterList() {
  cout << "What items do you need to buy? [Type your item and press ENTER "<<
  "to add another item. Type DONE to complete the list.]" << endl;
  
  string input;
  
  while(input != "DONE" && input != "done" && input != "Done") {
    getline(cin, input);
  	if(input != "DONE" && input != "done" && input != "Done") {
      shoppingList_.push_back(input);
	}
  }
}

void shopping::printTask() {
  cout << date_.getDate() << " - [Shopping] " << description_ << endl;
}

void shopping::printDetail() {
  cout << date_.getDate() << " - [Shopping] " << description_ << endl;
  cout << " ITEMS TO PURCHASE: " << endl;
  for (int i = 0; i < shoppingList_.size(); i++) {
  	cout << "  " << shoppingList_[i] << endl;
  }
}

string shopping::makeString() {
  string saveString;
  saveString = "S|" + getDate()->getDate();
  for (int i = 0; i < shoppingList_.size(); i++) {
  	saveString = saveString + "|" + shoppingList_[i];
  }
  return saveString;
}
	

