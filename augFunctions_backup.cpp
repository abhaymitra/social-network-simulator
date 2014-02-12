#include <iostream>     // std::cout
#include <algorithm>    // std:set_union, std:sort
#include "augFunctions.h"


#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

using namespace std ;

string firstNamesA[] = {"Aakash","Aaravamuthan","Abhay","Aarthi","Aarya","Aashika","Aashish","Abha","Abhas","Abhigyan","Abhijatya","Abhilash","Abhinandan","Abhinav","Abhinay","Abhinit","Abhishek","Adarsh","Adesh","Adi","Adipika","Aditi","Aditya","Aishwarya","Ajey","Ajith","Ajeet","Akhila","Akhilesh","Akshata","Akshay","Alikesh","Alpesh","Amal","Aman","Amani","Amar","Ambar","Amit","Amol","Amulya","Anant","Ananthu","Anindita","Animesh","Anirudh","Anish","Anitha","Anjana","Anjali","Anjan","Anjana","Anju","Anjum","Ankan","Ankita","Anmol","Annapoorna","Anoop","Anshul","Anshuman","Anu","Anubhuti","Anup","Anupam","Anupama","Anuradha","Anurag","Aparna","Apoorva","Aravind","Aravinda","Archana","Arihant","Arindam","Arjun","Arpita","Arnav","Arshad","Arun","Aruna","Aravind","Asawari","Aseem","Asha","Ashesh","Ashish","Ashu","Ashvin","Babita","Bandheka-","Babu","Babul","Bablu","Bala","Balaram","Balram","Banti","Basanti","Beena","Bhagya","Bhagyashri","Bhairavi","Bhalchandra","Bharani","Bharat","Bharath","Bharathi","Bhargavi","Bhaskar","Bhaskara","Bhavani","Bhavna","Bhooma","Bhoomika","Bhoominathan","Bhushan","Bibek","Billu","Bikram","Bikshapathi","Bimala","Bina","Bindu","Bineeta","Biran","Bodhisatva","Bhola","Chaitra","Chandana","Chandni","Chandra","Chandrakant","Chandraprabha","Chandrashekhar","Charu","Chetan","Chetana","Chilkoja","Chirasmita","Chithra","Chitrasen","Chudamani","Damodar","Deepa","Deepika","Deepti","Deepak","Deven","Devendra","Devi","Dhanalakshmi","Dhanush","Dhanya","Dhara","Dharani","Dharma","Dharshan","Dharshini","Dhwani","Dikpal","Dilip","Dimitri","Dipa","Dipti","Divya","Draupadi","Divyajyoti","Esha","Eshwar","Ehsaan","Emaraan","Gagana","Gajalakshmi","Gajanand","Ganesh","Ganesha","Ganga","Gauri","Gayathri","Gayatri","Geeta","Geetika","Girish","Godavari","Gopal","Gopinath","Govind","Greisha","Grisha","Haran","Harendra","Harika","Harmeet","Harpreet","Harsha","Harshan","Hashmeet","Hasini","Hansa","Hari","Hetal","Himanshu","Himesh","Hrishikesh","Hrithik","Hushmeet","Ira","Ish","Isha","Ishan","Ishani","Ishant","Ishanika","Ishvinder","Jaagruthi","Jagadish","Jai","Jaikanth","Jaishankar","Jasraj","Jayalalitha","Jayakumar","Jayanthi","Jayashree","Jayendra","Jayesh","Jaykishan","Jayshree","Jeet","Jeevan","Jekishan","Juhi","Kadhir","Kadhiresan","Kamal","Kamakshi","Kamaraj","Kanchana","Kandhan","Kanthi","Kanupriya","Kapil","Karan","Karthee","Karthika","Karthikeyan","Karunanidhi","Kaushik","Kavel","Kaveri","Kavitha","Kavya","Keerthi","Keshav","Keshavan","Ketan","Kiran","Kishan","Komal","Komudi","Krishna","Krithika","Kruthika","Kush","Lakshmana","Lakshmi","Lalit","Lalitha","Latha","Lav","Laya","Leela","Leena","Mahima","Malathi","Manas","Manav","Mandira","Mangala","Mangesh","Manish","Manisha","Manjula","Manjunath","Manohar","Manoj","Manpreet","Mansha","Maya","Mayank","Mayuri","Narayanan","Naren","Naresh","Narendra","Naveed","Naveen","Neal","Neel","Neelam","Neeli","Neelima","Neema","Neeraj","Neeraja","Neha","Nehal","Nihal","Nihar","Nihit","Nikhil","Parag","Paramjit","Paras","Parna","Parthasarathi","Parvati","Pompy","Pooja","Poornima","Prabha","Prachi","Pradeep","Prafulla","Pragati","Pragya","Prahlad","Prajakta","Prajna","Prakash","Pramila","Pramit","Pramod","Pran","Pranav","Pranay","Pranil","Praneel","Prapanna","Prarthna","Prasad","Prasanna","Prashant","Prathap","Pratibha","Pratik","Pratiksha","Pratima","Pratyush","Praveen","Preeta","Preetam","Preethi","Preeti","Prem","Prema","Pritam","Prithwish","Priya","Priyadarshini","Rahul","Radhalakshmi","Radhika","Raghu","Raghuram","Rahul","Raja","Rajalakshmi","Rajani","Rajarajeshwari","Rajaraman","Rajasekhar","Rajat","Rajesh","Rajnigandha","Rajini","Raju","Rajul","Raka","Rakesh","Ram","Rama","Raman","Ramachandra","Ramakanth","Ramakrishna","Raman","Ramani","Ramdev","Ramesh","Rameshwara","Ramu","Rani","Ranjini","Ranjit","Rashmi","Rasika","Rathnakar","Raveena","Ravi","Sachin","Sachita","Sadhana","Sagnik","Saket","Saketh","Samarchita","Sameer","Samir","Sampada","Samyukta","Sandeep","Sanjay","Sanjeev","Sanjeevini","Sankalp","Santhanalakshmi","Santhosh","Sapan","Sarasvati","Sarwagya","Satya","Satyanarayana","Saumya","Saurav","Sayali","Seetha","Shailaja","Shailendra","Shalaka","Shalmali","Shamira","Shamsunder","Shankar","Shanta","Shanti","Sharad","Sharada","Sharath","Sharmeela","Shashank","Shashi","Shaunak","Shauni","Sheela","Sheetal","Shefali","Shekhar","Sheshi","Sheshikala","Shiladitya","Shilpa","Shivani","Shivankush","Shivranjani","Shobha","Shraddha","Shree","Shreedhan","Shreerang","Shreya","Shreyas","Shridhar","Shrinath","Shrinivas","Shruti","Shubhada","Shubhashree","Shuili","Shunmugha","Shweta","Shyam","Shyamala","Siddharth","Siddhartha","Sita","Sitaram","Smitha","Sneha","Snigdha","Soheb","Soma","Sooraj","Soumen","Soumitra","Soumya","Sowjanya","Sravan","Sridhar","Srihith","Srikanth","Srinath","Tajinder","Tanvi","Tapas","Tara","Tarun","Thamizhselvan","Thamizhselvi","Theerth","Tina","Trilokesh","Trivikram","Trupti","Trushar","Tushar","Ujwala","Ulaganathan","Uma","Umesh","Urmila","Urvasi","Urvi","Usha","Utkarsha","Utpala","Uday","Udaya","Udayan","Vaishali","Vaishnavi","Vaman","Vandana","Vani","Vanya","Varad","Vardhman","Varna","Varsha","Varun","Vasudha","Vibhu","Vidhi","Vidhya","Vidya","Vijay","Vijaya","Vijesh","Vikalpa","Vikas","Vikram","Vinatha","Vinay","Vinod","Vinu","Viraj"};
string lastNamesA[] = {"Sharma","Verma","Gupta","Malhotra","Bhatnagar","Saxena","Kapoor","Singh","Mehra","Chopra","Sarin","Malik","Chatterjee","Sen","Bose","Sengupta","Das","Dasgupta","Banerjee","Chattopadhyay","Mukopadhyay","Dutta","Nair","Pillai","Rao","Jayaraman","Venkatesan","Balasubramanium","Subramanium","Rangan","Rangarajan","Singh","Yadav","Jhadav","Jaiteley","Chauhan","Mistry","Khan","Shah","Mehta","Patel","Patil","Pawar","Gavde","Kadam","Tambe","Chavan"};

