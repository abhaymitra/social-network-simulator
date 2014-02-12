/*!
 * \file
 *
 */

#include <vector>
#include <iostream>
using namespace std;

/*! \fn createAdjacencyList(Graph g)
 * \brief creates an adjacency list containing all the nodes with their friend list
 * @param Graph containing all the nodes of the graph
 * @return vector<vector<int> > The vector of vectors containing the adjacency list
 */

vector<vector<int> > createAdjacencyList(Graph g){

	vector<Node*> nodesOfGraph=g.allNodes;
	int m=g.allNodes.size();  //total number of nodes in the graph
	vector<vector<int> > a(vertices, vector<int>(vertices,999999999));

	for (int i = 0; i < m; i++){
		vector<int> friendList;
		Node* x=findNode(i,g);
		for (int j = 0; j < m; j++){
			if (i!=j) {
				friendList.push_back(distance(x,findNode(j,g)));
			}
	    }
		a.push_back(friendList);
	}
	return a;
}
