#include <iostream>
#include <string>
#include <queue>    
#include <vector>
#include <algorithm>
#include "graph.h"


#ifndef INFINITY
#define INFINITY 65535
#endif /* INFINITY */


using namespace std;


Graph* g;


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

    // initialize the dist of each node as infinity and visited status as false
    for (int i = 0; i < size;   i) 
    {
        dist[i] = INFINITY;
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
            if(graph[node][i]!=0)
            {
                // Update the distance if it is smaller than the current distance
                if(dist[i] > (dist[node] + graph[node][i]))
                    dist[i] = dist[node] + graph[node][i];

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




int main(int argc, char** argv){
    return 0;
}