#ifndef GRAPHS_H
#define GRAPHS_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

struct vertexs {
	int vertex_ = 99999;
	vector<pair<int,double>> adjacents;
	bool operator>(const vertexs other) {
		return vertex_ > other.vertex_;
	}
};

struct DijkstraRow {
	int vertex_;
	double weight_;
	int prev_ = 0;
	bool visited_ = false;
};

struct comparator {
	bool operator()(DijkstraRow* lhs, DijkstraRow* rhs) {
		return lhs->weight_ > rhs->weight_;
	}
};

class graphs {
 public:
 	//Not much going on, just calling internal methods
	bool insertVertex(string VertexString) {
		vector<string> parsedString = stringParser(VertexString, " ");
		//tests if the vertex is already in the graph
		if(contains(stoi(parsedString[0]))) { return false; }
		vertexs tmp = vertexCreator(parsedString);
		graph_.push_back(tmp);
		//sorting the vector of graph to make accessing data easier
		sort();
	}

	//checks if the graph contains vertex
	bool contains(int vertex) {
		for(int i = 0; i < graph_.size(); i++) {
			if(graph_[i].vertex_ == vertex) {
				return true;
			}
		}
		return false;
	}


	//If num1 and num2 are both vertexs, check will check if num2 is connected to num1 and will output the weight
	//of the connection if it is. check() assumes that the graphs.txt data is not sorted when given.
	bool check(int num1, int num2) {
		for(int i = 0; i < graph_.size(); i++) {
			if(graph_[i].vertex_ == num1) {
				for(int j = 0; j < graph_[i].adjacents.size(); j++) {
					if(graph_[i].adjacents[j].first == num2) {
						cout << num1 << " " << num2 << ": Connected, weight of edge is " << graph_[i].adjacents[j].second << endl;
						return true;
					}
				}
			}
		}
		cout << num1 << " " << num2 << ": Not connected" << endl;
		return false;
	}

	//Creates the Dijkstra Chart
	bool makeDijkstraChart(int startingVertex) {
		if(!contains(startingVertex)) {
			cout << startingVertex << " was not found on the graph." << endl;
			return false;
		}
		vector<DijkstraRow> tempVec;
		//Initialize the dQ first and second column (vertex and weight)
		for(int i = 0; i < graph_.size(); i++) {
			DijkstraRow tmp;
			tmp.prev_ = 0;
			tmp.vertex_ = i + 1;
			if(i+1 == startingVertex) {
				tmp.weight_ = 0.0;
			} else {
				tmp.weight_ = 999.9;
			}
			tempVec.push_back(tmp);
		}
		for (int i = 0; i < graph_.size(); i++) {
			DijkstraQ.push(&tempVec[i]);
			DQAddress.push_back(&tempVec[i]);
		}
		//Getting the row that we start Dijkstra's algorithm on
		DijkstraRow *DQRow = DQAddress[startingVertex-1];
		DQRow->weight_ = 0.0;
		Dijkstra();
		displayPath(startingVertex);
		return true;
	}

	// void printDijkstraChart() {
	// 	if(DQAddress.size() == 0) {
	// 		cout << "empty" << endl;
	// 	}
	// 	for(int i = 0; i < DQAddress.size(); i++) {
	// 		DijkstraRow *tmp = DQAddress[i];
	// 		cout << tmp->vertex_ << " = vertex" << endl;
	// 		cout << tmp->weight_ << " = weight" << endl;
	// 		cout << tmp->prev_ << " = prev" << endl;
	// 		cout << "-------------------------" << endl;
	// 		DijkstraRow tmp1 = *DijkstraQ.top();
	// 		DijkstraQ.pop();
	// 		cout << "pQ: " << endl;
	// 		cout << tmp1.vertex_ << "= vertex" << endl;
	// 		cout << tmp1.weight_ << "= weight" << endl;
	// 		cout << tmp1.prev_ << "= prev" << endl;
	// 		cout << "==========================" << endl;
	// 	}
	// }

