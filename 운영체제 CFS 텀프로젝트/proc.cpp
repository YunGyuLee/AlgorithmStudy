
#include "proc.h"
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <stdlib.h>

using namespace std;

Proc::Proc() {
	
}

Proc::~Proc() {

}

void Proc::readProcInfo() {
	DIR * directory; 
	struct dirent *entry = NULL;
	char procFile[40];
	vector<string> procInfo; //to store process's stat information
	processInfo lprocess;
	struct stat lstat;
	
	ProcList.clear();
	//get list of files under /proc
	if ((directory = opendir("/proc")) == NULL) {
           perror("opendir error :");
           exit(0);
        } 
   //read each directory
    while((entry = readdir(directory)) != NULL) {
        if (strcmp(entry->d_name, ".") !=0 &&
            strcmp(entry->d_name, "..") != 0) 
	   {
            sprintf(procFile,"/proc/%s/stat", entry->d_name);
	   //check if stat file exist
           if (access(procFile, F_OK) != 0) {
                continue;
            }
	  //check if directory name is digit
           if (isDigit(entry->d_name)) {
                lprocess.process  = procParser(procFile);

                if(atoi(lprocess.process[0].c_str()) == atoi(entry->d_name))
                {
                    ProcList.push_back(lprocess);
                }
            }
            
        }
 }
}

Plist Proc::getProcList()
{
    return ProcList;
}

int Proc::procNum()
{
    return ProcList.size();
}

vector<string> Proc::procParser(char *procFile)
{
    FILE *fp;
    char buf[512] = {0x00,};
    char field[80];
    int index = 0;
    unsigned int i, j = 0;
    vector<string> vproc;

    fp = fopen(procFile, "r");
    if (fp == NULL)
    {
        perror("error : ");
        exit(0);
    }

    memset(field, 0x00, 80);
    fgets(buf, 511, fp);
    for(i = 0; i < strlen(buf); i++)
    {
        if (buf[i] != ' ' && i != (strlen(buf) -1))
        {
            field[j++] = buf[i];
        }
        else
        {  
            if (index == 1)
            {
                field[strlen(field)-1] = 0x00;
                vproc.push_back(field+1);
            }
            else
                vproc.push_back(field);
            memset(field, 0x00, 80);
            j = 0;
            index++;
        }
    }
    fclose(fp);
    return vproc;
}   
 
bool Proc::isDigit(char *str)
{
    int i;
    for (i = 0; i < strlen(str); i++)
    {
        if (isdigit(str[i])==0)
            return false;
    }
    return true;
}
