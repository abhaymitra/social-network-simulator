#include <vector>
#include <iostream>
using namespace std;

Graph g;
int totalNumberOfNodes=g.allNodes.size();
int vertices = totalNumberOfNodes;
vector<vector<int> > a(vertices, vector<int>(vertices,999999999)); //array containing the shortest distances
vector<vector<int> > v(vertices, vector<int>(vertices,-1));  // the predecessor matrix
vector<vector<vector<int> > > r;

//gives a 1D vector containing the vertices between shortest path from i to j
vector<int> path(int i, int j){
	vector<int> ans;
	if (i==j){
		cout<<"invalid"<<endl;
	}

	int c=j;
	while (c!=i) {
			int t=v[i][c];
			ans.push_back(t);
			c=t;
	}
	return ans;
}

// returns a 3D vector containing the vector having all the vertices between i and j(shortest path)
vector<vector<vector<int> > > f(){
	for (int i=0;i<vertices;i++){
		vector<vector<int > > e;
		for (int k=0;k<vertices;k++){
			e.push_back(path(i,k));
		}
		r.push_back(e);
	}
	return r;
}

// prints all the vertices in the shortest path between i and j;
void print(vector<int> x){
	int i=0;
	cout<<x[i]<<endl;
	i++;
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
	print(path(4,1));
	return 0;
}
