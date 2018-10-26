#ifndef SEQUENCE_MAP_H
#define SEQUENCE_MAP_H	

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SequenceMap{
 public:
  SequenceMap() = default;

  SequenceMap(const string &a_rec_seq, const string &an_enz_acro) {
  	enzyme_acronyms_.push_back(an_enz_acro);
    recognition_sequence_ = a_rec_seq;
  }

  bool operator<(const SequenceMap &rhs) const {
  	if(recognition_sequence_.compare(rhs.getRecSeq()) < 0) { return true; }
  	else { return false; }
  }

  bool operator==(const SequenceMap &rhs) const {
    if(recognition_sequence_.compare(rhs.getRecSeq()) == 0) { return true; }
    else { return false; }
  }

  friend ostream& operator<<(ostream& os, SequenceMap sm) {
    for(unsigned int i = 0; i < sm.getEnzAcr().size(); i++) {
    cout << sm.enzyme_acronyms_[i] << " ";
    }
    return os;
  }

  void Merge(const SequenceMap &other_sequence) {
  	for(unsigned int i = 0; i < other_sequence.getEnzAcr().size(); i++) {
  		enzyme_acronyms_.push_back(other_sequence.getEnzAcr()[i]);
  	}
  }

  void insert(string input) { enzyme_acronyms_.push_back(input); }
  string getRecSeq() const { return recognition_sequence_; }
  vector<string> getEnzAcr() const { return enzyme_acronyms_; }

 private:
  string recognition_sequence_;
  vector<string> enzyme_acronyms_;
};

#endif