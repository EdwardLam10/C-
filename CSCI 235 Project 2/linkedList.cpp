/***************************************************************
Title: linkedList.cpp
Author: Edward Lam
Date Created: 03/13/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Assignment #2
Description: The .cpp file for the linkedList class, contains all
             the definitions for linkedList functions.
***************************************************************/

#include <iostream>
#include <string>
#include <fstream>

#include "date.h"
#include "generic.h"
#include "event.h"
#include "homework.h"
#include "linkedList.h"
#include "shopping.h"

using namespace std;

template<class T>
linkedList<T>::linkedList() {
  head_ = nullptr;
  size_ = 0;
  completedTasks_ = 0;
}

template<class T>
linkedList<T>::~linkedList() {  //removeAll and the destructor basically do the same thing.
  removeAll();
}

//makeTask function will take in a string, usually from a file and will parse it into the
//various parts that can make the task object.
template<class T>
void linkedList<T>::makeTask(string task) {
  string dateStr, descStr, locStr, timeStr, subjStr;
  char type = task[0];
  string delimiter = "|";
  task.erase(0, 2);
  dateStr = task.substr(0, task.find(delimiter));
  task.erase(0, dateStr.length() + 1);
  
  if(type == 'G') {
  	insertGeneric(dateStr, task);
  	
  } else if (type == 'E') {
  	descStr = task.substr(0, task.find(delimiter));
  	task.erase(0, descStr.length() + 1);
  	locStr = task.substr(0, task.find(delimiter));
  	task.erase(0, locStr.length() + 1);
    insertEvent(dateStr, descStr, locStr, task);
    
  } else if (type == 'H') {
  	descStr = task.substr(0, task.find(delimiter));
  	task.erase(0, descStr.length() + 1);
  	insertHomework(dateStr, descStr, task);
  	
  } else if (type == 'S') {
  	descStr = task.substr(0, task.find(delimiter));
  	task.erase(0, descStr.length() + 1);
  	vector<string> autoList;
  	while(task.find(delimiter) != std::string::npos) {
  	  string temp;
	  temp = task.substr(0,task.find(delimiter));
	  task.erase(0, temp.length() +1);	
	  autoList.push_back(temp);
	}
	autoList.push_back(task);
	autoShopping(dateStr, descStr, autoList);
  }
}

//Creates a generic task and passes it through the sorted insert function.
template<class T>
void linkedList<T>::insertGeneric(string dateStr, string descStr) {
  node<generic*> *newTask = new node<generic*>;
  newTask->task_ = new generic(dateStr, descStr);
  sortedInsert(newTask);
}

//Creates a shopping task and passes it through the sorted insert function.
template<class T>
void linkedList<T>::insertShopping(string dateStr, string descStr) {
  node<generic*> *newTask = new node<generic*>;
  newTask->task_ = new shopping(dateStr, descStr);
  sortedInsert(newTask);
}

//autoShopping calls the overloaded shopping constructor for loading from files.
template<class T>
void linkedList<T>::autoShopping(string dateStr, string descStr, vector<string> rhs) {
  node<generic*> *newTask = new node<generic*>;
  newTask->task_ = new shopping(dateStr, descStr, rhs);
  sortedInsert(newTask);
}

//Creates an event task and passes it through the sorted insert function.
template<class T>
void linkedList<T>::insertEvent(string dateStr, string descStr, string locStr, string timeStr) {
  node<generic*> *newTask = new node<generic*>;
  newTask->task_ = new event(dateStr, descStr, locStr, timeStr);
  sortedInsert(newTask);
}

//Creates a homework task and passes it through the sorted insert function.
template<class T>
void linkedList<T>::insertHomework(string dateStr, string descStr, string subjStr) {
  node<generic*> *newTask = new node<generic*>;
  newTask->task_ = new homework(dateStr, descStr, subjStr);
  sortedInsert(newTask);
}

//removes a task from the linked list
template<class T>
void linkedList<T>::removeTask(int pos) {
  node<generic*> *current = head_;
  
  //if removing from head
  if (size_ == 1) { 
  	delete current;
  	size_ -= 1;

  //if removing from tail
  } else if (pos == size_) { 
    while(current->next_ != nullptr) {
      current = current->next_;
      current->prev_->next_ = nullptr;
	}
	delete current;
    size_ -= 1;
    
  //removing from the middle of the list
  } else {
    for (int i = 1; i != pos; i++) {
  	  current = current->next_;
    }
    node<generic*> *front = current->next_;
    node<generic*> *back = current->prev_;
    front->prev_ = back;
    back->next_ = front;
    delete current;
    size_ -= 1;
  }
}

//Simple function that calls the remove function on the first task until the list is empty
template<class T>
void linkedList<T>::removeAll() {
  while(size_ > 0) {
  	removeTask(1);
  }
  head_ = nullptr;
  size_ = 0;
  completedTasks_ = 0;
}

