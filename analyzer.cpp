#include <iostream>
#include <string>
#include <queue>    
#include <vector>
#include <algorithm>
#include "graph.h"
#include "parser.h"


using namespace std;


#ifndef MAXX
#define MAXX 65535
#endif /* MAXX */



Graph* g;
int** b;
int** _distance;
int* importance;
int** path;

bool cached;

int dijkstrasize;
int totalNumberOfNodes;

int** createAdjacencyMatrix(){

    int m=g->allNodes.size();  //total number of nodes in the graph
    int** b;
    b = new int*[g->allNodes.size()];
    for ( int i =0;i<m;i++){
        b[i] = new int[m];
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            b[i][j]=MAXX;
            if(i==j){
                b[i][j]==0;
            }
            for (Node* n : g->allNodes[i]->friends){
                if (n->nodeID==g->allNodes[j]->nodeID){
                    b[i][j]=1;
                }
            }
        }
    } 

    return b;
}




void init(){
    b = new int*[g->allNodes.size()];
    for ( int i =0;i<g->allNodes.size();i++){
        b[i] = new int[g->allNodes.size()];
    };


    _distance = new int*[g->allNodes.size()];
    for (int i =0;i<g->allNodes.size();i++){
        _distance[i] = new int[g->allNodes.size()];
    };

    

    _distance = createAdjacencyMatrix() ;

    b = createAdjacencyMatrix();
    path = new int*[g->allNodes.size()];
    for ( int i =0;i<g->allNodes.size();i++){
        path[i] = new int[g->allNodes.size()];
    };
    for (int i =0;i<g->allNodes.size();i++){
        for (int j =0;j<g->allNodes.size();j++){
        path[i][j] = -1;
        };
    };
    for ( int i =0;i<g->allNodes.size();i++){
        for ( int j =0;j<g->allNodes.size();j++){
            if(i!=j && b[i][j]<MAXX){
                    path[i][j] = i;
        }
    }
}
    importance = new int[g->allNodes.size()];
   
    
}

void reader(){
    return;
}

void writer(){
    return;
}



/*Returns the pointer to node with a given NodeID*/
Node* findNode(int x){

	vector<Node*> nodesOfGraph=g->allNodes;
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



/**applies floyd-warshall over a given adjacency list*/
void floydwarshall(){
    int i,j,k;
    totalNumberOfNodes = g->allNodes.size();
    for (k = 0; k < totalNumberOfNodes; k++)
    {
        for (i = 0; i < totalNumberOfNodes; i++)
        {
            for (j = 0; j < totalNumberOfNodes; j++)
            {
                if (((_distance[i][k] * _distance[k][j] != 0) && (i != j))&&!(_distance[i][k]==(int) MAXX||_distance[j][k]==(int) MAXX))
                {
        
                    if ((_distance[i][k] + _distance[k][j] < _distance[i][j]) || (_distance[i][j] == 0))
                    {
                        _distance[i][j] = _distance[i][k] + _distance[k][j];
                        path[i][j]=path[k][j];
                    }
                }
            }
        }
    }
}


vector<int> getPath(int i,int j){
    vector<int> ans;
    if (i==j){
        cout<<"invalid"<<endl;
    }
    int c=j;
    while (c!=i) {
            int t = path[i][c];
            ans.push_back(t);
            c=t;
    }
    return ans;
}



void setImportance(){
    for ( int i =0; i<g->allNodes.size();i++){
        for ( int j =0; j<g->allNodes.size();j++){
            for ( int k =0; k<g->allNodes.size();k++){
                if(!((i==j) || (j==k))){
                    if(_distance[i][j]+_distance[j][k]==_distance[i][k]){
                        importance[j]+=1;
                    }
                }
            }
        }
    }
    for ( int i =0; i<g->allNodes.size();i++){
            importance[i] = importance[i]/2;
        }   
}




struct nodeDistance
{
    int node;
    unsigned int distance;
};

// This is the basis on which the elements of a priority queue are sorted and 
// kept in the queue, here the criteria is that the node with smaller distance should
// come above the one with larger distance

class CompareDist
{
    public:
        bool operator()(nodeDistance& n1, nodeDistance& n2)
        {
           if (n1.distance > n2.distance) 
                return true;
           else
                return false;
        }
};


unsigned int* dijkstra(int s, int size, int **graph) 
{    
    int mini;
    bool *visited = new bool [size];
    unsigned int *dist = new unsigned int [size];
    // initialize the dist of each node as MAXX and visited status as false
    for (int i = 0; i < size;   i++) 
    {
        dist[i] = MAXX;
        visited[i] = false;
    }

    // the distance of the source to itself is 0
    dist[s] = 0;

    // instantiate a priority queue with the structure and comparison criteria
    // as defined above
    priority_queue< nodeDistance, vector< nodeDistance >, CompareDist> pq;

    // Create the first node as the source and put it into the queue
    nodeDistance first = {s,0};
    pq.push(first);

    // While queue is not empty, pick the topmost node
    // using it's neighbors update the distance of each node that can be reached
    // and insert that node in the priority queue
    while(!pq.empty())
    {
        nodeDistance temp = pq.top();
        pq.pop();
        int node= temp.node;
        for(int i=0;i < size;i++)
        {
            if(graph[node][i]!=MAXX)
            {
                // Update the distance if it is smaller than the current distance
                if(dist[i] > (dist[node] + graph[node][i])){
                    dist[i] = dist[node] + graph[node][i];
                }
                // If not visited put it into the queue
                if(!visited[i])
                {
                    nodeDistance newNode;                   
                    newNode.node=i;
                    newNode.distance=dist[i];
                    pq.push(newNode);
                    visited[i]=true;
                }
            }
        }

    }
    return dist;
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
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            if(i!=j){
                if(b[v[i]][v[j]]!=1){
                    return false;
                    }
                }
            }
        }
    return true;
    }


