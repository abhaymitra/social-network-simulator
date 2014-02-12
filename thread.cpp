#include <string>
#include <iostream>
#include <thread>
#include <string>
#include <string.h>
#include <unistd.h>

using namespace std;

void task2(string msg)
{

	string s = "./timekeeper " + msg;
    sleep(1);
    system(s.c_str());
}

void task1(string msg)
{
    system("./generator");
    
}


int main(int argc, char** argv)
{
    thread t1(task1,"Hello");
    thread t2(task2, argv[1]);
    t1.join();
    t2.join();
    return 0;
}
