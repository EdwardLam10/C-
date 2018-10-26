/***************************************************************
Title: dictionary.h
Author: Edward Lam
Date Created: 5/07/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Assignment #3
Description: header file for dictionary class. the wrapper class
for the trie.
***************************************************************/

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <fstream>
#include <queue>
#include <string>

#include "trie.h"
#include "trieNode.h"

using namespace std;

class dictionary
{
 public:
  dictionary(string input);
  ~dictionary() { dictionary_.clear(); } //not sure if a destructor is really neccesary since I dont use any new/delete in my code.
  
  void load(string input);
  int numCount() { return dictionary_.getWordCount(); }
  int nodeCount() { return dictionary_.getNodeCount(); }
  void suggest(string input, int num);
  
 protected:
  trie dictionary_;
  
  void suggestHelper(trieNode* in, int &i);
};

#endif
