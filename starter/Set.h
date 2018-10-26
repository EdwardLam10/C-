#ifndef __CS235_SET_H_
#define __CS235_SET_H_

#include "Vector.h"

class Set {
 public:
	unsigned int size() const;
	bool empty() const;
	
	bool contains(const int& data) const;
		
	bool insert(const int& data);
	bool remove(const int& data);

	void clear();

 private:
	Vector vector_;

};

#endif
