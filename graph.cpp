#include "graph.h"
#include <iostream>
#include <string>

using namespace std;

void Graph::addUniversity(string name_i){
	University* u = new  University();
	u->name = name_i;
	u->graph = this;
	universities.push_back(u);
}

void Graph::addInterest(string interestName){
	interestMap[interestName] = interestNo;
	reverseMap[interestNo] = interestName;
	interestNo++; 
	interestList.resize(interestList.size()+1);
	interestList[interestList.size()-1].resize(0);
}

int Graph::getInterestIndex(string interestName){
	if(interestMap.find(interestName) == interestMap.end()){
		addInterest(interestName);
		return interestMap[interestName];
	}
	return interestMap[interestName];
}

void Graph::printInterestList(){
	for (int i=0;i<interestList.size();i++){
		for (int j=0;j<interestList[i].size();j++){
			cout << i<<"		" << interestList[i][j]->name << endl;
		}
	}
}

University* Graph::getUniversity(string univName){
	for(University* u : universities){
		if(strcmp(u->name.c_str(),univName.c_str()) == 0){
			return u;
		}
	}
	return 0;
}

StringToTypes Graph::stringToTypes(string univName,string hostelName,string depName){
	StringToTypes result = {};
	result.university = getUniversity(univName);
	result.department = result.university->getDepartment(depName);
	result.hostel = result.university->getHostel(hostelName);
	return result;
}

vector<int> Graph::generateInterestArray(vector<string> stringArray){
	vector<int> temp;
	for(string s: stringArray){
		temp.push_back(getInterestIndex(s));
	}
	return temp;
}

Graph::Graph(){};

