// Ethan Sam
// Main file for Part2(a) of Homework 2.
#include "avl_tree_modified.h"
#include "sequence_map.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

namespace {

// @db_filename: an input filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void QueryTree(const string &db_filename, TreeType &a_tree) 
{
// Code for running Part2(a)
ifstream input_file(db_filename);
    if (!input_file.good())
        cerr << "....ERROR...." << endl;
    string db_line;
    while (getline(input_file, db_line)) 
	{
        if (db_line[db_line.length()-1] != '/' && db_line[db_line.length()-2] != '/')
            continue;
        stringstream line_stream;
        line_stream << db_line;
        vector<string> sequences;
        string word;
        while (getline(line_stream, word,'/'))
           sequences.push_back(word);
        for (size_t i = 1; i < sequences.size(); ++i)
		{
            SequenceMap a_map(sequences[i], sequences[0]);
            a_tree.insert(a_map);
        }
    }
    input_file.close();

}

}

int main(int argc, char **argv)
 {
	 
  if (argc != 2)  
  {
    cout << "Usage: " << argv[0] << " <databasefilename>" << endl;
    return 0;
  }
  const string db_filename(argv[1]);
  cout << "Input filename is " << db_filename << endl;
  // Note that you will replace AvlTree<int> with AvlTree<SequenceMap>
  if (db_filename == "rebase210.txt") 
  {
        cout << "I will parse the text and create an AVL tree" << endl;
        AvlTree<SequenceMap> a_tree;
		int temp_counter = 0;
        QueryTree(db_filename, a_tree);
        string sequence;
        cout << "Please enter recognition sequence: ";
  while(getline(cin, sequence))
		{
			//SequenceMap object only containing the recognition_sequence
			SequenceMap map{sequence, ""};
			if(a_tree.contains(map, temp_counter))
			{
				a_tree.printElement(map); 
			}
			else
				std::cout << "Tree does not contain the sequence\n";
		}

  return 0;

	}
	
	
}

