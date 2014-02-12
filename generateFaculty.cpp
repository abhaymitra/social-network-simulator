#include "generateFaculty.h"
#include <math.h>

using namespace std;

void genFaculty(Graph* g){
	for (University* uni: g->universities){
		for (Department* dep : uni->departments){
			for (int i=0;i<dep->numFaculty;i++){
				vector<int> interests = genInterestList(uni) ;
				HouseLocality* h = uni->houseLocalities[rand()%uni->houseLocalities.size()];
				int year = floor(g->currentTime/(365.0*24*60*60)) + 1970;
				Node* n = new Node(nameGenerator(),uni,0,h,dep,interests,false,year);
				n->graph = g;
				dep->addFaculty(n);
				g->allNodes.push_back(n);
				h->addResident(n);
				n->roomNo = h->HouseNo;
				for (int i: interests){
					g->interestList[i].push_back(n);
				}
			}
		}
	}
}