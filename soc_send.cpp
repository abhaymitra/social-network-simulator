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
#include <string.h>


using namespace std;
#define SCK_VERSION1            0x0101
#define SCK_VERSION2            0x0202



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



int main(){
	char * l  = "127.0.0.1" ;
	int p =*ConnectToHost(60000,l) ;
	char* sign = "Divyansh" ;
	    send_sign(p,sign,strlen(sign)) ;
	    cout <<"ok" << endl;

	return 0 ;

}



