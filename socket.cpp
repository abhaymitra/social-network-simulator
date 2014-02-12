//============================================================================
// Name        : socket.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

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

using namespace std;

//This typedef will be filled out when the function returns

int s; //Socket handle
int n; //Socket handle


//CONNECTTOHOST  Connects to a remote host
bool ConnectToHost(int PortNo, char* IPAddress)
{


    //Fill out the information needed to initialize a socket

sockaddr_in target ;
    target.sin_family = AF_INET; // address family Internet
    target.sin_port = htons (PortNo); //Port to connect on
    target.sin_addr.s_addr =inet_addr("127.0.0.1") ; //Target IP

    s = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP); //Create socket
    if (s <0)
    {
        return false; //Couldn't create the socket
    }

    //Try connecting...

    if (connect(s, (sockaddr *)&target, sizeof(target)) <0)
    {
        return false; //Couldn't connect
    }
    else{

        return true; //Success
    }
}

//CLOSECONNECTION  shuts down the socket and closes any connection on it
void CloseConnection ()
{
    //Close the socket if it exists
    if (s)

    close(s) ;


}



//LISTENONPORT  Listens on a specified port for incoming connections
//or data
int ListenOnPort(int portno ,char* IPaddress)
{


    sockaddr_in addr; // The address structure for a TCP socket

    addr.sin_family = AF_INET;      // Address family
    addr.sin_port = htons (portno);   // Assign port to this socket

    //Accept a connection from any IP using INADDR_ANY
    //You could pass inet_addr("0.0.0.0") instead to accomplish the
    //same thing. If you want only to watch for a connection from a
    //specific IP, specify that //instead.

    addr.sin_addr.s_addr = htonl (INADDR_ANY);

    s = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP); // Create socket

    if (s<0)
    {
        return false; //Don't continue if we couldn't create a //socket!!
    }
    if (bind(s, (sockaddr*)&addr, sizeof(addr)) <0)
    {
       //We couldn't bind (this will happen if you try to bind to the same
       //socket more than once)
        return false;
    }

    //Now we can start listening (allowing as many connections as possible to
    //be made at the same time using SOMAXCONN). You could specify any
    //integer value equal to or lesser than SOMAXCONN instead for custom
    //purposes). The function will not //return until a connection request is
    //made
    listen(s, SOMAXCONN);

    //Don't forget to clean up with CloseConnection()!
//    int size = sizeof(addr);
//    s = accept(s, (SOCKADDR*)&addr , &size);


//    WSACleanup();
}

int send_sign(int p , char* mystring , int length){
cout << "l" << endl ;
	int iResult = send( p, mystring, length, 0 );
		    if (iResult <0) {
		       cout <<"error" << endl ;
		     close(p) ;
		        return 1;
		    }

		    printf("Bytes Sent: %d\n", iResult);

		       if (iResult<0) {
		    	   cout <<"shutdown error" << endl ;
		           close(p);

		           return 1;
		       }
		       cout << "shutdown" << endl ;

		    return 0 ;
}

int  receive(int p,char* rec, int rec_len){

cout << "receive" << endl ;
	int  iResult = recv(p, rec, rec_len, 0);
	cout << "receive" << endl ;
	        if ( iResult > 0 )
	            printf("Bytes received: %d\n", iResult);
	        else if ( iResult == 0 )
	            printf("Connection closed\n");
	        else


	return 0;
}





int main(){
	char * l  = "127.0.0.1" ;
	cout << "me" <<endl ;
	ListenOnPort(2345,l) ;


	bool p =ConnectToHost(2345,l) ;
	//wmain(n) ;
	cout << p <<endl ;
	//cout << ConnectToHost(5654,l)  <<endl ;
	    char* sign = "signal" ;
	    char rec[6] ;
	    int rec_len = 6 ;


	    send_sign(s,sign,6);
	    	receive(s,rec,rec_len) ;



	return 0 ;

}




