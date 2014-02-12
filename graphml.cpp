
#include <fstream>
#include <iostream>
#include "graphml.h"
#include "augFunctions.h"

using namespace std;

ofstream file;



void saveGraph(Graph* g){
  file.open("graph.graphml");
  file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?> "<< "\n" <<"<graphml xmlns=\"http://graphml.graphdrawing.org/xmlns\""<<"\n"<< "xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"" << "\n" << "xsi:schemaLocation=\"http://graphml.graphdrawing.org/xmlns"<<"\n"<<"http://graphml.graphdrawing.org/xmlns/1.0/graphml.xsd\">"<<endl;
  file << "<key id=\"d0\" for=\"node\" attr.name=\"name\" attr.type=\"string\"/> "<< endl;
  file << "<key id=\"d1\" for=\"node\" attr.name=\"university\" attr.type=\"string\"/> "<< endl;
  file << "<key id=\"d2\" for=\"node\" attr.name=\"department\" attr.type=\"string\"/> "<< endl;
  file << "<key id=\"d3\" for=\"node\" attr.name=\"locality\" attr.type=\"string\"/> "<< endl;
  file << "<key id=\"d4\" for=\"node\" attr.name=\"studentorfaculty\" attr.type=\"string\"/> "<< endl;
  file << "<key id=\"d5\" for=\"node\" attr.name=\"entryYear\" attr.type=\"string\"/> "<< endl;
  file << "<key id=\"d6\" for=\"node\" attr.name=\"ID\" attr.type=\"int\"/> "<< endl;
  file << "<graph id=\"G\" edgedefault=\"undirected\">" << endl;
  for (Node* n: g->allNodes){
    file << "<node id=\" " << n->nodeID << "\" >" << endl;
    file << "<data key=\"d0\"> " << n->name << "</data>"<<endl;
    file << "<data key=\"d1\"> " << n->university->name << "</data>" << endl;
    file << "<data key=\"d2\"> " << n->department->name << "</data>" <<endl;
    if(n->ifStudent){
      file << "<data key=\"d3\"> " << n->hostel->name << "</data>" << endl;
      file << "<data key=\"d4\"> " << "Student" << "</data>" <<endl;
      file << "<data key=\"d6\"> " << n->studentID << "</data>" << endl;
    }
    else{
      file << "<data key=\"d3\"> " << n->houseLocality->name << "</data>" << endl;
      file << "<data key=\"d4\"> " << "Faculty" << "</data>" <<endl; 
      file << "<data key=\"d6\"> " << n->facultyID << "</data>" << endl;
    }
    file << "<data key=\"d5\"> " << n->entryYear << "</data>" <<endl; 
    file << "</node>" << endl;
    Sort(&n->friends);
    for (Node* friendnode : n->friends){
      file << "<edge source=\" "<< n->nodeID <<"\" target=\" "<< friendnode->nodeID <<"\"/> " << endl;
    }
  }
  file << "</graph>" << endl;
  file << "</graphml>" << endl;
  file.close();
}