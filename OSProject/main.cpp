#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include "Process.h"
#include "CPU.h"
#include "HDD.h"
#include "MMU.h"
#include "RAM.h"

using namespace std;

//Custom Comparator for Scheduler 
//**Sorts the Priority Queue to move highest priority value to the top**
struct comparator {
	bool operator()(Process lhs, Process rhs) {
		return lhs.getPriority() < rhs.getPriority();
	}
};

void printHelp();
void printR(priority_queue<Process, vector<Process>, comparator> tmpQ, CPU tmpCPU);

int main(int argc, char **argv) {
	if(argc != 4) {
		cout << "Incorrect usage!" << endl;
		cout << "Usage: " << "make run " << " ram=<RAM> page=<Page> hdd=<HDD> " << endl;
		cout << "Note that make file instructions are case and space sensitive! No space between '='!" << endl;
		return 0;
	}

	//Initializations
	const int RAMSize = atoi(argv[1]);
	const int PageSize = atoi(argv[2]);
	const int HDDNum = atoi(argv[3]);

	int PID = 1;
	int TIMESTAMP = 1;
	priority_queue<Process, vector<Process>, comparator> scheduler_;
	CPU cpu_;
	//HDD objects bundled with their respective I/O queues in an array of pairs.
	pair<HDD, queue<pair<Process,string>>> HardDrive[HDDNum];
	MMU TLB;
	RAM Memory(RAMSize, PageSize);

	//Main Menu
	printHelp();
	string input = "A"; //Random String to allow access into while loop
	while(input != "end") {
		getline(cin, input);
		//Add Process
		if(input.front() == 'A') {
			input.erase(0,2);
			Process tmp(stoi(input),PID++);
			//Memory Allocation for new Process.
			int openFrame = Memory.lowestOpenFrame();
			if(openFrame == -1) {
				cout << "There is not enough RAM to begin this process." << endl;
			} else {
				FTRow tmpRow{.frame_ = openFrame, .page_ = 0, .PID_ =tmp.getPID(), .timeStamp_ = TIMESTAMP++};
				//Checking if TLB is full. Swap least recently used if TLB is full.
				if(TLB.isFull()) {
					Memory.push(*TLB.getLeastRecent());
					TLB.replace(tmpRow);
				} else {
					TLB.push(tmpRow);
				}
				Memory.pushProcess(openFrame);
				//Determining where the process will go; CPU or CPU Scheduler
				if(cpu_.empty()) {
					cpu_.push(tmp);
					cout << "New Process is now using the CPU" << endl;
				} else if(tmp.getPriority() > cpu_.getCurrent()->getPriority()) {
					Process tmp2(cpu_.getCurrent()->getPriority(),cpu_.getCurrent()->getPID());
					cpu_.push(tmp);
					scheduler_.push(tmp2);
					cout << "Process that was using the CPU has been preempted" << endl;
				} else {
					scheduler_.push(tmp);
					cout << "Process has been added to the CPU Scheduler" << endl;
				}
			}

		//Terminate Process
		} else if(input.front() == 't') {
			if(cpu_.empty()) {
				cout << "There is no process using the CPU to be terminated." << endl;
			} else {
				//Deallocating the memory used by process.
				queue<int> framesToRemove = TLB.remove(cpu_.getCurrent()->getPID());
				Memory.remove(cpu_.getCurrent()->getPID());
				while(!framesToRemove.empty()) {
					Memory.free(framesToRemove.front());
					framesToRemove.pop();
				}
				//Removing the process from CPU and allowing next process in CPU scheduler to use CPU
				cpu_.clear();
				cout << "Process that was using the CPU has been terminated." << endl;
				//To avoid segmentation faults in case the CPU scheduler is empty.
				if(!scheduler_.empty()) {
					cpu_.push(scheduler_.top());
					cout << "Next Process in CPU Scheduler is now using the CPU." << endl;
					scheduler_.pop();
				}
			}

		//Requesting HDD and I/O
		} else if(input.front() == 'd') {
			if(cpu_.empty()) {
				cout << "There is currently no process using the CPU." << endl;
			} else {
				input.erase(0,2);
				//Extracting HDD number and I/O File Name from input
				int HardDriveNum = stoi(input.substr(0,input.find(" ")));
				input.erase(0,input.find(" ") + 1);
				string IOFile = input;
				//Checks if the requested HDD is currently performing I/O for another Process
				//Decrement HardDrive Number since HDD's start at 0
				if((HardDriveNum < 0) || (HardDriveNum > HDDNum - 1)) {
					cout << "That Hard Drive Number does not exist." << endl;
				} else {
					//Checks if the Requested HDD is currently being used
					if(HardDrive[HardDriveNum].first.empty()) {
						HardDrive[HardDriveNum].first.push(*cpu_.getCurrent(), IOFile);
						cout << "Process is now using HDD" << HardDriveNum << "." << endl;
					} else {
						pair<Process, string> IOBundle(*cpu_.getCurrent(), IOFile);
						HardDrive[HardDriveNum].second.push(IOBundle);
						cout << "Process has been inserted into HDD" << HardDriveNum << "'s I/O Queue." << endl;
					}
					//Removing the Process from CPU and adding the next process in Scheduler if there is one
					cpu_.clear();
					//To avoid Segmentation faults if the scheduler is empty.
					if(!scheduler_.empty()) {
						cpu_.push(scheduler_.top());
						scheduler_.pop();
					}
				}
			}

		//Finishing Process using HDD and allow next Process in I/O queue to use its requested HDD
		} else if(input.front() == 'D') {
			input.erase(0,2);
			int HardDriveNum = stoi(input);
			//Avoiding Segmentation Faults
			if ((HardDriveNum < 0) || (HardDriveNum > HDDNum - 1)) {
				cout << "That Hard Drive Number does not exist." << endl;
			//If the Requested HDD is not currently not doing anything
			} else if (HardDrive[HardDriveNum].first.empty()) {
				cout << "That Hard Drive is not doing anything." << endl;
			} else {
				//Returning the Process to CPU scheduler
				scheduler_.push(*HardDrive[HardDriveNum].first.getCurrent());
				HardDrive[HardDriveNum].first.clear();
				//Allowing the next Processs in the I/O queue to use the HDD and I/O devices
				HardDrive[HardDriveNum].first.push(HardDrive[HardDriveNum].second.front().first, HardDrive[HardDriveNum].second.front().second);
				HardDrive[HardDriveNum].second.pop();
			}

		//Request Memory Operation
		} else if(input.front() == 'm') {
			if(cpu_.empty()) {
				cout << "There is currently no process using the CPU." << endl;
			} else {
				input.erase(0,2);
				int address = stoi(input);
				FTRow tmp{.frame_ = 0, .page_ = address/PageSize, .PID_ = cpu_.getCurrent()->getPID(), .timeStamp_ = 0};
				cout << tmp.page_ << endl;
				int temp = TLB.find(tmp);
				//Checks if Process was found in TLB
				if(temp != -1) {
					TLB.renew(temp, ++TIMESTAMP);
				//If Process wasn't found in TLB
				} else {
					if(Memory.find(tmp)) {
						FTRow tmp2 = Memory.getFTRow(tmp);
						//Changing timestamp on Process and moving to TLB
						tmp2.timeStamp_ = ++TIMESTAMP;
						if(TLB.isFull()) {
							Memory.push(*TLB.getLeastRecent());
							TLB.push(tmp2);
						} else {
							TLB.push(tmp2);
						}
					} else {
						tmp.frame_ = Memory.lowestOpenFrame();
						tmp.timeStamp_ = ++TIMESTAMP;
						if(TLB.isFull()) {
							Memory.push(*TLB.getLeastRecent());
							TLB.push(tmp);
						} else {
							TLB.push(tmp);
						}
					}
				}
			}

		//Show functions
		} else if(input.front() == 'S') {
			input.erase(0,2);
			//Show CPU Scheduler and CPU
			if(input == "r") {
				printR(scheduler_, cpu_);
			//Show Hard Drive states and their I/O Queues
			} else if(input == "i") {
				for(int i = 0; i < HDDNum; i++) {
					cout << "Hard Drive " << i << ": ";
					if(HardDrive[i].first.empty()) {
						cout << "Currently not in use." << endl;
					} else {
						cout << " PID: " << HardDrive[i].first.getCurrent()->getPID() << " - Opened File: " << HardDrive[i].first.getOpenedFile() << endl;
						if(!HardDrive[i].second.empty()) {
							queue<pair<Process,string>> tmp = HardDrive[i].second;
							cout << "I/O Queue for HDD" << i << ": " << endl;
							while(!tmp.empty()) {
								int x = 1;
								cout << x++ << ") PID: " << tmp.front().first.getPID() << " - File to Open: " << tmp.front().second << endl;
								tmp.pop();
								}
						}
					}
				}
			//Show RAM and Frames/Pages
			} else if(input == "m") {
				cout << "In TLB: " << endl;
				TLB.print();
				cout << "In RAM: " << endl;
				Memory.print();
			} else {
				cout << "Invalid Input!" << endl;
			}
		} else if(input == "end") {
		} else {
			cout << "Invalid Input!" << endl;
		}
	}

	return 0;
};

