#ifndef _SEQUENCE_MAP
#define _SEQUENCE_MAP
#include <iostream>
#include <string>
#include <vector>
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
	// end big five.
	SequenceMap(const string &a_rec_seq, const string &an_enz_acro);
	bool operator<(const SequenceMap &rhs) const;
	friend ostream& operator<<(ostream &out, const SequenceMap &anotherMap);
	void Merge(const SequenceMap &other_sequence);
	bool isEmpty() const;
	string getSequence() const;
	vector<string> getAcronym() const;
	~SequenceMap();
private:
	string recognition_sequence_;
	vector<string> enzyme_acronyms_;
};

#include "sequence_map.cpp"

#endif // _SEQUENCE_MAP 




 