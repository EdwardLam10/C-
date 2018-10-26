//Edward Lam
//Chain class is a templated array that can take in a list of a specific format.

#ifndef CSCI335_HOMEWORK1_CHAIN_
#define CSCI335_HOMEWORK1_CHAIN_

#include <iostream>
#include <cstddef>
#include <sstream>

using namespace std;

namespace teaching_project {
// Can take in a list in a specific format and save it into a templated array class.
// If no parameters are added in the constructor it will create an array of size 0,
// Arrays are created dynamically so their sizes can be determined at run time.
template<typename Object>
class Chain {
 public:
  // Default "big five" -- you have to alter them for your assignment.
  // That means that you will remove the "= default" statement.
  //  and you will provide an implementation.

  // Zero-parameter constructor.
  Chain() {
  	size_ = 0;
  	array_ = new Object [0];
  }

  // Copy-constructor.
  // Creates a deep copy of the Chain passed as parameter
  Chain(const Chain &rhs) {
  	size_ = rhs.size_;
  	array_ = new Object [rhs.size_];
	for(unsigned int i = 0; i < size_; i++) {
	  array_[i] = rhs.array_[i];
	}
  }

  // Copy-assignment. If you have already written
  // the copy-constructor and the move-constructor
  // you can just use:
  // {
  // Chain copy = rhs; 
  // std::swap(*this, copy);
  // return *this;
  // }
  Chain& operator=(const Chain &rhs) {
    Chain copy = rhs;
    swap(*this, copy);
    return *this;
  }

  // Move-constructor.
  // Moves the data from one chain into the other, the chain that is moved will be deleted.
  Chain(Chain &&rhs) {
    size_ = rhs.size_;
    array_ = move(rhs.array_);
    rhs.array_ = nullptr;
    rhs.size_ = 0;
  }

  // Move-assignment.
  // Same as Move-constructor.
  Chain& operator=(Chain &&rhs) {
    size_ = rhs.size_;
    array_ = move(rhs.array_);
    rhs.array_ = nullptr;
    rhs.size_ = 0;
    return *this;
  }

  // End of big-five.

  // One parameter constructor.
  Chain(const Object& item) {
    size_ = 1;
    array_ = new Object [1];
    array_[0] = item;
  }

  // Read a chain from standard input.
  void ReadChain() {
    string input; 
    getline(cin, input);
    
	// String manipulation to extract data from string.
	input = input.substr(1); // remove front [
	input.pop_back(); // remove back ]
	size_ = input[0] - '0';
	input = input.substr(3);
	
	delete [] array_; // Deletes the current array
	array_ = new Object [size_]; // recreates the array to fit new data
	
	istringstream ssinput(input);
	for(unsigned int i = 0; i < size_; i++) {
		ssinput >> array_[i];
	}
  }
  
  // Chain operator+ overloaded to accept a string as one of the parameters.
  // Recreates a new Chain to update the array size, destructor should be called
  // after leaving the scope of the function so there shouldn't be any memory leak. (I hope)
  Chain operator+(string rhs) {
    Chain<string> tmp;
    tmp.array_ = new string [size_ + 1];
    tmp.size_ = size_ + 1;
    for(unsigned int i = 0; i < size_; i++) {
      tmp.array_[i] = array_[i];
	}
	tmp.array_[size_] = rhs;
	swap(tmp.array_,array_);
	swap(tmp.size_,size_);
	return *this;
  }

  size_t size() const { 
    return size_;
  }

  // @location: an index to a location in the chain.
  // @returns the Object at @location.
  // const version.
  // abort() if out-of-range.
  const Object& operator[](size_t location) const { 
    return array_[location];
  }

 // @location: an index to a location in the range.
 // @returns the Object at @location.
 // non-const version.
 // abort() if out-of-range.
 Object& operator[](size_t location) { 
   return array_[location];
 }

 //  @c1: A chain.
 //  @c2: A second chain.
 //  @return the concatenation of the two chains.
 friend Chain operator+(const Chain &c1, const Chain &c2) {
   Chain<Object> tmp;
   tmp.size_ = c1.size_ + c2.size_;
   tmp.array_ = new Object [tmp.size_];
   if(c1.size_ == 0) {
     for(unsigned int i = 0; i < tmp.size_; i++) {
       	tmp.array_[i] = c2.array_[i];
	 }
   } else if(c2.size_ == 0) {
   	 for(unsigned int i = 0; i < tmp.size_; i++) {
   	   tmp.array_[i] = c1.array_[i];	
	 }
   } else {
   	  int i = 0;
   	  for(unsigned int c1Counter = 0; c1Counter < c1.size_; c1Counter++) {
   	    tmp.array_[i] = c1.array_[c1Counter];
		i++;	
	  }
	  for(unsigned int c2Counter = 0; c2Counter < c2.size_; c2Counter++) {
	  	tmp.array_[i] = c2.array_[c2Counter];
	  	i++;
	  }
   }
   return tmp;
 }

 // Overloading the << operator.
 friend std::ostream &operator<<(std::ostream &out, const Chain &a_chain) {
  cout << '[';
  if(a_chain.size_ != 0) {
  	cout << a_chain.array_[0];
  }
  for(unsigned int i = 1; i < a_chain.size_; i++) {
  	cout << " " << a_chain.array_[i];
  }
  cout << ']' << endl;
  return out;
 }
 
 private:
  size_t size_;
  Object *array_;
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_CHAIN_
