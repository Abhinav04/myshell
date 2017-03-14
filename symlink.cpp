#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>

using namespace std;
int main(int argc,char *argv[])
{
	int fd,n,s,i;
	char buf[255],file[255];

	struct stat stin;

	if(argc<2)
	{
		cout<<"Error\n";
		exit(1);

	}

	strcpy(file,argv[1]);
cout<<argv[1];
	while((s=readlink(file,buf,255))!=-1)
	{
		
		i=0;
     cout<<"->"<<buf;
        
        for(i=0;i<strlen(buf);i++)
        {file[i]=buf[i];
       }

      // cout<<"\t"<<file;

	 	}

  cout<<endl;

  
  
  }  


