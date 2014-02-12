
//#include "All_Structs.h"
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <string.h>
#include "Node.h"
#include <map>
#include <utility>


using namespace std;

typedef struct StringToTypes
{
	University* university;
	Hostel* hostel;
	Department* department;
};

class Graph{
	// To be made private
	public:
		map<string, int> interestMap;
		map<int,string> reverseMap;
		int interestNo ;
		vector<University*> universities;
		vector<Node*> allNodes; 
		int totalStudents;
		int totalFaculty;
		long currentTime;
		bool ifFirstSemester;
		vector<vector<Node*> > interestList;
	public:
		void addInterest(string interestName);
		int getInterestIndex(string interestName);
		University* getUniversity(string univName);
		vector<int> generateInterestArray(vector<string> stringArray);
		StringToTypes stringToTypes(string univName,string hostelName,string depName);
		void addUniversity(string name_i);
		void printInterestList();
		Graph();
};


#endif /* GRAPH_H_ */