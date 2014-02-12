
#ifndef READER_H_
#define READER_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include "graph.h"


class setEnvironment{
public:
	Graph* g ;
	int University_counter=0;
	string main_string;
	void print_University(vector<University*> v);
	void print_Department(vector<Department*> v);
	void print_Course(vector<University*> v);
	void print_Interest(map<string,int> v);
	void print_hostels(vector<Hostel*> v);
	void  print_houseLocalities(vector<HouseLocality*> v);
	string convert_to_string(const char* filename_read);
	void read_string(string s);
	vector<int> create_indices(string s);
	vector<string> f(string s);
	void create_all(string s);
};

#endif /* READER_H_ */