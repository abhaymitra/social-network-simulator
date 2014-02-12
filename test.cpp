#include <omp.h>
#include <string>
#include <iostream>

using namespace std;

void printthread(){
	#pragma omp parallel for
	for (int i = 0; i<10;i++){
		cout << "Hello World !" << endl;
	}
}

int main(){
	printthread();
	return 0;
}