#include <iostream>     // std::cout
#include <algorithm>    // std::set_union, std::sort
#include <vector>
#include <ctime>
#include <iostream>

       // std::cout
#include "graphml.h"
#include <ctime>
#include <stdlib.h>
#include "generateFaculty.h"
#include "augFunctions.h"
#include "generateStudents.h"
#include "setCourses.h"
#include "setFriends.h"


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


using namespace std ;


#define SCK_VERSION1            0x0101
#define SCK_VERSION2            0x0202

//This typedef will be filled out when the function returns


//LISTENONPORT  Listens on a specified port for incoming connections
//or data
int* ListenOnPort(int portno )
{

sockaddr_in addr ;
     // The address structure for a TCP socket

    addr.sin_family = AF_INET;      // Address family
    addr.sin_port = htons (portno);   // Assign port to this socket

    //Accept a connection from any IP using INADDR_ANY
    //You could pass inet_addr("0.0.0.0") instead to accomplish the
    //same thing. If you want only to watch for a connection from a
    //specific IP, specify that //instead.

    addr.sin_addr.s_addr = htonl (INADDR_ANY);
int s1 ;
    s1= socket (AF_INET, SOCK_STREAM, IPPROTO_TCP); // Create socket

    if (s1 <0)
    {
        return NULL; //Don't continue if we couldn't create a //socket!!
    }

    if (bind(s1, (sockaddr*)&addr, sizeof(addr)) <0)
    {
       //We couldn't bind (this will happen if you try to bind to the same
       //socket more than once)
        return NULL;
    }

    //Now we can start listening (allowing as many connections as possible to
    //be made at the same time using SOMAXCONN). You could specify any
    //integer value equal to or lesser than SOMAXCONN instead for custom
    //purposes). The function will not //return until a connection request is
    //made
    listen(s1, SOMAXCONN);

    //Don't forget to clean up with CloseConnection()!
   unsigned int size = sizeof(addr);
    int t = accept(s1, (sockaddr*)&addr , &size);

return &t ;

//    WSACleanup();
}

int  receive(int p,char* rec, int rec_len){
	int  iResult = recv(p, rec, rec_len, 0);
	        if ( iResult > 0 ){
	            printf("Bytes received: %d\n", iResult);
	            cout << "Data received " << rec << endl ;
	        }
	        else if ( iResult == 0 )
	            printf("Connection closed\n");
	        else
	            cout << "recv failed " << endl ;

	return 0;
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

Graph* g;
setEnvironment s;

int exit(){
    saveGraph(g);
    closeLog();
    cout << "exiting" << endl;
    return 0;
}



void run(char* c){
    string s = c; 
    size_t case1 = s.find("#") ;
    size_t case2 = s.find("$") ;
    size_t case3= s.find("%") ;
    size_t case4= s.find("&") ;
    if(case1 != string::npos){
        string time = s.substr(0,case1) ;
        long Time =  atol( time.c_str() ) ;
        g->currentTime = Time;
        genStudents(g);
        }
    else if(case2 != string::npos){
        string time = s.substr(0,case2) ;
        long Time =  atol( time.c_str() ) ;
        g->currentTime = Time;
        floatCourses(g);
        setCourses(g);
        }
    else if(case3 != string::npos){
    string time = s.substr(0,case3) ;
    long Time =  atol( time.c_str() ) ;
    g->currentTime = Time;
    setFriends(g);
    }
    else if(case4 != string::npos){
        cout << "exiting" << endl;
        exit();
    }
    return;
}


void recieveLoop(){
	
	    int p =*ListenOnPort(60000) ;	
	    char rec[512] ;
	    while(true){
    		receive(p,rec,sizeof(rec)) ;
    		run(rec);
    		char* sign = "go" ;
    	    send_sign(p,sign,strlen(sign)) ;		
        }
	    
}

void init(){
	g = new Graph();
	g->ifFirstSemester = true;
	s = setEnvironment();
	s.g = g;
	string sample=s.convert_to_string("example");
	s.create_all(sample);
	initLog();
	genFaculty(g);
}



int main(int argc, char *argv[]){

	init();
	recieveLoop();
	exit();
	return 1;
}
