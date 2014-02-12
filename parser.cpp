//============================================================================
// Name        : parser.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>
#include <algorithm>
#include <vector>
#include "graph.h"
#include "Node.h"
#include <limits.h>
#include <stdio.h>

using namespace std;

long fsize(FILE* binaryStream)
{
  long ofs, ofs2;
  int result;

  if (fseek(binaryStream, 0, SEEK_SET) != 0 ||
      fgetc(binaryStream) == EOF)
    return 0;

  ofs = 1;

  while ((result = fseek(binaryStream, ofs, SEEK_SET)) == 0 &&
         (result = (fgetc(binaryStream) == EOF)) == 0 &&
         ofs <= LONG_MAX / 4 + 1)
    ofs *= 2;

  /* If the last seek failed, back up to the last successfully seekable offset */
  if (result != 0)
    ofs /= 2;

  for (ofs2 = ofs / 2; ofs2 != 0; ofs2 /= 2)
    if (fseek(binaryStream, ofs + ofs2, SEEK_SET) == 0 &&
        fgetc(binaryStream) != EOF)
      ofs += ofs2;

  /* Return -1 for files longer than LONG_MAX */
  if (ofs == LONG_MAX)
    return -1;

  return ofs + 1;
}

/* File must be open with 'b' in the mode parameter to fopen() */
/* Set file position to size of file before reading last line of file */
char* fgetsr(char* buf, int n, FILE* binaryStream)
{
  long fpos;
  int cpos;
  int first = 1;

  if (n <= 1 || (fpos = ftell(binaryStream)) == -1 || fpos == 0)
    return NULL;

  cpos = n - 1;
  buf[cpos] = '\0';

  for (;;)
  {
    int c;

    if (fseek(binaryStream, --fpos, SEEK_SET) != 0 ||
        (c = fgetc(binaryStream)) == EOF)
      return NULL;

    if (c == '\n' && first == 0) /* accept at most one '\n' */
      break;
    first = 0;

    if (c != '\r') /* ignore DOS/Windows '\r' */
    {
      unsigned char ch = c;
      if (cpos == 0)
      {
        memmove(buf + 1, buf, n - 2);
        ++cpos;
      }
      memcpy(buf + --cpos, &ch, 1);
    }

    if (fpos == 0)
    {
      fseek(binaryStream, 0, SEEK_SET);
      break;
    }
  }

  memmove(buf, buf + cpos, n - cpos);

  return buf;
}

int max_id(char* filename)
{
  FILE* f;
  long sz;
  char buf[256];
 f = fopen(filename, "rb");

  sz = fsize(f);
//  printf("file size: %ld\n", sz);

  if (sz > 0)
  {

    fseek(f, sz, SEEK_SET);

for(int i=0;i<3 ; i++){
   //  printf("%s", buf);
	 fgetsr(buf, sizeof(buf), f) ;
	if(i==2){
		string line = buf;
		size_t found1 = line.find("\"") ;
		size_t  found2 = line.find("\"",found1+1) ;
		string first = line.substr(found1+2,found2) ;
	 	first = first.substr(0,found2-found1-2) ;
	//	cout << atoi(first.c_str()) << endl;
	return atoi(first.c_str());
	}
}
  }
}



