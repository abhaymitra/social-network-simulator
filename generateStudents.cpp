#include "generateStudents.h"
#include "augFunctions.h"
#include <math.h>

using namespace std;

void genStudents(Graph* g){
	for (University* uni: g->universities){
		for (Department* dep : uni->departments){
			for (int i=0;i<dep->numStudents;i++){
				vector<int> interests = genInterestList(uni) ;
				Hostel* h = uni->hostels[rand()%uni->hostels.size()];
				int year = floor(g->currentTime/(365.0*24*60*60)) + 1970;
				Node* n = new Node(nameGenerator(),uni,h,0,dep,interests,true,year);
				n->graph = g;
				dep->addStudent(n);
				g->allNodes.push_back(n);
				h->addResident(n);
				n->roomNo = h->RoomNo;
				for (int i: interests){
					g->interestList[i].push_back(n);
				}
			}
		}
	}
	for(Node* n : g->allNodes){
		updateNonNetwork(n);
	}
}