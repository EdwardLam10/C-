#ifndef DISJSETS_H
#define DISJSETS_H

#include <iostream>
#include <vector>

using namespace std;

struct vertexs {
	int outDegree = 0;
	bool root = true;

	vector<vertexs*> children;
	vertexs* parent = nullptr;
};

class DisjSets {
 public:
 	DisjSets(int max) : SubsetCount(max) {
 		vertexs tmp;
 		for(int i = 0; i < max; i++) {
 			vertexList.push_back(tmp);
 		}
 	}

 	bool Union(int lhs, int rhs) {
 		//If theyre connected, this edge has already been added.
 		if(!Connected(lhs,rhs)) {
	 		if(vertexList[lhs-1].children.size() < vertexList[rhs-1].children.size()) {
	 			Connect(lhs,rhs);
	 		} else {
	 			Connect(rhs,lhs);
	 		}
	 		if(vertexList[lhs-1].root || vertexList[rhs-1].root) {
	 			SubsetCount--;
	 		}
	 		edgeCount++;
	 		return true;
	 	}
	 	cout << "they werent connected" << endl;
	 	return false;
 	}

 	bool Connected(int lhs, int rhs) {
 		vertexs left = vertexList[lhs-1];
 		vertexs right = vertexList[rhs- 1];
 		if(left.parent == &right || right.parent == &left) { return true; }
 		return false;
 	}

 	int SubsetCounter() {
 		return SubsetCount;
 	}

 	void print() {
 		int total = 0;
 		for(int i = 0; i < vertexList.size(); i++) {
 			if(vertexList[i].outDegree > maxOutDegree) {
 				maxOutDegree = vertexList[i].outDegree;
 				total += vertexList[i].outDegree;
 			} else if (vertexList[i].outDegree < minOutDegree) {
 				minOutDegree = vertexList[i].outDegree;
 				total += vertexList[i].outDegree;
 			}  else {
 				total += vertexList[i].outDegree;
 			}
 		}
 		cout << "Total number of edges: " << edgeCount << endl;
 		cout << "Smallest out-degree for a vertex: " << minOutDegree << endl;
 		cout << "Largest out-degree for a vertex: " << maxOutDegree << endl;
 		cout << "Average out-degree for an edge: " << total/vertexList.size() << endl;
 	}

 private:
 	int maxOutDegree = 0;
 	int minOutDegree = 9999999;
 	int SubsetCount;
 	int edgeCount = 0;
 	vector<vertexs> vertexList;

 	//Connects the lhs and rhs such that the left is the parent of the right.
 	void Connect(int lhs, int rhs) {
	 	vertexList[lhs-1].parent = &vertexList[rhs-1];
		vertexList[rhs-1].children.push_back(&vertexList[lhs-1]);
		vertexList[lhs-1].root = false;
		vertexList[lhs-1].outDegree++;
		vertexList[rhs-1].outDegree++;
 	}
};

#endif