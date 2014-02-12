#include "graph.h"
#include <iostream>
#include <string>

Graph g;
int totalNumberOfNodes=g.allNodes.size();
int vertices = totalNumberOfNodes;
vector<vector<int> > a(vertices, vector<int>(vertices,999999999));
vector<vector<int> > v(vertices, vector<int>(vertices,-1));

void path(int i, int j){
	if (i==j){
		cout<<v[i][j]<<endl;
	}
	if (i!=j) {
			path(i,v[i][j]);
			cout<<v[i][j]<<endl;
	}
}

/*creates an adjacency list of all the nodes of the graph where b[x][y]=distance between nodes x & y*/
int** createAdjacencyList(Graph g){

	vector<Node*> nodesOfGraph=g.allNodes;
	int m=g.allNodes.size();  //total number of nodes in the graph
	int b[m][m];

	for (int i = 0; i < m; i++){
		Node* x=findNode(i,g);
		for (int j = 0; j < m; j++){
			if (i==j){
				b[i][j]=0;
			}
			else {
				b[i][j]=distance(x,findNode(j,g));
			}
	    }
	}
	return b[m][m];
}

void initialise(){
	// initialize diagonal
		for(int i=0; i < vertices; i++)
			a[i][i]=0;

		a=createAdjacencyList(g);

		for(int i = 0; i < vertices; i++)
			for(int j = 0; j < vertices; j++)
				if(i!=j && a[i][j]<999999999){
					v[i][j] = i;
				}
}

/*returns the distance between two node pointers in a graph.
 * Note that the distance between a and b is 1 if they are friends. Otherwise, it is infinity*/
int distance(Node* a, Node* b){
	vector<Node*> f=a->friends;
	int i=0;
	while (i!=f.size()+1){
		if (f[i]==b){
			return 1;
			break;
		}
		else {
			i++;
		}
	}
	if (i==f.size()+1){
		return 999999999;
	}
}

/*Returns the pointer to node with a given NodeID*/
Node* findNode(int x,Graph g){

	vector<Node*> nodesOfGraph=g.allNodes;
	int i=0;
	while (i!=nodesOfGraph.size()+1){
		if (nodesOfGraph[i]->nodeID==x){
			return nodesOfGraph[i];
		}
		else {
			i++;
		}
	}
}

void flyodwarshall(){
		for(int k = 0; k < vertices; k++)
			for(int i = 0; i < vertices; i++)
				for(int j = 0; j < vertices; j++)
					if(a[i][j]>a[i][k]+a[k][j]){
						a[i][j]=a[i][k]+a[k][j];
						v[i][j]=v[k][j];
					}

		// Print out final distance matrix
		for(int i = 0; i < vertices; i++){
			for(int j = 0; j < vertices; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
		cout << endl;

		// Print out final predecessor matrix
		for(int i = 0; i < vertices; i++){
			for(int j = 0; j < vertices; j++)
				if(v[i][j]==-1)
					cout << -1 << " ";
				else
					cout << v[i][j]+1 << " ";
			cout << endl;
		}
		cout << endl;
}

int main(){
	initialise();
	flyodwarshall();
	path(4,2);
	return 0;
}

