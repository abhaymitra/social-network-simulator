#include <vector>
#include <string>
#include <string.h>	
#include <iostream>

#ifndef ALLSTRUCTS_H_
#define ALLSTRUCTS_H_



using namespace std;

struct Hostel;
struct HouseLocality;
struct Course;
struct Department;
struct University;
class Node;
class Graph;

struct Hostel
{
	string name;
	int RoomNo;
	vector<Node*> residents;
	Hostel(){
		RoomNo = 0;
	};
	void addResident(Node* n){
		residents.push_back(n);
		RoomNo++;
	}
}; 

struct HouseLocality
{
	string name;
	int HouseNo;
	vector<Node*> residents;
	void addResident(Node* n){
		residents.push_back(n);
		HouseNo ++;
	}
	HouseLocality(){
		HouseNo = 0;
	};
};

struct Course
{
	public:
		Department* parentDepartment;
		string name;
		Node* currentFaculty;
		vector<Node*> enrolledStudents;
		float frequencyPerYear;
		Course(){};
		void addStudent(Node* n){
		enrolledStudents.push_back(n);
		}
};

struct Department
{
	public:
		University* parentUniversity;
		string name;
		vector<Node*> allFaculty;
		vector<Node*> allStudents;
		vector<Course*> allCourses;
		vector<Course*> floatedCourses;
		float departmentCoursesPerSemester;
		float nonDepartmentCoursesPerSemester;
		int numStudents;
		int numFaculty;
		int roundRobinIndex;
		Department(){
			roundRobinIndex=0;
		};
		void addFaculty(Node* n){
			allFaculty.push_back(n);
		}
		void addStudent(Node* n){
			allStudents.push_back(n);
		}
		void addCourse(string s){
			Course* c = new Course();
			c->name = s;
			allCourses.push_back(c);
		}
		Course* getCourse(string name){
			for(Course* c: allCourses){
				if(strcmp(c->name.c_str(),name.c_str())==0){
					return c;
				}
			}
			return 0;
		}
};

struct InterestProbabilities
{
	public:
		int interestIndex;
		float probability;
};

struct University 
{
	public:
		int facID;
		int stuID;
		Graph* graph;
		string name;
		vector<Node*> uniNodes;
		vector<Department*> departments;
		vector<Hostel*> hostels;
		vector<HouseLocality*> houseLocalities;
		float out_probability;
		float recip_probability;
		float friendship_rate;
		vector<InterestProbabilities> interestProbabilities;
		University(){
			facID =1;
			stuID = 1;
		};
		void addHostel(string s){
			Hostel* h = new Hostel();
			h->name = s;
			hostels.push_back(h);
		}
		void addHouseLocality(string s){
			HouseLocality* h = new HouseLocality();
			h->name = s;
			houseLocalities.push_back(h);
		}
		void addDepartment(string s){
			Department* d = new Department();
			d->parentUniversity = this;
			d->name = s;
			departments.push_back(d);
			
		}
		Department* getDepartment(string name){
			for(Department* d: departments){
				if(strcmp(d->name.c_str(),name.c_str())==0){
					return d;
				}
			}
			return 0;
		}
		Hostel* getHostel(string name){
			for(Hostel* h: hostels){
				if(strcmp(h->name.c_str(),name.c_str())==0){
					return h;
				}
			}
			return 0;
		}
		HouseLocality* getHouseLocality(string name){
			for(HouseLocality* h: houseLocalities){
				if(strcmp(h->name.c_str(),name.c_str())==0){
					return h;
				}
			}
			return 0;
		}
};

#endif /* ALLSTRUCTS_H_ */