#include "All_Structs.h"
#include <vector>
#include "augFunctions.h"

#ifndef NODE_H_
#define NODE_H_


using namespace std;

class Graph;	

class Node{
	// To be made public
	public:
		static int IDcount;
		string name;
		int nodeID;
		Graph* graph;
		bool ifStudent;
		University* university;
		vector<Node*> friends;
		Department* department;
		vector<int> interests;
		vector<Course*> currentCourses;
		vector<Course*> doneCourses;
		vector<Node*> nonNetwork;
		vector<Node*> sameCourse;
		vector<Node*> sameInterests;
		// Student attributes
		Hostel* hostel;
		int roomNo;
		int studentID;
		int entryYear;

		//Faculty attributes
		HouseLocality* houseLocality;
		int houseNo;
		int facultyID;

		string uni;

		//functions
		vector<int> getInterests(Node* n);
		vector<Course*> getCourse(Node* n);
		void setCourse(vector<Course*> courses);
		Hostel* getHostel(Node* n);
		HouseLocality* getHouseLocality(Node* n);
		void addFriend(Node* n1, Node* n2);
		Node();
		Node(string,University*,Hostel*,HouseLocality*, Department*,vector<int>,bool,int);
};


#endif /* NODE_H_ */