#include "setFriends.h"
#include <fstream>
#include <iostream>
#include <omp.h>

using namespace std;

ofstream myfile;

void initLog(){
	myfile.open("log_new.txt");
}

void closeLog(){
	myfile.close();
}




void setFriends(Graph* g){
	vector<Node*> temp;
	for (University* u : g->universities){
		vector<Node*> tempAllSet = u->uniNodes;
		for (int i=0;i<1;i++){
			int randomInteger = rand()%tempAllSet.size();
			temp.push_back(tempAllSet[randomInteger]);
			removeSelf(&tempAllSet,tempAllSet[randomInteger]);
		}
	}

//#pragma omp parallel for
	for (int i=0; i<temp.size();i++){
		Node* n = temp[i];
		vector<Node*> network;
		string line="";
		if (rand()%100 < n->university->out_probability*100){
			if(n->ifStudent){
				if(n->nonNetwork.size()!=0){
					int randomInteger = rand()%n->nonNetwork.size();
					Node* possibleFriend = n->nonNetwork[randomInteger];
					line += n->name + " of " + n->university->name + " sent a request to " + possibleFriend->name + " of " + possibleFriend->university->name + ". Result:";
					if((rand()%100<possibleFriend->university->recip_probability*100)&&!ifInList(&n->friends,possibleFriend)){
						n->addFriend(n,possibleFriend);
						removeSelf(&(n->nonNetwork),possibleFriend);
						line += "Accepted. \n" ;
					}				
					else{
						line+= "Rejected. \n";
					};
				}
			}
			else{
				if(n->nonNetwork.size()!=0){
					int randomInteger = rand()%n->nonNetwork.size();
					Node* possibleFriend = n->nonNetwork[randomInteger];
					line += n->name + " of " + n->university->name + " sent a request to " + possibleFriend->name + " of " + possibleFriend->university->name + ". Result:";
					if((rand()%100<possibleFriend->university->recip_probability*100)&&!ifInList(&n->friends,possibleFriend)){
						n->addFriend(n,possibleFriend);
						removeSelf(&(n->nonNetwork),possibleFriend);
						line+= "Accepted. \n" ;
					}
					else{
						line+= "Rejected. \n";
					};
				}
			};	
		}
	else{
		int pick = rand()%4;
		vector<Node*> allSet;
		switch (pick){
			case 0: 		// Sharing a course
				allSet = n->sameCourse;
				break;
			case 1:			// Same Department
				allSet = n->department->allStudents;
				allSet.insert(allSet.end(),n->department->allFaculty.begin(),n->department->allFaculty.end());
				break;
			case 2:			// Same Neighbourhood
				if (n->ifStudent){
					allSet = n->hostel->residents;
				}
				else{
					allSet = n->houseLocality->residents;
				};
				break;
			case 3:			// Same Interest
				allSet = n->sameInterests;
				break;
		};
		allSet = setDifference(allSet,n->friends);
		removeSelf(&allSet,n);
		if(allSet.size()!=0){
			int randomInteger = rand()%allSet.size();
			Node* possibleFriend = allSet[randomInteger];
			line += n->name + " of "+n->university->name + " sent a request to " + possibleFriend->name + " of " + possibleFriend->university->name + ". Result:";
			if((rand()%100<possibleFriend->university->recip_probability*100)&&!ifInList(&n->friends,possibleFriend)){
				n->addFriend(n,possibleFriend);
				removeSelf(&(n->nonNetwork),possibleFriend);
				line+= "Accepted. \n" ;
			}
			else{
				line+= "Rejected. \n";
				};
		}
	};
		myfile << line;
	}
}