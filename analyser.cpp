#include "graph.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

int matrix[][];
Graph g;

void parsexml(const char *filename){
	std::vector<int> tscore(0);
	string line;
	int temp;
	std::string sscore;
	ifstream myfile (filename);
	if (myfile.is_open())
	{
	while ( myfile.good() ){
	  getline (myfile,line);

		}
		myfile.close();
	}
}

vector<vector <int>> bfs(int n, int r){
	std::vector<bool> v(n);
    std::fill(v.begin() + n - r, v.end(), true);
    vector<vector <int>> temp;
    do {
    	vector<int> t;
        for (int i = 0; i < n; ++i) {
            if (v[i]) {
                t.push_back(i+1);
            }
        }
       temp.push_back(t);
    } while (std::next_permutation(v.begin(), v.end()));
    return temp;
}

bool checkfriends(vector<int> v){
	for(int i=0;i<v.size();v++){
		for(int j=0;j<v.size();v++){
			if(i!=j){
				if(matrix[i][j]!=1){
					return false;
					}
				}
			}
		}
	return true;
	}


vector<int> clique(int source){
	vector<int> result;
	for (int i=3;i<g.allNodes[source].size();i++){
		bool ifexit = true;
		for (vector<int> v : bfs(g.allNodes[source]->friends.size(),i)){
			vector<int> temp;
			for (int i : v){
				temp.push_back(g.allNodes[source]->friends[i]->nodeID);
			}
			if (checkfriends(temp)){
				result = temp;
				ifexit=false;
			}
		}
		if(ifexit){
			return result;	
		}
	}
}

