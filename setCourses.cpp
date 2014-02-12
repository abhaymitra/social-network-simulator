#include "setCourses.h"
#include <math.h>
// #include "timekeeper.h"

using namespace std;

void floatCourses(Graph* g){
	g->ifFirstSemester = !g->ifFirstSemester;
	for(University* uni : g->universities){
		for(Department* dep : uni->departments){
			for (Node* faculty : dep->allFaculty){
				faculty->currentCourses.resize(0);
			}
			dep->floatedCourses.resize(0);
			dep->roundRobinIndex = (dep->roundRobinIndex +1)%dep->numFaculty;
			int facIndex = dep->roundRobinIndex;
			int counter =0;
			for(Course* c : dep->allCourses){
				c->enrolledStudents.resize(0);
				if(g->ifFirstSemester){
					if(c->frequencyPerYear>=1){
						dep->floatedCourses.push_back(c);
						c->currentFaculty = dep->allFaculty[(facIndex+counter)%(dep->allFaculty.size())];
						c->currentFaculty->currentCourses.push_back(c);
						counter++;
					}
					else{
						if(rand()%100<(c->frequencyPerYear/((float) 2.0))*100){
							dep->floatedCourses.push_back(c);
							c->currentFaculty = dep->allFaculty[(facIndex+counter)%(dep->allFaculty.size())];
							c->currentFaculty->currentCourses.push_back(c);
							counter++;
						}
					};
				}
				else{
					if(c->frequencyPerYear>=1){
						if(rand()%100<(((c->frequencyPerYear-1))*100)){
							dep->floatedCourses.push_back(c);
							c->currentFaculty = dep->allFaculty[(facIndex+counter)%(dep->allFaculty.size())];
							c->currentFaculty->currentCourses.push_back(c);
							counter++;
						}
					}
					else{
						if(rand()%100<(c->frequencyPerYear/((float) 2.0))*100){
							dep->floatedCourses.push_back(c);
							c->currentFaculty = dep->allFaculty[(facIndex+counter)%(dep->allFaculty.size())];
							c->currentFaculty->currentCourses.push_back(c);
							counter++;
						}
					};
				};
			}
		}
	}
}


void setCourses(Graph* g){
	for(Node* n : g->allNodes){
		if(n->ifStudent){
			float depCourses = n->department->departmentCoursesPerSemester;
			float nonDepCourses = n->department->nonDepartmentCoursesPerSemester;
			int ifExtra =0;
			if (rand()%100 > (depCourses - floor(depCourses))*100){
				ifExtra =1;	
			}
			vector<Course*> tempCourses;
			vector<Course*> allSet = n->department->floatedCourses;
			for(int i=0;i<floor(depCourses)+ifExtra;i++){
				int randomInteger = rand()%allSet.size();
				tempCourses.push_back(allSet[randomInteger]);
				allSet[randomInteger]->addStudent(n);
				allSet.erase(allSet.begin() + randomInteger);
			}
			allSet.resize(0);
			ifExtra =0;
			if (rand()%100 > (nonDepCourses - floor(nonDepCourses))*100){
				ifExtra =1;	
			}
			for(Department* d : n->university->departments){
				if(strcmp(d->name.c_str(),n->department->name.c_str())!=0){
					allSet.insert(allSet.end(),d->floatedCourses.begin(),d->floatedCourses.end());
				}
			}
			for(int i=0;i<floor(nonDepCourses)+ifExtra;i++){
				int randomInteger = rand()%allSet.size();
				tempCourses.push_back(allSet[randomInteger]);
				allSet.erase(allSet.begin() + randomInteger);
				allSet[randomInteger]->addStudent(n);
			}
			n->setCourse(tempCourses);
		}
	}
	for(Node* n : g->allNodes){
		updateNonNetwork(n);
	}
}
