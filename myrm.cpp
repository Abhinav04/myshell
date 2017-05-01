#include<stdlib.h>
#include<iostream>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<unistd.h>
#include<stdio.h>
using namespace std;

struct stat stin;

int main(int argc,char **argv)
{
int i=0;
DIR *p=NULL;

struct dirent *dptr=NULL;

if(strcmp(argv[1],"-s")==0)
	{
		cout<<"hrllo";
  		stat(argv[2],&stin);
		
		p=opendir(argv[2]);
		
		for(i = 0;(dptr = readdir(p)) != NULL; i++) 
    		{       cout<<"Hie\n";
			remove(dptr->d_name);
		}
		
		exit(1);						
					
	}	

else
	{
	for(i=0;i<argc;i++)
  		remove(argv[i]);
	}

return 0;

}