string substring(string l , int i1 ,int i2){
	string l1 = "" ;
//	cout << i1 <<"  " << i2 << endl ;
for(int i=i1;i1<i2;i++){
l1=l1+l.at(i) ;
//cout << l.at(i)  << endl ;
//cout <<  i2 <<endl ;
//cout << i <<endl ;
}
return l1 ;
}
int read(char* filename, Graph* g){
	int graphsize = max_id(filename)+1;
	for(int i =0;i<graphsize;i++){
		Node* n = new Node();
		g->allNodes.push_back(n);
	}
	string line = "" ;
		ifstream myfile(filename,ios::in) ;
		if(myfile.good()){    // if check(file) is present
				while(myfile.good()){
					getline(myfile,line) ;
				//	cout << line << endl ;
					size_t found = line.find("\"") ;
					string node1 ="<node id=" ;
					string node2 = line.substr(0,found) ;
					if(strcmp(node1.c_str(),node2.c_str())==0){
					//	cout << "node id found" << endl;
						found = line.find("\"") ;
						size_t	fo = line.find("\"",found+1);
						string l= line.substr(found+2,fo) ;
						 l= l.substr(0,fo-found-2) ;
						// cout << "l = " <<  l <<endl ;
						int ID = atoi(l.c_str());
						// cout << "line = " <<  line <<endl ;
							getline(myfile,line) ;
							found = line.find(">") ;
							fo = line.find("<",found);
						// cout <<   fo <<endl ;
						 l= line.substr(found+2,fo) ;
						 l= l.substr(0,fo-found-2) ;

						// cout << "l = " <<  l <<endl ;
						g->allNodes[ID]->name = l;
						// cout << "line = " <<  line <<endl ;
							getline(myfile,line) ;
							found = line.find(">") ;
							fo = line.find("<",found);
						// cout <<   fo <<endl ;
						 l= line.substr(found+2,fo) ;
						 l= l.substr(0,fo-found-2) ;
						// cout << "l = " <<  l <<endl ;
						g->allNodes[ID]->uni = l;
						// cout << "line = " <<  line <<endl ;
							getline(myfile,line) ;
							found = line.find(">") ;
							fo = line.find("<",found);
						// cout <<   fo <<endl ;
						 l= line.substr(found+2,fo) ;
						 l= l.substr(0,fo-found-2) ;
						// cout << "l = " <<  l <<endl ;
						// cout << "line = " <<  line <<endl ;

							getline(myfile,line) ;
							found = line.find(">") ;
							fo = line.find("<",found);
						// cout <<   fo <<endl ;
						 l= line.substr(found+2,fo) ;
						 l= l.substr(0,fo-found-2) ;
						// cout << "l = " <<  l <<endl ;
						// cout << "line = " <<  line <<endl ;
							getline(myfile,line) ;
							found = line.find(">") ;
							fo = line.find("<",found);
						// cout <<   fo <<endl ;
						 l= line.substr(found+2,fo) ;
						 l= l.substr(0,fo-found-2) ;
						// cout << "l = " <<  l <<endl ;
						// cout << "line = " <<  line <<endl ;
							getline(myfile,line) ;
							found = line.find(">") ;
							fo = line.find("<",found);
						// cout <<   fo <<endl ;
						 l= line.substr(found+2,fo) ;
						 l= l.substr(0,fo-found-2) ;
						// cout << "l = " <<  l <<endl ;
						// cout << "line = " <<  line <<endl ;
							getline(myfile,line) ;
							found = line.find(">") ;
							fo = line.find("<",found);
						// cout <<   fo <<endl ;
						 l= line.substr(found+2,fo) ;
						 l= l.substr(0,fo-found-2) ;
						// cout << "l = " <<  l <<endl ;
						// cout << "line = " <<  line <<endl ;

						
					
					}
				else{

						// cout << "in else condition " << endl ;
						found = line.find("\"") ;
						string check = line.substr(0,found) ;
						string friends = "<edge source=" ;
						// cout << "check = " << check << endl ;
						// cout << "friends = " << friends << endl ;
						if(strcmp(check.c_str(),friends.c_str())==0){
							// cout << "friends condition" << endl ;
							size_t found1 = line.find("\"",found+1) ;
							size_t  found2 = line.find("\"",found1+1) ;
							size_t  found3 = line.find("\"",found2+1) ;
							 string first = line.substr(found+2,found1) ;
						 	first = first.substr(0,found1-found-2) ;
						 	string second = line.substr(found2+2,found3) ;
						 	second = second.substr(0,found3-found2-2) ;
						 	g->allNodes[0]->addFriend(g->allNodes[atoi(first.c_str())],g->allNodes[atoi(second.c_str())]);
						 	 // cout << "first = " << first << endl ;
						 	 // cout << "second = " << second << endl ;
}
}
					
}
				}
}


// int main() {
// Graph* g = new Graph();
// read("graph.graphml",g);
// for ( int i=0;i<1500;i++){
// 	cout << "Friends of	" <<  i << " :	"<< g->allNodes[i]->friends.size() << endl;
// }
// return 0;
// }
