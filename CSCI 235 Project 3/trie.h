/***************************************************************
Title: trie.h
Author: Edward Lam
Date Created: 5/07/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Assignment #3
Description: header file for the trie class, used for managing 
all the nodes and their data.
***************************************************************/

#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <iostream>
#include <stack>

#include "trieNode.h"

using namespace std;

class trie
{
 public:
  ~trie() { clear(); }
  int getWordCount() { return wordCount_; }
  int getNodeCount(); 
  trieNode* getHead() { return &head_; } 
  
  void insert(string word);
  bool contains(string word);
  bool remove(string word);
  void clear();
  
  bool isEmpty(); 
  trieNode* getNode(string word);
  string makeWord(trieNode* in);
  
 protected:
  trieNode head_;
  int wordCount_ = 0;
  int nodeCount_ = 0;
  
  string lowerCase(string word);
  int nodeCountHelper(trieNode *in);
  void clearHelper(trieNode *in);
  string flip(string word);
};

#endif
