#ifndef RAM_H
#define RAM_H

#include <iostream>
#include <vector>
#include "MMU.h"

using namespace std;

struct frames {
	bool occupied = false;
};

class RAM {
 public:
 	RAM(int ramSize, int pageSize) : Memory{ramSize/pageSize} {};

 	int lowestOpenFrame() {
 		for(int i = 0; i < Memory.size(); i++) {
 			if(Memory[i].occupied == false) {
 				return i;
 			}
 		}
 		return -1;
 	}

 	void pushProcess(int frame) {
 		Memory[frame].occupied = true;
 	}

 	bool remove(int pid) {
 		for(int i = 0; i < unusedRows.size(); i++) {
 			if(unusedRows[i].PID_ == pid) {
 				Memory[unusedRows[i].frame_].occupied = false;
 				unusedRows.erase(unusedRows.begin() + i);
 			}
 		}
 	}

 	bool find(FTRow lhs) {
 		for(int i = 0; i < unusedRows.size(); i++) {
 			if(unusedRows[i] == lhs) {
 				return true;
 			}
 		}
 		return false;
 	}

 	FTRow getFTRow(FTRow lhs) {
 		for(int i = 0; i < unusedRows.size(); i++) {
 			if(unusedRows[i] == lhs) {
 				return unusedRows[i];
 			}
 		} 		
 	}

 	void print() {
 		cout << "Frame  Page  PID" << endl;
 		for(int i = 0; i < unusedRows.size(); i++) {
 			unusedRows[i].print();
 		}
 	}


 	void free(int frame) { Memory[frame].occupied = true; }
	void push(FTRow tmp) { unusedRows.push_back(tmp); }

 private:
 	vector<frames> Memory;
 	vector<FTRow> unusedRows;
};

#endif