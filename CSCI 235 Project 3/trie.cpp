/***************************************************************
Title: trie.cpp
Author: Edward Lam
Date Created: 5/07/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Assignment #3
Description: .cpp file for trie class.
***************************************************************/

#include "trie.h"

int trie::getNodeCount() {
  return nodeCountHelper(&head_);
}


//insert words into trie 
void trie::insert(string word) {
  word = lowerCase(word);
  trieNode* trav = &head_;
  int i = 0;
  while (i < word.length()) {
	while(trav->contains(word[i])) {
	  trav = trav->getNext(word[i]);
	  i++;
	} 
	trav->insert(word[i]);
	if(trav->getWord()) {
	}
  }
  trav->setWord(true);
  wordCount_ += 1;
}

//Checks if the string is in the trie
bool trie::contains(string word) {
  word = lowerCase(word);
  trieNode *trav = &head_;
  for(int i = 0; i < word.length(); i++) {
  	trav = trav->getNext(word[i]);
    if(trav->getData() != word[i]) {
      return false;
	}
  }
  return true;
}

//soft remove
bool trie::remove(string word) {
  word = lowerCase(word);
  if(contains(word)) {
  	trieNode* trav = &head_;
  	for(int i = 0; i < word.length(); i++) {
  	  trav = trav->getNext(word[i]);
    }
    trav->setWord(false);
    wordCount_ -= 1;
    return true;
  } else {
  	return false;
  }
}

void trie::clear() {
  	clearHelper(&head_);
  	head_.clear();
  	wordCount_ = 0;
}

bool trie::isEmpty() {
  if(getNodeCount() == 0) {
  	return true;
  } else {
  	return false;
  }
}

//takes in the string as a parameter,
//and returns the address of the last letter in the string.
trieNode* trie::getNode(string word) {
  trieNode* trav = &head_;
  for(int i = 0; i < word.length(); i++) {
  	trav = trav->getNext(word[i]);
  }
  return trav;
}

//takes in the address of a trieNode, 
//and goes up the trie collecting the data to create a word.
string trie::makeWord(trieNode* in) {
  trieNode* trav = in;
  string word;
  while(trav->getPrev() != &head_) {
  	word += trav->getData();
  	trav = trav->getPrev();
  }
  word += trav->getData();
  word = flip(word);
  return word;
}

string trie::lowerCase(string word) {
  for(int i = 0; i < word.length(); i++) {
    word[i] = tolower(word[i]);
  }
  return word;
}

//Recursive counter, base case is when the trieNode has no children
//anything else will call nodeCountHelper on all the children.
int trie::nodeCountHelper(trieNode *in) {
  trieNode* trav = in;
  if(trav->isEmpty()) {
  	return 0;
  } else {
  	int nodeCount = 0;
  	for(char counter = 'a'; counter != '{'; counter++) {
	  if(trav->contains(counter)) {
	  	nodeCount = nodeCount + 1 + nodeCountHelper(trav->getNext(counter));
	  }	
	}
	return nodeCount;
  }
}

//hard remove
void trie::clearHelper(trieNode* in) {
  trieNode* trav = in;
  for(char counter = 'a'; counter != '{'; counter++) {
  	if(trav->getNext(counter)->isEmpty()) {
  	  trav->remove(counter);	
	} else {
	  clearHelper(trav->getNext(counter));
	}
  }
}

//flips a string ex. add -> dda
string trie::flip(string word) {
  stack<char> tempQ;
  string temp;
  for(int i = 0; i < word.length(); i++) {
  	tempQ.push(word[i]);
  }
  while(!tempQ.empty()) {
  	temp += tempQ.top();
  	tempQ.pop();
  }
  return temp;
}

