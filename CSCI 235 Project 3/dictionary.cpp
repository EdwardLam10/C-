/***************************************************************
Title: dictionary.cpp
Author: Edward Lam
Date Created: 5/07/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Assignment #3
Description: .cpp file for dictionary class.
***************************************************************/

#include "dictionary.h"

using namespace std;

//dictionary class constructor
dictionary::dictionary(string input) {
  if(dictionary_.isEmpty()) {
  	load(input);
  } else {
  	dictionary_.clear();
  	load(input);
  }
}

//loads file and inserts evyerthing in the file into the dictionary.
void dictionary::load(string input) {
  ifstream loadFile;
  loadFile.open(input);
  while(!loadFile.eof()) {
  	string word;
  	getline(loadFile, word);
  	dictionary_.insert(word);
  }
}

void dictionary::suggest(string input, int num) {
  if(!dictionary_.contains(input)) {
    cout << input << " was not found in the dictionary." << endl;
  } else {
  	trieNode* trav = dictionary_.getNode(input); //traverse to the node that we need to start at.
  	queue<trieNode*> nodeQ; //Queue needed for level order traversal
  	int wordsPrinted = 0;
  	nodeQ.push(trav);
  	do {
      suggestHelper(nodeQ.front(), wordsPrinted);
      for(char counter = 'a'; counter != '{'; counter++) {
      	if(nodeQ.front()->contains(counter)) {
      	  nodeQ.push(nodeQ.front()->getNext(counter));	
		}
	  }
	  nodeQ.pop();
	  if(nodeQ.empty()) { //If all words have been printed before reaching number of requested words.
	  	break;
	  }
	} while(wordsPrinted < num);
  }
}

//Checks if trieNode contains the end of a word. If it does,
//it will call the makeWord function from the trie class to
//retrieve the word asscociated with that node.
void dictionary::suggestHelper(trieNode* in, int &i) {
  if(in->getWord()) {
  	cout << dictionary_.makeWord(in) << endl;
  	i++;
  }
}

