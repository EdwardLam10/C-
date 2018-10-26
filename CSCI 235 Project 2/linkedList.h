/***************************************************************
Title: linkedList.h
Author: Edward Lam
Date Created: 03/13/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Assignment #2
Description: The header file for the linkedList class.
***************************************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "date.h"
#include "generic.h"
#include "event.h"
#include "homework.h"
#include "shopping.h"

template<typename A>
struct node {
	A task_;
	node* next_ = nullptr;
	node* prev_ = nullptr;
};

template<class T>
class linkedList
{
 public:
  linkedList();
  ~linkedList();
  
  void makeTask(string task);
  void insertGeneric(string dateStr, string descStr);
  void insertShopping(string dateStr, string descStr);
  void autoShopping(string dateStr, string descStr, vector<string> rhs);
  void insertEvent(string dateStr, string descStr, string locStr, string timeStr);
  void insertHomework(string dateStr, string descStr, string subjStr);
  
  void removeTask(int pos);
  void removeAll();
  
  void sortedInsert(node<generic*> *sortedTask); 
  bool isLessThan(node<generic*> *lhs, node<generic*> *rhs); //helper function for sortedInsert
  
  void printTask();
  void printDetail();
  void printCompleted();
  void completeTask(int pos);
  
  int getSize();
  
  void saveList();
  
 protected:
  node<generic*>* head_;
  int size_;
  
  int completedTasks_;
};

#endif

