#include <iostream>     // std::cout
#include <algorithm>    // std:set_union, std:sort
#include <vector>       // std::vector
#include <string>

using namespace std ;
//Compartor function
//bool myfunction (int i,int j) { return (i<j); } // i and j are the node  id of the respective node

bool myfunction (Node i,Node j) { return (i.nodeID<j.nodeID; } // function for string

// Print aaray function
void printArray(vector<Node> a){
	for(int i=0 ;i <a.size() ; i++ ){
		cout << a[i].name << endl ;
	}
}
int setUnion(vector<Node>array1,vector<Node>array2) {

  std::vector<string> v(13); // string vector array in which is to be stord
  std::vector<string>::iterator it;
  sort (array1.begin(),array1.end(),myfunction);
  sort (array2.begin(),array2.end(),myfunction);
 	 it=set_union (array1.begin(), array1.end(), array2.begin(), array2.end(), v.begin());
  	  v.resize(it-v.begin()); // trim result array
  return 0;
}

int setIntersection(vector<Node>array1,vector<Node>array2) {  // instead of string  Use your node here

 // instead of string  Use your node here
  std::vector<string> v(10);
  std::vector<string>::iterator it;
  sort (array1.begin(),array1.end(),myfunction);
  sort (array2.begin(),array2.end(),myfunction);
 	 it=set_intersection(array1.begin(), array1.end(), array2.begin(), array2.end(), v.begin());
  	  v.resize(it-v.begin());

  return 0;
}

int setDifference(vector<Node>array1,vector<Node>array2) {  // instead of string  Use your node here

 // instead of string  Use your node here
  std::vector<string> v(10);
  std::vector<string>::iterator it;
  printArray(array1) ;
  sort (array1.begin(),array1.end(),myfunction);
  sort (array2.begin(),array2.end(),myfunction);
 	 it=set_difference(array1.begin(), array1.end(), array2.begin(), array2.end(), v.begin());
  	  v.resize(it-v.begin());

  return 0;
}
int main(){
	vector<Node>a1 ;
	vector<Node>a2  ;
  for (int i=0;i++;i<10){
    Node n = new Node();
    
  }
	a1.push_back("a") ;
	a1.push_back("aa") ;
	a1.push_back("aaaa") ;

	a1.push_back("aaaaaaaaaaa") ;
	a1.push_back("aaaaa") ;
	//a1.push_back("a") ;

	a2.push_back("aa") ;
	a2.push_back("aaa") ;
	a2.push_back("a") ;
	a2.push_back("aaaaaaaa") ;
//	setDifference(a1,a2) ;
//	setUnion(a1,a2) ;
	printArray(a1,a2) ;

	return 0 ;
}
