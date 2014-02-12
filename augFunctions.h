#include <vector>       // std::vector
#include <string>
#include "reader.h"


#ifndef AUGFUNCTION_H_
#define AUGFUNCTION_H_


using namespace std;

string nameGenerator(void);
void printArray(vector<Node*>);
vector<Node*> setUnion(vector<Node*>,vector<Node*>);
vector<Node*> setIntersection(vector<Node*>,vector<Node*>);
vector<Node*> setDifference(vector<Node*>,vector<Node*>);
vector<int> genInterestList(University*);
void updateNonNetwork(Node*);
void Sort(vector<Node*>*);
void removeSelf(vector<Node*>*,Node*);
bool ifInList(vector<Node*>*,Node*);
vector<Node*> getPeopleInSameCourse(Node*);
vector<Node*> getPeopleWithSameInterest(Node*);


#endif /* AUGFUNCTION_H_ */