//sortedInsert takes in a task 'sortedTask' and will insert it while sorting.
template<class T>
void linkedList<T>::sortedInsert(node<generic*> *sortedTask) {
	
  //pushfront
  if (size_ == 0) {
  	head_ = sortedTask;
  	size_ += 1;
  } else {
    node<generic*> *current = head_;
    
    //Traverses list until last node
	while (current->next_ != nullptr) {
	  if(isLessThan(sortedTask, current)) {
	  	
	  	// if pushing to before the head
	    if(current == head_) {
	      sortedTask->next_ = current;
	      current->prev_ = sortedTask;
	      head_ = sortedTask;
	      size_ += 1;
	      break;
	      
	    //pushing to before any other node
		} else {
		  sortedTask->next_ = current;
		  sortedTask->prev_ = current->prev_;
		  current->prev_->next_ = sortedTask;
		  current->prev_ = sortedTask;
		  size_ += 1;
		  break;
		}
	  } else {
	    current = current->next_;	
	  }
	}
	
	//If inserting to the end of the list
	if(current->next_ == nullptr) {
	  if(isLessThan(sortedTask, current)) {
	  	
	  	//if the end of the list is the head i.e. - there is only one task
	  	if(current == head_) {
	  	  sortedTask->next_ = current;
	      current->prev_ = sortedTask;
	      head_ = sortedTask;
	      size_ += 1;
		  
		//if sortedTask goes right before the tail task	
		} else { 
		  sortedTask->next_ = current;
		  sortedTask->prev_ = current->prev_;
		  current->prev_->next_ = sortedTask;
		  current->prev_ = sortedTask;
		  size_ += 1;
		}
	
	  //inserting after the tail, or making a new tail
	  } else {
	  	current->next_ = sortedTask;
	  	sortedTask->prev_ = current;
	  	size_ += 1;
	  }
	}	
  } 
}

//isLessThan is a helper task for the sortedInsert function that takes in 2 nodes and compares them
//returns true if the left node is smaller than the right node.
template<class T>
bool linkedList<T>::isLessThan(node<generic*> *lhs, node<generic*> *rhs) {
  if(lhs->task_->getDate()->getYear() < rhs->task_->getDate()->getYear()) {
    return true;
  } else if (lhs->task_->getDate()->getYear() == rhs->task_->getDate()->getYear()) {
    if (lhs->task_->getDate()->getMonth() < rhs->task_->getDate()->getMonth()) {
      return true;	
	} else if (lhs->task_->getDate()->getMonth() == rhs->task_->getDate()->getMonth()) {
	  if (lhs->task_->getDate()->getDay() < rhs->task_->getDate()->getDay()) {
	  	return true;
	  } else if (lhs->task_->getDate()->getDay() == lhs->task_->getDate()->getDay()) {
	    return false;
	  }
	}
  } else {
  	return false;
  }
}

//Prints the tasks regularly
template<class T>
void linkedList<T>::printTask() {
  node<generic*> *current = head_;
  int i = 1;
  while (current != nullptr) {
  	cout << i << ". ";
	current->task_->printTask();	
	current = current->next_;
	i++;
  }
}

//Prints the tasks with details
template<class T>
void linkedList<T>::printDetail() {
  node<generic*> *current = head_;
  int i = 1;
  while (current != nullptr) {
    cout << i << ". ";
    current->task_->printDetail();
    current = current->next_;	
    i++;
  }
}

//Prints only the completed tasks
template<class T>
void linkedList<T>::printCompleted() {
  if(completedTasks_ == 0) {
  	cout << "You have no outstanding tasks!" << endl;
  } else {
    for(node<generic*> *current = head_; current != nullptr; current = current->next_) {
      current->task_->printCompleted();
	}
  }
}

//takes in a position on the linked list and will mark the task as complete
template<class T>
void linkedList<T>::completeTask(int pos) {
  node<generic*> *current = head_;
  for (int i = 1; i != pos; i++) {
  	current = current->next_;
  }
  current->task_->completeTask();
  completedTasks_ += 1;
}

//basic get function for size_
template<class T>
int linkedList<T>::getSize() {
  return size_;
}

//saves the list onto a file, I included the save function in the linkedList class 
//for easier access to each node.
template<class T>
void linkedList<T>::saveList() {
  if (size_ == 0) {
  	cout << "You have no outstanding tasks!" << endl;
  }
  string fileName;
  ofstream saveFile;
  cout << "Where would you like to save your oustanding tasks?" << endl;
  getline(cin, fileName);
  saveFile.open(fileName);
  for(node<generic*> *current = head_; current != nullptr; current = current->next_) {
    saveFile << current->task_->makeString() << endl;
  }  
  saveFile.close();
  cout << "Tasks saved successfully!" << endl;
}

