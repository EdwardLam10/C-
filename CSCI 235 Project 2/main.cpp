/***************************************************************
Title: main.cpp
Author: Edward Lam
Date Created: 03/13/2017
Class: Spring 2017, CSCI 235-03, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Assignment #2
Description: main.cpp contains the menu for the program.
***************************************************************/

#include <iostream>
#include <fstream>
#include <string>

#include "date.h"
#include "generic.h"
#include "event.h"
#include "homework.h"
#include "shopping.h"
#include "linkedList.cpp"

using namespace std;

int main() {
  
  string input;
  
  string date;
  string description;
  string location;
  string time;
  string subject;
  
  linkedList<generic*> sortedList;
  
  while (input != "EXIT" && input != "Exit" && input != "exit") {
  	
    string inputTask;
  	
    cout << "Hello, welcome to To-Do List, please enter a command" <<
  	"or 'HELP' for a list of acceptable commands" << endl;
  	getline(cin, input);
  	
  	//HELP MENU
  	if (input  == "HELP" || input  == "Help" || input  == "help") {
  		cout << "Acceptable commands are: " << endl;
  		cout << "ADD - Add a new task to your To-Do List" << endl;
  		cout << "PRINT - Prints your To-Do List" << endl;
  		cout << "DETAIL - Prints a detailed version of your To-Do List" << endl;
  		cout << "REMOVE - Removes a task from your To-Do List" << endl;
  		cout << "COMPLETE - Marks one of your tasks as 'COMPLETE'" << endl;
  		cout << "COMPLETED - Prints a list of your completed tasks" << endl;
  		cout << "SAVE - Saves your current To-Do List" << endl;
  		cout << "LOAD - Loads a To-Do List from your files" << endl;
  		cout << "EXIT - Exits the program" << endl;
  	
	//ADD A TASK	
	} else if (input == "ADD" || input == "Add" || input == "add") {
	  while (inputTask != "G" && inputTask != "S" && inputTask != "E" && inputTask != "H") {
	  	cout << "What type of task is this? [G: Generic, S: Shopping, E: Event, H: Homework]" << endl;
	  	getline(cin, inputTask);
	  	
	  	//Add Generic Task
	  	if (inputTask == "G") {
	  	  cout << "When is this task due?" << endl;
	  	  getline(cin, date);
	  	  cout << "How would you describe this task?" << endl;
	  	  getline(cin, description);
	  	  sortedList.insertGeneric(date, description);
	  	  cout << "Task added successfully." << endl;
	  	  
	  	//Add Shopping Task
		} else if (inputTask == "S") {
		  cout << "When is this task due?" << endl;
	  	  getline(cin, date);
		  cout << "How would you describe this task?" << endl;
	  	  getline(cin, description);
		  sortedList.insertShopping(date, description);
		  cout << "Task added successfully." << endl;
		
		//Add Event Task
		} else if (inputTask == "E") {
		  cout << "When is this task due?" << endl;
	  	  getline(cin, date);
		  cout << "How would you describe this task?" << endl;
	  	  getline(cin, description);
		  cout << "Where is this event taking place?" << endl;
		  getline(cin, location);
		  cout << "When is this event taking place?" << endl;
		  getline(cin, time);
		  sortedList.insertEvent(date, description, location, time);
		  cout << "Task added successfully." << endl;	
		
		//Add Homework Task  
		} else if (inputTask == "H") {
		  cout << "When is this task due?" << endl;
	  	  getline(cin, date);
		  cout << "How would you describe this task?" << endl;
	  	  getline(cin, description);
		  cout << "Which subject is this homework task for?" << endl;
		  getline(cin, subject);
		  sortedList.insertHomework(date, description, subject);
		  cout << "Task added successfully." << endl;
					  
		} else {
		  cout << "That was an invalid command" << endl;
		}
	}
	
	//PRINT  
    } else if (input == "PRINT" || input == "Print" || input == "print") {
      if(sortedList.getSize() == 0) {
      	cout << "You have no outstanding Tasks!" << endl;
	  } else {
	  	sortedList.printTask();
	  }
	 
	//DETAILED PRINT  	  
	} else if (input == "DETAIL" || input == "Detail" || input == "detail") {
	  if(sortedList.getSize() == 0) {
	  	cout << "You have no outstanding Tasks!" << endl;
	  } else {
	  	sortedList.printDetail();
	  }
	
	//REMOVE A TASK  
	} else if (input == "REMOVE" || input == "Remove" || input == "remove") {
	  if (sortedList.getSize() == 0) {
	    cout << "You have no outstanding tasks!" << endl;	
	  } else {
	  	int removePos;
	  	cout << "Which task would you like to remove?" << endl;
	  	cin >> removePos;
	  	while (removePos < 0 || removePos > sortedList.getSize()) {
	  	  cout << "You have entered an invalid position." << endl;
		  cout << "Please enter a correct position." << endl << endl;
		  sortedList.printTask();
		  cin >> removePos;	
		}
		sortedList.removeTask(removePos);
		cout << "Task removed successfully!" << endl;
	  }
	
	//MARK A TASK AS COMPLETE  
	} else if (input == "COMPLETE" || input == "Complete" || input == "complete") {
	  if (sortedList.getSize() == 0) {
	  	cout << "You have no outstanding tasks!" << endl;
	  } else {
	  	int completePos;
	  	cout << "Which task would you like to complete?" << endl;
	  	cin >> completePos;
	  	while (completePos < 0 || completePos > sortedList.getSize()) {
	  	  cout << "You have entered an invalid position." << endl;
		  cout << "Please enter a correct position." << endl << endl;
		  sortedList.printTask();
		  cin >> completePos;	
		}
		sortedList.completeTask(completePos);
		cout << "Task marked complete successfully." << endl;
	  }
	
	//PRINT COMPLETED TASKS  
	} else if (input == "COMPLETED" || input == "Completed" || input == "completed") {
	  sortedList.printCompleted();
	
	//SAVE TASKS ONTO A FILE  
	} else if (input == "SAVE" || input == "Save" || input == "save") {
	  sortedList.saveList();
	
	//LOADS TASKS FROM A FILE  
	} else if (input == "LOAD" || input == "Load" || input == "load") {
	  string fileName;
	  cout << "What file would you like to load outstanding tasks from? (Note: All existing tasks will be deleted)" << endl;
	  cout << "Enter 'N' to stop" << endl;
	  getline(cin, fileName);
	  if (fileName == "N") {
	  	break;
	  }
	  sortedList.removeAll();
	  string inputTask;
	  ifstream loadFile;
	  loadFile.open(fileName);
	  if(loadFile.fail()) {
	  	cout << "Error occured while loading file." << endl;
	  	break;
	  }
	  while (!loadFile.eof()) {
	  	getline(loadFile, inputTask);
	  	sortedList.makeTask(inputTask);
	  }
	
	//EXIT PROGRAM 
    } else if (input  == "EXIT" || input == "Exit" || input == "exit") {
      cout << "Warning! Any usaved Tasks will be erased, do you still wish to continue? Y/N" << endl;
      char answer;
      cin >> answer;
      cin.ignore();
      while (answer != 'Y' && answer != 'N') {
      	cout << "You have entered an invalid answer, please enter 'Y' or 'N'." << endl;
      	cin >> answer;
      	cin.ignore();
	  }
	  if(answer == 'Y') {
	  	break;
	  } else if (answer == 'N') {
        cout << "Hello, welcome to To-Do List, please enter a command" <<
  	    "or 'HELP' for a list of acceptable commands" << endl;
	  	getline(cin, input);
      }
    
    //INVALID COMMAND
    } else {
    	cout << "You have entered an invalid command, enter a valid " <<
    	"command or type 'HELP' to see a list of valid commands" << endl;
	}
  }
  cout << "Thank you for using To-Do List!" << endl;
}
