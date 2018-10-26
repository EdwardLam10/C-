#ifndef Process_H
#define Process_H

#include <string>
#include <iostream>

using namespace std;

struct ProgramControlBlock {
	int priority_;
	int PID_;
};

class Process {
 public:
 	void operator=(Process lhs) {
 		PCB.priority_ = lhs.getPriority();
 		PCB.PID_ = lhs.getPID();
 	}

 	Process(int priority, int PID) : PCB{.priority_ = priority, .PID_ = PID} {}
 	int getPriority() const { return PCB.priority_; }
 	int getPID() const { return PCB.PID_; }

 	void print() const {
 		cout << "Priority: " << PCB.priority_ << endl;
 		cout << "PID: " << PCB.PID_ << endl;
  }

 private:
 	ProgramControlBlock PCB;

};

#endif