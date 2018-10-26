#ifndef CPU_H
#define CPU_H

#include <iostream>
#include "Process.h"

using namespace std;

class CPU {
 public:

 	void push(Process tmp) {
 		Current_ = tmp;
 		isEmpty_ = false;
 	}

 	bool empty() { return isEmpty_; }
 	void clear() { isEmpty_ = true; }
	Process* getCurrent() { return &Current_;	}

	void print() {
		cout << "PID: " << Current_.getPID() << endl;
		cout << "Priority: " << Current_.getPriority() << endl;
	}

 private:
 	Process Current_{0,0};
 	bool isEmpty_ = true;
 	
};

#endif