vector<int> clique(int source){
    vector<int> result;
    if(g->allNodes[source]->friends.size()<=3){
        for (Node* n : g->allNodes[source]->friends){
            result.push_back(n->nodeID);
        };
        return result;
    }
    for (int i=1;i<g->allNodes[source]->friends.size();i++){
        bool ifexit = true;
        for (vector<int> v : bfs(g->allNodes[source]->friends.size(),i)){
            vector<int> temp;
            temp.push_back(source);
            for (int i : v){
                temp.push_back(g->allNodes[source]->friends[i-1]->nodeID);
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


void printClique(int nodeID){
    cout << "The clique of node " << nodeID << " consists of :" << endl;
   for(int i:clique(nodeID)){
    cout << "node " << i << "   |   ";
   }
   cout << "." << endl;
}


void printDijkstraLength(int n1,int n2){
    unsigned int* temp = dijkstra(n1,g->allNodes.size(),b);
    cout << "The length of the shortest path between node " << n1 << " and node " << n2 << " is "<<temp[n2]<< "."<<endl;

}

void printDijkstraPath(int n1,int n2){
    floydwarshall();

   vector<int> temp = getPath(n1,n2);
   cout <<"The people on the shortest path between node" << n1 << " and node " << n2 << " are:" << endl; 
    for (int i=0 ;i< temp.size();i++){
       cout << temp[i] << ", " ;
    }
    cout << "" << endl;
}

void setCachedTrue(){
    ofstream myfile ("cache.important");
    for(int i=0;i<g->allNodes.size();i++){
          if (myfile.is_open())
            {
                myfile << importance[i];
                myfile << ":";
              }

            else{
                cout << "Unable to open file";
            }
    }
    myfile.close();
    ofstream file;
    file.open("cache.temp");
    file << "1";
    file.close();
}


void setCached(){
    string line1;
    ifstream myfile("cache.temp",ios::in) ;
    if(myfile.good()){
        getline(myfile,line1) ;
    }
    if (atoi(line1.c_str())==1){
        string line = "" ;
        size_t found = 0 ;
        int c =0 ;
        ifstream myfile ("cache.important");
        if(myfile.good()){
            while(myfile.good()){
                getline(myfile,line) ;
                string newline = line ;
                for(int i =0 ; i < newline.length(); i++){
                    found = line.find(":");
                    if(line != ""){
                        string p = line.substr(0,found) ;
                        line = line.substr(found+1,line.length()) ;
                        int l = atoi(p.c_str()) ;
                        importance[c] = l ;
                        c++ ;
                    }
                    else{
                        break ;
                    }

            }
        }
    }
    else{
        cout << "cound not open a file" << endl ;
    }
        cached = true;
    }
    else {cached=false;}
}


void printImportance(int nodeID){
    if (cached){
        cout << "The importance of node "<< nodeID<< " is "<< importance[nodeID] <<"." << endl; 
    }
    else{
        floydwarshall();
        setImportance();
        setCachedTrue();
        cout << "The importance of node "<< nodeID<< " is "<< importance[nodeID] <<"." << endl;    
    }
}

void printMoreImportant(int nodeID){
    floydwarshall();
    setImportance();
    setCachedTrue();
    vector<Node*> temp = g->allNodes[nodeID]->friends;
    int maximum=0;
    for (int i=0;i<temp.size();i++){
        if(temp[i]>temp[maximum]){
            maximum = i;
        }
    }
    if(maximum<=importance[nodeID]){
        cout << "No friend of node "<< nodeID <<" is more important than him." << endl;
    }
    else{
        cout << "Node " << temp[maximum]->nodeID << ", a friend of node " << nodeID << "is more important than him." << endl;
    }

}

int main(int argc,char** argv){   
    g = new Graph();
    read("graph.graphml",g);
    init();
    setCached();
    int queryChoice = atoi(argv[1]);
    switch(queryChoice){
        case 1:
            printClique(atoi(argv[2]));
            break;
        case 2:
            printDijkstraLength(atoi(argv[2]),atoi(argv[3]));
            break;
        case 3:
            printDijkstraPath(atoi(argv[2]),atoi(argv[3]));         
            break;
        case 4:
            break;
        case 5:
            printImportance(atoi(argv[2]));
            break;
        case 6:
            printMoreImportant(atoi(argv[2]));
            break;
    }
    
 return 0;
}