#ifndef HDD_H
#define HDD_H

#include <iostream>
#include <string>
#include <vector>
#include "Process.h"

using namespace std;

class HDD {
 public:
 	void push(Process tmp, string fileName) {
 		Current_ = tmp;
 		openedFile_ = fileName;
 		isEmpty_ = false;
 	}

 	bool empty() { return isEmpty_; }
 	void clear() { isEmpty_ = true; }
	Process* getCurrent() { return &Current_;	}
	string getOpenedFile() { return openedFile_; }

	void print() {
		cout << "PID: " << Current_.getPID() << endl;
		cout << "Priority: " << Current_.getPriority() << endl;
	}

 private:
 	Process Current_{0,0};
 	bool isEmpty_ = true;
 	string openedFile_;

};

#endif