vector<string> firstNames(firstNamesA,firstNamesA+ARRAY_SIZE(firstNamesA));
vector<string> lastNames(lastNamesA,lastNamesA+ARRAY_SIZE(lastNamesA));

string nameGenerator(void){
  string firstName = firstNames[rand()%firstNames.size()];
  string lastName = lastNames[rand()%lastNames.size()];
  return (firstName+" " +lastName);
}

bool myfunction (Node* i,Node* j) { return (i->nodeID<j->nodeID); } 


void printArray(vector<Node*> a){
	for(int i=0 ;i <a.size() ; i++ ){
		cout << a[i]->name <<" " << a[i]->roomNo << " " << a[i]->department->name<< " Node ID: "<< a[i]->nodeID<<endl ;
    }
}


vector<Node*> setUnion(vector<Node*>array1,vector<Node*>array2) {
int l = array1.size() + array2.size() ;
  std::vector<Node*> v(l); 
  std::vector<Node*>::iterator it;
  sort (array1.begin(),array1.end(),myfunction);
  sort (array2.begin(),array2.end(),myfunction);
	it=set_union(array1.begin(), array1.end(), array2.begin(), array2.end(), v.begin(),myfunction); 
  v.resize(it-v.begin());
  return v;
}

vector<Node*> setIntersection(vector<Node*>array1,vector<Node*>array2) {  
	int l = array1.size() + array2.size() ;
  std::vector<Node*> v(l);
  std::vector<Node*>::iterator it;
  sort (array1.begin(),array1.end(),myfunction);
  sort (array2.begin(),array2.end(),myfunction);
 	it=set_intersection(array1.begin(), array1.end(), array2.begin(), array2.end(), v.begin(),myfunction);
  v.resize(it-v.begin());
  return v;
}

