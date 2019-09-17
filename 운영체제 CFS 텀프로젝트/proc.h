#ifndef _PROC_H_
#define _PROC_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <dirent.h>
#include <string>

using namespace std;

typedef struct _process_info {
	vector<string> process; //stat information
} processInfo; //store process information

typedef vector<processInfo> Plist; //define type to store process 

class Proc {
	private :
		int processNum; //number of process
		Plist ProcList; //entire process list
	public :
		Proc();
		~Proc();
		void readProcInfo();//read process info from stat file
		vector<string> procParser(char*);//parsing process infomation in stat file
		int procNum();//return total process number
		bool isDigit(char*);//check if string is digit
		Plist getProcList();//return process list		
};

#endif


