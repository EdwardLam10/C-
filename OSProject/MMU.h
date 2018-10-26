#ifndef MMU_H
#define MMU_H

#include <iostream>
#include <vector>

using namespace std;

struct FTRow { 
	int frame_;
	int page_;
	int PID_;
	int timeStamp_;
	void operator=(FTRow lhs) {
		page_ = lhs.page_;
		PID_ = lhs.PID_;	
	}
	bool operator==(FTRow lhs) {
		return ((page_ == lhs.page_) && (PID_ = lhs.PID_));
	}
	void exchange(FTRow lhs) {
		FTRow tmp;
		tmp = *this;
		*this = lhs;
		lhs = tmp; 
	}
	//REMEMBER TO DELETE THIS!
	void print() {
		cout << "  "<< frame_ << "     " << page_ <<  "     " << PID_<< endl;
	}
};

class MMU {
 public:
 	void replace(FTRow lhs) {
 		FrameTable_[findLeastRecent()].exchange(lhs);
 	}

 	void push(FTRow lhs) {
 		FrameTable_.push_back(lhs);
 	}

 	bool isFull() {
 		if(FrameTable_.size() > FTMax_) {
 			return true;
 		} else {
 			return false;
 		}
 	}

 	queue<int> remove(int pid) {
 		queue<int> framesToFree;
 		for(int i = 0; i < FrameTable_.size(); i++) {
 			if(FrameTable_[i].PID_ == pid){
 				framesToFree.push(FrameTable_[i].frame_);
 				FrameTable_.erase(FrameTable_.begin() + i);
 			}
 		}
 		return framesToFree;
 	}

 	int find(FTRow lhs) {
 		for(int i = 0; i < FrameTable_.size(); i++) {
 			if(FrameTable_[i] == lhs) {
 				return i;
 			}
 		}
 		return -1;
 	}

 	void print() {
 		cout << "Frame  Page  PID" << endl;
 		for(int i = 0; i < FrameTable_.size(); i++) {
 			FrameTable_[i].print();
 		}
 	}

 	void renew(int counter, int newTime) { FrameTable_[counter].timeStamp_ = newTime; }
 	int getSize() { return FrameTable_.size(); }
 	FTRow* getLeastRecent() { return &FrameTable_[findLeastRecent()]; }

 private:
 	vector<FTRow> FrameTable_;
 	int FTMax_ = 4;

 	int findLeastRecent() {
 		int tmp = 9999;
 		int tmpIndex;
 		for(int i = 0; i <= FrameTable_.size(); i++) {
 			if(FrameTable_[i].timeStamp_ < tmp) {
 				tmpIndex = i;
 				tmp = FrameTable_[i].timeStamp_;
 			}
 		}
 		return tmpIndex;
 	}

};

#endif