vector<Node*> setDifference(vector<Node*>array1,vector<Node*>array2) {  
	int l = array1.size() + array2.size() ;
  std::vector<Node*> v(l);
  std::vector<Node*>::iterator it;
  sort (array1.begin(),array1.end(),myfunction);
  sort (array2.begin(),array2.end(),myfunction);
 	it=set_difference(array1.begin(), array1.end(), array2.begin(), array2.end(), v.begin(),myfunction);
  v.resize(it-v.begin());

  return v;
}

vector<int> genInterestList(University* uni){
  vector<int> temp;
  for (InterestProbabilities ip : uni->interestProbabilities){
    if(rand()%100<(0.1)*100){
      temp.push_back(ip.interestIndex);
    }
  }
  return temp;
}


vector<Node*> getPeopleWithSameInterest(Node* n){
  vector<Node*> similarInterestPeople;
  for (int i : n->interests){
    vector<Node*> temp = similarInterestPeople;
    similarInterestPeople = setUnion(temp,n->graph->interestList[i]); 
  }
  return similarInterestPeople;
}

vector<Node*> getPeopleInSameCourse(Node* n){
  vector<Node*> allCourseStudents;
  for (Course* c: n->currentCourses){
    vector<Node*> temp = allCourseStudents;
    allCourseStudents = setUnion(temp,c->enrolledStudents);
    if(n->ifStudent){
      allCourseStudents.push_back(c->currentFaculty);
    }
  }
  return allCourseStudents;
}

void removeSelf(vector<Node*> *v,Node* n){
  for (int i=0;i<v->size();i++){
    if(v->at(i)->nodeID == n->nodeID){
      v->erase(v->begin()+i);
      return;
    }
  }
  return;
}


void updateNonNetwork(Node* n){
  vector<Node*> temp;
  vector<Node*> course_hostel;
  if(n->ifStudent){
    course_hostel = setUnion(getPeopleInSameCourse(n),n->hostel->residents);
  }
  else{
    course_hostel = setUnion(getPeopleInSameCourse(n),n->houseLocality->residents);
  }
        vector<Node*> course_hostel_interest = setUnion(course_hostel,getPeopleWithSameInterest(n));
        vector<Node*> network = setUnion(course_hostel_interest,n->department->allStudents);
        network.insert(network.end(),n->department->allFaculty.begin(),n->department->allFaculty.end());
        network = setUnion(network,n->friends);
        n->nonNetwork.resize(0);
        temp = setDifference(n->graph->allNodes,network);
        n->nonNetwork.insert(n->nonNetwork.end(),temp.begin(),temp.end());
        n->sameCourse.resize(0);
        temp = getPeopleInSameCourse(n); 
        n->sameCourse.insert(n->sameCourse.end(),temp.begin(),temp.end());
        temp = getPeopleWithSameInterest(n);
        n->sameInterests.insert(n->sameInterests.end(),temp.begin(),temp.end());   
       // removeSelf(&(n->nonNetwork),n);
}