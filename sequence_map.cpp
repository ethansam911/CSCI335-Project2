/**
    Name: Ethan Sam 
	Date: 3/11/2019
	Professor: Ioannis Stamos
	Class: CSCI 335
	
	Header file: sequence_map.cpp
	
	This file provides implementation for the big five and constructors
	for the AvlTree
	
	
 Few comments describing the class sequence_map.h
**/	

#include "sequence_map.h"

SequenceMap::SequenceMap() : recognition_sequence_{""}
{}

SequenceMap::SequenceMap(const SequenceMap &rhs) {
	recognition_sequence_ = rhs.recognition_sequence_;
	for(size_t i=0; i<rhs.enzyme_acronyms_.size(); i++)
		enzyme_acronyms_.push_back(rhs.enzyme_acronyms_[i]);
}

SequenceMap::SequenceMap(SequenceMap &&rhs) {
	recognition_sequence_ = rhs.recognition_sequence_;
	enzyme_acronyms_ = std::move(rhs.enzyme_acronyms_);
}

SequenceMap& SequenceMap::operator=(const SequenceMap &rhs) 
{
	enzyme_acronyms_.clear();
	recognition_sequence_ = rhs.recognition_sequence_;
	for(size_t i=0; i<rhs.enzyme_acronyms_.size(); ++i)
		enzyme_acronyms_.push_back(rhs.enzyme_acronyms_[i]);
	return *this;
}

SequenceMap& SequenceMap::operator=(SequenceMap &&rhs) 
{
	recognition_sequence_ = rhs.recognition_sequence_;
	std::swap(enzyme_acronyms_, rhs.enzyme_acronyms_);
	return *this;
}

SequenceMap::SequenceMap(const string &a_rec_seq, const string &an_enz_acro)
{
	recognition_sequence_ = a_rec_seq;
	enzyme_acronyms_.push_back(an_enz_acro);
}

//END OF BIG FIVE

bool SequenceMap::operator<(const SequenceMap &rhs) const
{
	return recognition_sequence_ < rhs.recognition_sequence_;
}

ostream& operator<<(ostream &out, const SequenceMap &anotherMap) {
    out << "Recognition Sequence: " << anotherMap.recognition_sequence_ << endl;
    out << "Enzyme Acronyms: ";
    if(anotherMap.enzyme_acronyms_.size() == 0)
	{
        out << "Not Found";
	}
    else
	{
        for(unsigned int i=0; i<anotherMap.enzyme_acronyms_.size(); i++)
		{
            out << anotherMap.enzyme_acronyms_[i] << " ";
		}
    }
    out <<"\n_____________________________________________ " << endl;
    return out;
}

void SequenceMap::Merge(const SequenceMap &other_sequence) 
{
	if(recognition_sequence_ == other_sequence.recognition_sequence_)
    {
		for(size_t i=0; i<other_sequence.enzyme_acronyms_.size(); ++i)
		{
			enzyme_acronyms_.push_back(other_sequence.enzyme_acronyms_[i]);
		}
		
	}
}

bool SequenceMap::isEmpty() const {
    return recognition_sequence_.empty();
}

string SequenceMap::getSequence() const {
    return recognition_sequence_;
}

vector<string> SequenceMap::getAcronym() const {
    return enzyme_acronyms_;
}

SequenceMap::~SequenceMap(){
	recognition_sequence_ = "";
	enzyme_acronyms_.clear();
}