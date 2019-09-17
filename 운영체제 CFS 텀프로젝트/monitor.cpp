#include <unistd.h>
#include <stdio.h>
#include "proc.h"
#include <iostream>
#include <set>
#include <string>
#include <string.h>
using namespace std;
set<string> db;  	/*Database to store benchmark1,2*/

#define SCHED_FAST 328
#define SCHED_SLOW 329

void printDB() {
	set<string>::iterator it;
	for(it = db.begin() ; it !=db.end();it++) {
		cout<<*it<<" ";
	}
	cout<<endl;
}

void firstCheckProc() { //funtion to check if it is the first implement of benchmark1,2. And store them to DB

	Proc mproc; //define a object to use procfs
	mproc = Proc();

	bool checkEnd = false; //variable to check the end of while loop

	cout<<"First Check begin"<<endl;

	while(1) {

		mproc.readProcInfo();
		Plist ProcList;
		ProcList = mproc.getProcList();

		for(int i=0;i<ProcList.size();i++) {//check all process if there is process named benchmark1 and 2
			if(strcmp(ProcList[i].process[1].c_str(),"benchmark1")==0 
			|| strcmp(ProcList[i].process[1].c_str(),"benchmark2")==0)
			{ 
				checkEnd = false;
				if(db.find(ProcList[i].process[1]) != db.end()) //if benchmark1,2 is already in the DB DO NOT ADD
					continue; 
				
				db.insert(ProcList[i].process[1]);//add benchmark1 or 2 to DB
			}
		}

		if (db.size()!=0 && checkEnd) //loop exit conidition
			break;
		checkEnd = true;
		usleep(500000); //check all process every 0.5 sec
	
	}
	cout<<"First Check is done"<<endl;
	return;
}

void secondCheckProc() {
	Proc mproc;
	mproc = Proc();

	bool checkEnd = false; //variable for check End of while loop

	cout<<"Second Check begin"<<endl;

	while(1) {
		//read Process info from procfs
		mproc.readProcInfo();
		Plist ProcList;
		ProcList = mproc.getProcList();

		for(int i=0;i<ProcList.size();i++) {
			//benchmark1 is I/O bound. so call sched_slower
			if(strcmp(ProcList[i].process[1].c_str(),"benchmark1")==0)
			{ 
				if(db.find("benchmark1") != db.end()) {
					db.erase("benchmark1");
					printf("Call sched_slower\n");
					syscall(SCHED_SLOW,std::stoi(ProcList[i].process[0]));
					//call sched_slower here!
				} 
				checkEnd = false;	  
			}
			//benchmark2 is CPU bound. so call sched_faster
			else if(strcmp(ProcList[i].process[1].c_str(),"benchmark2")==0)
			{
				if(db.find("benchmark2") != db.end()) {
					db.erase("benchmark2");
					printf("Call sched_faster\n");
					syscall(SCHED_FAST,std::stoi(ProcList[i].process[0]));
				}
				checkEnd = false;
			}	
		}

		if (db.empty() && checkEnd)
			break;
		
		checkEnd = true;


		usleep(500000); //check all process every 0.5 sec
	}
	cout<<"Second check is done"<<endl;
	return;
}

int main() {
	firstCheckProc();
	cout<<"In the Database : ";
	printDB();
	secondCheckProc();
	cout<<"monitoring is over"<<endl;
	return 0;
}
