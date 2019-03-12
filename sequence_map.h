/**
    Name: Ethan Sam 
	Date: 3/11/2019
	Professor: Ioannis Stamos
	Class: CSCI 335
	
	Header file: sequence_map.h
	
	This file is a header for sequence_map.cpp
	
	
 Few comments describing the class sequence_map.h
**/	
#ifndef _SEQUENCE_MAP
#define _SEQUENCE_MAP
#include <iostream>
#include <string>
#include <vector>
#include "avl_tree.h"
using namespace std;

class SequenceMap
{
public:
	// the Big Five
	SequenceMap();
	SequenceMap(const SequenceMap &rhs);
	SequenceMap(SequenceMap &&rhs);
	SequenceMap& operator=(const SequenceMap &rhs);
	SequenceMap& operator=(SequenceMap &&rhs);
	// END BIG FIVE
	SequenceMap(const string &a_rec_seq, const string &an_enz_acro);
	bool operator<(const SequenceMap &rhs) const;
	//Overloaded "<<" operator
	friend ostream& operator<<(ostream &out, const SequenceMap &anotherMap);
	void Merge(const SequenceMap &other_sequence);
	bool isEmpty() const;
	string getSequence() const;
	vector<string> getAcronym() const;
	//Destructor
	~SequenceMap();
private:
	string recognition_sequence_;
	vector<string> enzyme_acronyms_;
};

#include "sequence_map.cpp"
#endif // _SEQUENCE_MAP 




 