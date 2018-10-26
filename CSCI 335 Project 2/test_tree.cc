// <Your name>
// Main file for Part2(b) of Homework 2.

#include "AvlTree.h"
#include "BinarySearchTree.h"
#include "SequenceMap.h"

#include <iostream>
#include <string>
#include <fstream>
#include <utility>
using namespace std;

namespace {

// @db_filename: an input database filename.
// @seq_filename: an input sequences filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void TestTree(const string &db_filename, const string &seq_filename, TreeType &a_tree) {
  ifstream dbFile(db_filename);
  //ignoring the header of the text file
  for(int i = 0; i < 10; i++) {
    dbFile.ignore(10000,'\n');
  }

  string an_enz_acro;
  string a_reco_seq;
  string db_string;

  while(getline(dbFile, db_string)) {
    while(db_string.find("//") != string::npos) {
    db_string.pop_back();
    }
    an_enz_acro = db_string.substr(0, db_string.find("/"));
    db_string.erase(0, db_string.find("/"));
    while(db_string.compare("/") != 0){
      db_string.erase(0,1);
      a_reco_seq = db_string.substr(0, db_string.find("/"));
      SequenceMap new_sequence_map(a_reco_seq, an_enz_acro);
      a_tree.insert(new_sequence_map);
      db_string.erase(0,db_string.find("/"));
    }
  } 
}

template <typename TreeType>
pair<int, int> questionFour( TreeType &a_tree, const string seq_filename) {
  int successfulQ = 0;
  int recursionAvg = 0;
  int numberOfQueries = 0;
  string seqInput;

  ifstream seqFile(seq_filename);
  while(getline(seqFile, seqInput)) {
    pair<bool, int> result = a_tree.find(seqInput);
    if(result.first == true) { successfulQ++; }
    recursionAvg = recursionAvg + result.second;
    numberOfQueries++;
  }  

  recursionAvg = recursionAvg / numberOfQueries;

  pair<int, int> returnvalue(successfulQ, recursionAvg);
  return returnvalue;
}

template <typename TreeType>
pair<int, int> questionFive( TreeType &a_tree, const string seq_filename) {
  int successfulR = 0;
  int recursionAvg = 0;
  int numberOfRemoves = 0;
  string seqInput;

  ifstream seqFile(seq_filename);
  while(getline(seqFile, seqInput)) {
    pair<bool, int> result = a_tree.del(seqInput);
    if(result.first == true) { successfulR++; }
    recursionAvg += result.second;
    numberOfRemoves++;
    seqFile.ignore(10000, '\n'); //Ignores everyother line
  }

  recursionAvg = recursionAvg / numberOfRemoves;
  pair<int, int> returnvalue(successfulR, recursionAvg);
  return returnvalue;
}

}  // namespace

int
main(int argc, char **argv) {
  if (argc != 4) {
    cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename> <tree-type>" << endl;
    return 0;
  }
  const string db_filename(argv[1]);
  const string seq_filename(argv[2]);
  const string param_tree(argv[3]);
  cout << "Input file is " << db_filename << ", and sequences file is " << seq_filename << endl;
  cout << "Type of tree is " << param_tree << endl;
  if (param_tree == "BST") {
    BinarySearchTree<SequenceMap> a_tree;
    TestTree(db_filename, seq_filename, a_tree);

    cout << "2: " << a_tree.size() << endl;
    cout << "3a: " << a_tree.aDepth()/a_tree.size() << endl;
    cout << "3b: " << (a_tree.aDepth()/a_tree.size())/log2(a_tree.size()) << endl;
    pair<int, int> result4 = questionFour(a_tree, seq_filename);
    cout << "4a: " << result4.first << endl;
    cout << "4b: " << result4.second << endl;
    pair<int, int> result5 = questionFive(a_tree, seq_filename);
    cout << "5a: " << result5.first << endl;
    cout << "5b: " << result5.second << endl;
    cout << "6a: " << a_tree.size() << endl;
    cout << "6b: " << a_tree.aDepth()/a_tree.size() << endl;
    cout << "6c: " << (a_tree.aDepth()/a_tree.size())/log2(a_tree.size()) << endl;

  } else if (param_tree == "AVL") {
    AvlTree<SequenceMap> a_tree;
    TestTree(db_filename, seq_filename, a_tree);

    cout << "2: " << a_tree.size() << endl;
    cout << "3a: " << a_tree.aDepth()/a_tree.size() << endl;
    cout << "3b: " << (a_tree.aDepth()/a_tree.size())/log2(a_tree.size()) << endl;
    pair<int, int> result4 = questionFour(a_tree, seq_filename);
    cout << "4a: " << result4.first << endl;
    cout << "4b: " << result4.second << endl;
    pair<int, int> result5 = questionFive(a_tree, seq_filename);
    cout << "5a: " << result5.first << endl;
    cout << "5b: " << result5.second << endl;
    cout << "6a: " << a_tree.size() << endl;
    cout << "6b: " << a_tree.aDepth()/a_tree.size() << endl;
    cout << "6c: " << (a_tree.aDepth()/a_tree.size())/log2(a_tree.size()) << endl;

  } else {
    cout << "Uknown tree type " << param_tree << " (User should provide BST, or AVL)" << endl;
  }


  return 0;
}
