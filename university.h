/*
 * university.h
 *
 *  Created on: 27-Sep-2013
 *      Author: xcv
 */

#include<stdio.h>
#include<string.h>
#include "math.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using std::string;
using std::cout;
using namespace std;

#ifndef UNIVERSITY_H_
#define UNIVERSITY_H_

class department{

	public:

	std::string name;
	int num_faculty;
	int num_students;
	float dep_courses;
	float non_dep_courses;

};

class course{

	public:

	string course_name;
	std::string department_that_offers;
	float frequency;

};

class interest{

	public:

	std::string name;
	float popularity;

};

class university{

	public:

	string name;
	std::vector<department> departments;
	std::vector<course> courses;
	vector<interest> interests;
	vector<string> hostel;
	vector<string> house_locality;
	float friendship_rate;
	float openness;
	float friendliness;

};



#endif /* UNIVERSITY_H_ */