	vector<vertexs>* getGraph() { return &graph_; }

 private:
	vector<vertexs> graph_;
	priority_queue<DijkstraRow*,vector<DijkstraRow*>,comparator> DijkstraQ;
 	vector<DijkstraRow*> DQAddress;

	//internal method stringParser parses the string of ints and doubles into a vector of strings contains the ints and doubles as strings
	vector<string> stringParser(string stringToParse, string delimiter) {
		vector<string> returnVec;
		//this while loop deletes the last space in every string if there is one. Done to have some level of consistency in the strings
		while(stringToParse.back() == ' ') { stringToParse.pop_back(); }
		string tmp = stringToParse.substr(0,stringToParse.find(delimiter));
		returnVec.push_back(tmp);
		stringToParse.erase(0,stringToParse.find(delimiter));
		//Parsing the strings
		while(stringToParse.length() > 0) {
			stringToParse.erase(0,1);
			string tmp = stringToParse.substr(0,stringToParse.find(delimiter));
			returnVec.push_back(tmp);
			stringToParse.erase(0,stringToParse.find(delimiter));
		}
		return returnVec;
	}	

	//Given the vector of ints and doubles as strings from stringParser; converts them into their respective data types and adds
	//them into a temperary struct to be returned and later push into the vector of vertexes.
	vertexs vertexCreator(vector<string> parsedVector) {
		vertexs tmp;
		pair<int,double> pairTmp;
		tmp.vertex_ = stoi(parsedVector[0]);
		for(int i = 1; i < parsedVector.size(); i++) {
			pairTmp.first = stoi(parsedVector[i]);
			pairTmp.second = stod(parsedVector[++i]);
			tmp.adjacents.push_back(pairTmp);
		}
		return tmp;
	}

	//sorts the data so that smallest vertex will go first in the vector
	void sort() {
		for(int i = 0; i < graph_.size()-1; i++) {
			if(graph_[i].vertex_ > graph_[i+1].vertex_) {
				graph_[i].adjacents.swap(graph_[i+1].adjacents);
				std::swap(graph_[i].vertex_,graph_[i+1].vertex_);
			}
		}
	}

	//Recursive Dijkstra function that will keep calling itself and finding shortest paths
	//until there are no more unvisisted vertexs.
	bool Dijkstra() {
		if(DijkstraQ.empty()) { return true; }
		DijkstraRow *current = DijkstraQ.top();
		for(int i = 0; i < graph_[current->vertex_ - 1].adjacents.size(); i++) {
			DijkstraRow *tmp = DQAddress[graph_[current->vertex_ - 1].adjacents[i].first - 1];
			if(current->weight_ + graph_[current->vertex_ - 1].adjacents[i].second < tmp->weight_) {
				tmp->weight_ = current->weight_ + graph_[current->vertex_ - 1].adjacents[i].second;
				tmp->prev_ = current->vertex_;
			}
		}
		DijkstraQ.pop();
		Dijkstra();
	}

	//Dsiplays the shortest path froim StartingVertex to every other vertex.
	void displayPath(int startingVertex) {
		for(int i = 0; i < DQAddress.size(); i++) {
			DijkstraRow *current = DQAddress[i];
			int cost = current->weight_;
			if(current->vertex_ == startingVertex) {
				cout << startingVertex << ": " << startingVertex << ", " << "cost: 0" << endl;
			} else {
				//Stack was used to reverse the path as well as store the path.
				stack<int> path;
				while(current->vertex_ != startingVertex) {
					path.push(current->vertex_);
					current = DQAddress[current->prev_ - 1];
				}
				cout << startingVertex << ": " << startingVertex << ", ";
				while(!path.empty()) {
					cout << path.top() << ", ";
					path.pop();
				}
				cout << "Cost: " << cost << endl;
			}
		}
	}
};

#endif