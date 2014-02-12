#include "Node.h"
#include <vector>
#include <string>

using namespace std;
int Node::IDcount=0;
Node::Node(string s,University* university_i,Hostel* hostel_i,HouseLocality* houselocality_i, Department* department_i,vector<int> interests_i,bool ifStudent_i,int entryYear_i){
	name = s;
	ifStudent = ifStudent_i;
	if(ifStudent){
		studentID = university_i->stuID++;// code to compute ID
		hostel = hostel_i;
	}
	else{
		facultyID = university_i->facID++;// code to compute ID
		houseLocality = houselocality_i;
	};
	university = university_i;
	department = department_i;
	interests = interests_i;
	entryYear = entryYear_i;
	nodeID = Node::IDcount++;
	university_i->uniNodes.push_back(this);
};

Node::Node(){
	nodeID = Node::IDcount++;
};

void Node::addFriend(Node* n1, Node* n2){
	if (!ifInList(&n1->friends,n2)){
		n1->friends.push_back(n2);
	}
	if (!ifInList(&n2->friends,n1)){
		n2->friends.push_back(n1);
	}
}

vector<int> Node::getInterests(Node* n){
	return n->interests;
}

vector<Course*> Node::getCourse(Node* n){
	return n->currentCourses;
}


void Node::setCourse(vector<Course*> courses){
	doneCourses.insert(doneCourses.end(),currentCourses.begin(),currentCourses.end());
	currentCourses.resize(0);
	for(Course* c: courses){
		currentCourses.push_back(c);
	}
}



Hostel* Node::getHostel(Node* n){
	if(ifStudent){
		return n->hostel;
	}
	else{
		return 0;
	};
}



HouseLocality* Node::getHouseLocality(Node* n){
	if(!ifStudent){
		return n->houseLocality;
	}
	else{
		return 0;
	};
}

