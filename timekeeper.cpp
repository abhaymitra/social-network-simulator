#include "timekeeper.h"
#include <iostream>       // std::cout
#include "graphml.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <fstream>
#include <string.h>
#include <string>
#include <random>


using namespace std;
#define SCK_VERSION1            0x0101
#define SCK_VERSION2            0x0202

std::default_random_engine generator;
std::exponential_distribution<double> distribution(0.1);


//This typedef will be filled out when the function returns

//CONNECTTOHOST  Connects to a remote host
int* ConnectToHost(int PortNo, char* IPAddress)
{
	int s;

    sockaddr_in target; //Socket address information

    target.sin_family = AF_INET; // address family Internet
    target.sin_port = htons (PortNo); //Port to connect on
    target.sin_addr.s_addr = inet_addr (IPAddress); //Target IP

    s = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP); //Create socket
    if (s <0)
    {
        return NULL; //Couldn't create the socket
    }

    //Try connecting...

    if (connect(s, (sockaddr *)&target, sizeof(target))<0)
    {
        return NULL; //Couldn't connect
    }
    else{

        return &s; //Success
    }
}

//CLOSECONNECTION  shuts down the socket and closes any connection on it
void CloseConnection (int s)
{
    //Close the socket if it exists

    if (s)
        close(s);


}


int send_sign(int p , char* mystring , int length){
	int iResult = send( p, mystring, length, 0 );
		    if (iResult<0) {
		        cout << "send failed" <<endl ;
		        close(p);
		        return 1;
		    }

		    printf("Bytes Sent: %ld\n", iResult);
//		    iResult = shutdown(p, SD_SEND);
		       if (iResult <0) {
		           cout <<" shutdown failed" << endl ;
		           close(p);

		           return 1;
		       }

		    return 0 ;
}


int  receive(int p,char* rec, int rec_len){
	int  iResult = recv(p, rec, rec_len, 0);
	        if ( iResult > 0 ){
	            printf("Bytes received: %d\n", iResult);
	            cout << "Data received " << rec << endl ;
	        }
	return 0;
}
long MaxTime;

long Time;

struct request
{
public:
	long Time;
	int whichThread;
	int argument;
	request(long t,int n){Time=t;whichThread=n;};
	request(){};
};

struct Comparator
{
  bool operator()(const request& lhs, const request& rhs)
  {
  	if(lhs.Time==rhs.Time){
  		return lhs.whichThread > rhs.whichThread;
  	}
  	else{
   	 	return lhs.Time>rhs.Time;
   	}
  }
};

priority_queue<request,vector<request>,Comparator> timeHeap;

void setAlarm(long Time, int n){
	request r = request(Time,n);
	if((r.Time < MaxTime)&&(r.Time>=Time)){
		timeHeap.push(r);
	}
}


time_t now ;


void init(int numDays){
	now = time(0);
	Time=(long) now;
	//cout << "Setting up Environment... Generating Faculty ..." << endl;
	MaxTime = Time + numDays*24*60*60;
	// graph = new Graph();
	// graph->ifFirstSemester = true;
	// s = setEnvironment();
	// s.g = graph;
	// string sample=s.convert_to_string("example");
	// s.create_all(sample);
	// initLog();
	// genFaculty(graph);
	setAlarm(Time,1);
	setAlarm(Time,2);
	setAlarm(Time,3);
	// for (vector<Node*> v : graph->interestList){
	// 	for (Node* n: v){
	// 		cout << n->name << "	"<< n->university->name << endl;
	// 		// << "	" << graph->reverseMap.find(i.interestIndex)
	// 	}
	// 	cout << "#####################"  << endl;
	// }
	
}
int exit(){
	// saveGraph(graph);
	// closeLog();
	// save Graph as XML File
	return 0;
}



void run(){
	char * l  = "127.0.0.1" ;
	int p =*ConnectToHost(60000,l) ;
	char rec[512] ;
	char* sign ;
	string s  ;
	while (!timeHeap.empty()){
		request req = timeHeap.top();
		timeHeap.pop();
		Time = req.Time;
		request r;
		switch(req.whichThread){
			case 1: 	// generate Students
				s = to_string(Time) + "#" ;
				strcpy(sign, s.c_str());                  // # string case 1
	            send_sign(p,sign,strlen(sign)) ;
                receive(p,rec,sizeof(rec)) ;
               // CloseConnection(p);
				//graph->currentTime = Time;
				//genStudents(graph);
				setAlarm(Time+365*60*60*24,1);
				break;
			case 2:		// setCourses
				
				s = to_string(Time) + "$" ;
				strcpy(sign, s.c_str());                        // $ string case 2
	            send_sign(p,sign,strlen(sign)) ;
                receive(p,rec,sizeof(rec)) ;
             //   CloseConnection(p);
				//graph->currentTime = Time;
				//floatCourses(graph);
				//setCourses(graph);
				setAlarm(Time+365*60*60*12,2);
				break;
			case 3:		// setFriends
				cout << "Time:	" << (Time - now)/(60*24) << endl;
				s = to_string(Time) + "%" ;
				strcpy(sign, s.c_str());             // % string case 3
	            send_sign(p,sign,strlen(sign)) ;
                receive(p,rec,sizeof(rec)) ;
              //  CloseConnection(p);
				//graph->currentTime = Time;
				//setFriends(graph);
				cout << ceil(distribution(generator)) << endl;
				setAlarm(Time + 60*(ceil(distribution(generator))),3);
				break;
		}
	}
	s = to_string(Time) + "&" ;
				strcpy(sign, s.c_str()); 
	strcpy(sign, s.c_str());             // % string case 3
	send_sign(p,sign,strlen(sign)) ;
	exit();
}

int main(int argc, char** argv){
	int arg = atoi( argv[1] );
	init(arg);
	run();
	return 0;
}
