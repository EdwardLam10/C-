/***************************************************************
Title: trieNode.cpp
Author: Edward Lam
Date Created: 5/07/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Assignment #3
Description: definitions for functions prototyped in trieNode.h
***************************************************************/

#include "trieNode.h"

void trieNode::setWord(bool value) {
  if(value == true) {
  	isWord_ = true;
  } else {
  	isWord_ = false;
  }
}

bool trieNode::insert(char a) {
  if(contains(a)) {
  	return false;
  } else {
  	trieNode newNode;
  	newNode.setData(a);
  	newNode.setPrev(this);
  	next_[a] = newNode;
  	return true;
  }
}

bool trieNode::contains(char a) {
  std::map<char, trieNode>::iterator it;
  it = next_.find(a);
  if (it == next_.end()) {
  	return false;
  } else {
  	return true;
  }
}