void printHelp() {
	cout << "Please enter one of the commands below:" << endl;
	cout << "A priority             | creates a new process with priority 'priority'." << endl;
	cout << "t                      | Terminates the current process using the CPU." << endl;
	cout << "d number File Name     | The process in the CPU requess hard disk 'number' and read or write to file 'File Name'." << endl;
	cout << "D number               | The hard disk 'number' has finished the work for one process." << endl;
	cout << "m address              | The process that currently uses the CPU requests a memory operation for the address 'address'." << endl;
	cout << "S r                    | Shows what process is currently using the CPU and the ready Queue." << endl;
	cout << "S i                    | Shows the state of the hard disks and I/O queue." << endl;
	cout << "S m                    | Shows the stae of memory" << endl;
	cout << "end                    | Ends the program." << endl;
	cout << "Please note that the commands are case sensitive!" << endl;
};

void printR(priority_queue<Process, vector<Process>, comparator> inQ, CPU inCPU) {
	if(inCPU.empty()) {
		cout << "No Process is using the CPU" << endl;
	} else {
		cout << "Currently using CPU: " << endl;
		cout << "CPU) PID: " << inCPU.getCurrent()->getPID() << " - Priority: " << inCPU.getCurrent()->getPriority() << endl;
		cout << "CPU Scheduler: " << endl;
		int counter = 1;
		priority_queue<Process, vector<Process>, comparator> tmp = inQ;
		while(!tmp.empty()) {
			cout << counter++ << ") PID: " << tmp.top().getPID() << " - Priority: " << tmp.top().getPriority() << endl;
			tmp.pop();
		}
	}
};
