/***************************************************************
Title: trieNode.h
Author: Edward Lam
Date Created: 5/07/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Assignment #3
Description: Header file for the trieNode class, contains
everything that accesses a the contents of a node.
***************************************************************/

#ifndef TRIENODE_H
#define TRIENODE_H

#include <map>
#include <iostream>

class trieNode
{
 public:
  //Setters and getters for protected info.
  void setData(char data) { data_ = data; }     
  char getData() { return data_; }
  trieNode* getNext(char a) { return &next_[a]; }      
  void setPrev( trieNode* in ) { prev_ = in; }
  trieNode* getPrev() { return prev_; }
  void setWord(bool value);
  bool getWord() { return isWord_; }                        
  
  bool insert(char a);
  bool contains(char a);
  
  bool isEmpty() { return next_.empty(); } 
  void clear() { next_.clear(); }
  void remove(char a) { next_.erase(a); }
  
 protected:
  std::map<char, trieNode> next_;
  trieNode* prev_;
  char data_;
  bool isWord_ = false;
};

#endif
