/***************************************************************
Title: main.cpp
Author: Edward Lam
Date Created: 5/07/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Assignment #3
Description: main.cpp contains the UI.
***************************************************************/

#include <iostream>
#include <assert.h>
#include <map>
#include <string>

#include "dictionary.h"
#include "trieNode.h"
#include "trie.h"

using namespace std;

int main() {
	
string input;
int num;
cout << "Enter the name of your text file." << endl;
getline(cin, input);
dictionary dictionary_(input);
cout << "Number of words added: " << dictionary_.numCount() << endl;
cout << "Number of nodes created: " << dictionary_.nodeCount() << endl;
do{
  cout << "Enter a string to be auto completed." << endl;
  cout << "Or enter 'end program' to leave." << endl;
  getline(cin, input);
  if(input == "end program") {
  	break;
  }
  cout << "Enter Number of suggestions." << endl;
  cin >> num;
  cin.ignore();
  dictionary_.suggest(input, num);
} while (input != "end program");  

}
