
#include "reader.h"

using std::cout;
using namespace std;



	/*prints the name of all the universities*/
	void setEnvironment::print_University(vector<University*> v){
		for (unsigned int i=0; i<v.size();i++){
			cout<<v[i]->name<<endl;
		  }
	}

	/*prints info about the departments present in a particular university*/
	void setEnvironment::print_Department(vector<Department*> v){
		for (unsigned int i=0; i<v.size();i++){
			cout<<v[i]->name<<" "<<v[i]->numFaculty<<" "<<v[i]->numStudents<<" "<<v[i]->departmentCoursesPerSemester<<" "<<v[i]->nonDepartmentCoursesPerSemester<<endl;
		  }
	}

	/*prints info about the courses present in a particular university*/
	void setEnvironment::print_Course(vector<University*> v){
		for (unsigned int i=0; i<v.size();i++){
			vector<Department*> w=v[i]->departments;

			for (unsigned int j=0; j<w.size();j++){

				vector<Course*> u=w[j]->allCourses;

				for (unsigned int k=0; k<u.size();k++){
					cout<< v[i]->name<< " "<< w[j]->name<<" "<<w[j]->allCourses[k]->name<<" "<<w[j]->allCourses[k]->parentDepartment->name <<" "<<w[j]->allCourses[k]->frequencyPerYear<<endl;
				}
			}
		}
	}

	/*prints info about the interests present in a particular university*/
	void setEnvironment::print_Interest(map<string,int> v){
		for( map<string,int>::iterator ii=v.begin(); ii!=v.end(); ++ii)
	   {
	       cout << (*ii).first << ": " << (*ii).second << endl;
	   }

	}

	/*prints info about the hostels present in a particular university*/
	void setEnvironment::print_hostels(vector<Hostel*> v){
		for (unsigned int i=0; i<v.size();i++){
		    cout<<v[i]->name <<endl;
		  }
	}

	/*prints info about the house localities present in a particular university*/
	void  setEnvironment::print_houseLocalities(vector<HouseLocality*> v){
		for (unsigned int i=0; i<v.size();i++){
		    cout<<v[i]->name<<endl;
		  }
	}

	/*prints friendship rate etc. of a particular university*/
	// void print_misc(vector<University> v){
	// 	for (unsigned int i=0; i<v.size();i++){
	// 	    cout<<v[i].name<<" "<<v[i].friendship_rate<<" "<<v[i].out_probability<<" "<<v[i].recip_probability<<endl;
	// 	  }
	// }


	/* reads a file and converts the entire text to a single string */
	string setEnvironment::convert_to_string(const char* filename_read){
		string line;
		ifstream myfile (filename_read);



				  while (! myfile.eof()){
				          getline (myfile,line);
				          unsigned int c=0;
				          while ((c<line.length())&&(line[c]!='\n')){
				        	  c++;
				          }
				          string t=line.substr(0,c);
				          main_string=main_string+' '+t;
				  }
				  myfile.close();
				return main_string;
	}



	/*reads a given string(containing information about a single university),
	  finds the instances of universities, courses etc.
	  and puts them into their respective arrays*/
	void setEnvironment::read_string(string s){

		University_counter++;
		University* new_University = new University();
		g->universities.push_back(new_University);

		unsigned int i=0;

		vector<Department*> Department_array=g->universities[University_counter-1]->departments;
		map<string,int> Interest_array=g->interestMap;
		vector<Hostel*> hostels_array=g->universities[University_counter-1]->hostels;
		vector<HouseLocality*> houseLocalities_array=g->universities[University_counter-1]->houseLocalities;

		int Department_counter=0;
		int Interest_counter=0;
		int Course_counter=0;
		int hostels_counter=0;
		int houseLocalities_counter=0;


		while (i!=s.length()){

			if (s[i]=='U'){
				if (!s.substr(i,10).compare("UNIVERSITY")){

					unsigned int y=i+10;   //inner counter

					while (s[y]==' '){
						y++;
					}

					i=y;  //outer counter

					while ((y!=s.length())&&(s[y]!=' ')){
						y++;
					}

					string University_name=s.substr(i,y-i);
					g->universities[University_counter-1]->name=University_name;

					i=y;
				}
			}
			Department* new_department;
			if (s[i]=='D'){

					if (!s.substr(i,10).compare("DEPARTMENT")){
					new_department = new Department();
					vector<Course*> allCourses;

					int iteration=0;

					unsigned int y=i+10;   //inner counter
					while (iteration!=5){

						while (s[y]==' '){
							y++;
						}

						i=y;  //outer counter
						while ((y!=s.length())&&(s[y]!=' ')){
							y++;
						}

						string temp=s.substr(i,y-i);

						iteration++;

						if (iteration==1){
							new_department->name=temp;
						}

						if (iteration==2){
							int result;
							stringstream(temp) >> result;
							new_department->numFaculty=result;
						}

						if (iteration==3){
							int result;
							stringstream(temp) >> result;
							new_department->numStudents=result;
						}

						if (iteration==4){
							float result;
							stringstream(temp) >> result;
							new_department->departmentCoursesPerSemester=result;
						}

						if (iteration==5){
							float result;
							stringstream(temp) >> result;
							new_department->nonDepartmentCoursesPerSemester=result;
							g->universities[University_counter-1]->departments.push_back(new_department);
						}
					}
					i=y;
				}

				Department_counter++;
			}




			if (s[i]=='C'){

				if (!s.substr(i,6).compare("COURSE")){

				int iteration=0;

				unsigned int y=i+6;   //inner counter
				while (iteration!=3){
					while (s[y]==' '){
						y++;
					}

					i=y;  //outer counter

					while ((y!=s.length())&&(s[y]!=' ')){
						y++;
					}

					string temp=s.substr(i,y-i);
					i=y;

					iteration++;
					if (iteration==1){
						Course* new_course = new Course();
						new_course->name=temp;
						new_department->allCourses.push_back(new_course);
					}

					if (iteration==2){
						Department* parentDep = new_department;
						new_department->allCourses[new_department->allCourses.size()-1]->parentDepartment=parentDep;
					}

					if (iteration==3){
						float result;
						stringstream(temp) >> result;
						new_department->allCourses[new_department->allCourses.size()-1]->frequencyPerYear=result;
					}

				}

				}
				Course_counter++;
			}

			if (s[i]=='I'){

				if (!s.substr(i,8).compare("INTEREST")){

					int iteration=0;

					unsigned int y=i+8;   //inner counter
					while (iteration!=2){
						while (s[y]==' '){
							y++;
					}

					i=y;  //outer counter
					int noTemp;
					while ((y!=s.length())&&(s[y]!=' ')){
						y++;
					}

					string temp=s.substr(i,y-i);
					i=y;

					iteration++;
					if (iteration==1){

						noTemp = g->getInterestIndex(temp);
				
					}

					if (iteration==2){
						float result;
						stringstream(temp) >> result;
						InterestProbabilities ip = InterestProbabilities();
						ip.interestIndex = noTemp;
						ip.probability = result;
						bool ifthere = false;
						for(InterestProbabilities iploop : g->universities[University_counter-1]->interestProbabilities ){
							if(iploop.interestIndex == noTemp){
								iploop.probability = result;
								ifthere = true;
							}
						}
						if(!ifthere){
						g->universities[University_counter-1]->interestProbabilities.push_back(ip);
					}
					}
					}

				}
				Interest_counter++;
			}

			if (s[i]=='H'){

									if (!s.substr(i,6).compare("HOSTEL")){

									int iteration=0;

									unsigned int y=i+6;   //inner counter
									while (iteration!=1){
										while (s[y]==' '){
											y++;
										}

										i=y;  //outer counter

										while ((y!=s.length())&&(s[y]!=' ')){
											y++;
										}

										string temp=s.substr(i,y-i);
										i=y;

										iteration++;

										if (iteration==1){

											Hostel* new_hostel = new Hostel();
											new_hostel->name=temp;
											g->universities[University_counter-1]->hostels.push_back(new_hostel);
										}
									}
								hostels_counter++;
								}

						if (!s.substr(i,13).compare("HOUSELOCALITY")){

							int iteration=0;

							unsigned int y=i+13;   //inner counter
							while (iteration!=1){
								while (s[y]==' '){
									y++;
								}

								i=y;  //outer counter

								while ((y!=s.length())&&(s[y]!=' ')){
									y++;
								}

								string temp=s.substr(i,y-i);
								i=y;
								iteration++;

								if (iteration==1){

									HouseLocality* new_house_locality = new HouseLocality();
									new_house_locality->name=temp;
									g->universities[University_counter-1]->houseLocalities.push_back(new_house_locality);
									i=y;
								}
								houseLocalities_counter++;

							}
						}
			}



			if (s[i]=='F'){
				if (!s.substr(i,14).compare("FRIENDSHIPRATE")){

					unsigned int y=i+14;   //inner counter

					while (s[y]==' '){
						y++;
					}

					i=y;  //outer counter

					while ((y!=s.length())&&(s[y]!=' ')){
						y++;
					}

					string temp=s.substr(i,y-i);
					i=y;

					float result;
					stringstream(temp) >> result;
					g->universities[University_counter-1]->friendship_rate=result;
					}


				if (!s.substr(i,12).compare("FRIENDLINESS")){

								unsigned int y=i+12;   //inner counter
									while (s[y]==' '){
										y++;
									}

									i=y;  //outer counter

									while ((y!=s.length())&&(s[y]!=' ')){
										y++;
										}

									string temp=s.substr(i,y-i);
									i=y;

									float result;
									stringstream(temp) >> result;
									g->universities[University_counter-1]->recip_probability=result;
								}

							}

			if (!s.substr(i,8).compare("OPENNESS")){

							unsigned int y=i+8;   //inner counter
								while (s[y]==' '){
									y++;
								}

								i=y;  //outer counter

								while ((y!=s.length())&&(s[y]!=' ')){
									y++;
									}

								string temp=s.substr(i,y-i);
								i=y;

									float result;
									stringstream(temp) >> result;
									g->universities[University_counter-1]->out_probability=result;
						}
			else {
			i++;
			}
		}
		//print_University(g.universities);
		//print_Department(g.universities[0]->departments);
		//print_Course(g.universities);
		//print_Interest(Interest_array);
		//print_hostels(hostels_array);
		//print_houseLocalities(houseLocalities_array);

	}


	/*finds all instances of different universities and separates them*/
	vector<int> setEnvironment::create_indices(string s){

		vector<int> separate_strings;

		std::string str=s;
		std::string search="UNIVERSITY";
		for(std::string::size_type pos=0; pos<str.size(); pos+=search.size())
		{
		    pos=str.find(search, pos);
		    if(pos==std::string::npos)
		        break;

		    int new_University;
		    new_University=pos;
		    separate_strings.push_back(new_University);
		}

		return separate_strings;
	}


	vector<string> setEnvironment::f(string s){

		vector<int> p;
		p=create_indices(s);

		vector<string> d;

		unsigned int i=0;
		while (i!=p.size()){

				string x=s.substr(p[i],p[i+1]-p[i]);
				d.push_back(x);
				i++;
		}

		return d;
	}

	void setEnvironment::create_all(string s){

		vector<string> d=f(s);

		unsigned int i=0;
		while (i!=d.size()){
			read_string(d[i]);
			i++;
		}

	}


// int main(int argc, char *argv[]){
// 	setEnvironment s = setEnvironment();
// 	string sample=s.convert_to_string("example");
// 	s.create_all(sample);
// 	s.print_University(s.g.universities);
// 	s.print_Course(s.g.universities);
// 	//print_Department(g.universities[0]->departments);
// 	//print_misc(g.universities);

// }
