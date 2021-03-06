/**
    Name: Ethan Sam 
	Date: 3/11/2019
	Professor: Ioannis Stamos
	Class: CSCI 335
	
	Header file: query_tree.cc
	
	This file takes two files as arguments: "rebase210.txt" and "sequences.txt"
	The contents of "rebase210.txt" are read and the file contents of "sequences.txt" 
	are queried 
	
	
 Few comments describing the class test_tree.cc
**/	
//File for part 2b
#include "avl_tree.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "sequence_map.h"
using namespace std;

namespace {


template<class TreeType>
void ConstructTree( TreeType &a_tree, const string& db_filename ) 
{
    ifstream input_stream(db_filename);
    if (!input_stream.good())
	{
        cerr << ".... ERROR ...." << endl;
	}
    string line;
    while (getline(input_stream, line)) 
	{
        if (line[line.length()-1] != '/' && line[line.length()-2] != '/')
		{
            continue;
		}
        stringstream line_stream; 
        line_stream << line;
        vector<string> sequences;
        string word;
        while (getline(line_stream, word
		{
           sequences.push_back(word);
		}
        for (unsigned int i = 1; i < sequences.size(); i++)
		{
            SequenceMap a_map(sequences[i], sequences[0]);
            a_tree.insert(a_map);
        }
    }
    input_stream.close();
}

template<class TreeType>
int CountSuccessfulQueries( const TreeType &a_tree, const string &db_filename ) 
{
    ifstream myFile(db_filename);
    string word;
    int count_success = 0;
    // temp_counter is needed for ".contains" to work
    int temp_counter = 0;
    while(myFile >> word) 
	{
		//We need a SequenceMap object to allow contains to work 
        SequenceMap map(word, "");  
        bool success = a_tree.contains(map, temp_counter);
        if (success)
		{
            count_success++;
		}
	}
    myFile.close();
    return count_success;

}

template<class TreeType>
int CountFindRecursionCalls( const TreeType &a_tree, const string &db_filename ) {
    ifstream myFile(db_filename);
    string word;
    int find_counter = 0;
    while(myFile >> word) 
	{
        SequenceMap map(word, ""); 
		//We need a SequenceMap object to allow contains to work  
        a_tree.contains(map, find_counter);
    }
    myFile.close();
    return find_counter;
}


template<class TreeType>
int CountRemoveEveryotherSequences( TreeType &a_tree, const string& seq_filename ) 
{
    ifstream myFile(seq_filename);
    string word;
    int delete_counter = 0;
    // we have to pass it in the function
    // in order to keep the function prototype correct
    int temp_counter = 0;
    int state = 1;
    while(getline(myFile, word)) {
        if(state%2 == 0) {
            SequenceMap map(word, "");
            if (a_tree.contains(map, temp_counter))
			{
                a_tree.remove(map, delete_counter);
            }
            state++; // the next iteration will skip this if statement
                    // since it becomes an odd integer.
        }
        else
            state++;
    }
    myFile.close();
    return delete_counter;
}


// @db_filename: an input database filename.
// @seq_filename: an input sequences filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void TestTree(const string &db_filename, const string &seq_filename, TreeType &a_tree) 
{
  // Code for running Part2(b)

		//1
        ConstructTree(a_tree, db_filename);
		//2
        int total_nodes = a_tree.countNodes();
		cout << "2: " << total_nodes << endl;
		
		//3a
		float average_depth = float(a_tree.heightOfTree(0)) / total_nodes;
		cout << "3a: " << average_depth << endl;
		
		//3b
        float ratio = average_depth / log2(total_nodes);
		cout << "3b: " << ratio << endl;
        
        //4a 
		int succesful_queries = CountSuccessfulQueries(a_tree, seq_filename);
        cout << "4a: " << succesful_queries << endl;
        

		//4b  (Uses successful_queries)
		int find_counter = CountFindRecursionCalls(a_tree, seq_filename);
		cout << "4b: " << float(find_counter) / succesful_queries << endl;

        //5a  "CountRemoveEveryotherSequences" needs to be called to update "a_tree"
		//so that total_nodes and a_tree.countNodes() are not the same value
		int delete_counter = CountRemoveEveryotherSequences(a_tree, seq_filename);		
        cout << "5a: " << total_nodes-a_tree.countNodes() << endl;
		
		//5b
		cout << "5b: " << float(delete_counter) / (total_nodes - a_tree.countNodes()) << endl;
		//6a
		average_depth = float(a_tree.heightOfTree(0)) / a_tree.countNodes();
        ratio = average_depth / log2(a_tree.countNodes());
        cout << "6a: " << a_tree.countNodes() << endl;
		
		//6b
        cout << "6b:" << average_depth << endl;
		
		//6c
        cout << "6c: " << ratio << endl; 

}

}// namespace


int main(int argc, char **argv) 
{
    if (argc != 3) 
	{
    cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename>" << endl;
    return 0;
    }
    string db_filename(argv[1]);
    string seq_filename(argv[2]);
	cout << "Input file is " << db_filename << ", and sequences file is " << seq_filename << endl;
	cout << "Type of Tree is AVL" <<endl;
    if (seq_filename == "sequences.txt") 
	{
    AvlTree<SequenceMap> a_tree;
	TestTree(db_filename, seq_filename, a_tree);
    } 

    return 0;
}


