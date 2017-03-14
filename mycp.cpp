#include<stdlib.h>
#include<iostream>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<unistd.h>
using namespace std;

struct stat stin,stout;

int dir(char *s,char *d);
int file(char *s,char *d);


int main(int argc,char **argv)
{

	char *s,*d;

	if(argc!=3)
	{
		cout<<"Source and destination files are not mentioned";

	}

	s=argv[1];
	d=argv[2];

	stat(s,&stin);
	stat(d,&stout);

	if(s[0]=='/' && d[0]=='/')
	{
       exit(1);
	}



	else if(s[0]=='/' || d[0]=='/')
	{
		
		file(s,d);
	}
 
	else
	{
		file(s,d);
	}


}

int file(char *s,char *d)
{
	int fdin,fdout,count;
	char buf[2048];

	if((fdin=open(s,O_RDONLY))==-1)
	{
		cout<<"Error opening the source file\n";
		exit(1);
	}

	else if((fdout=open(d,O_RDWR|O_CREAT))==-1)
	{
		cout<<"Error opening the destination file\n";
		exit(1);
	}


	count=read(fdin,buf,stin.st_size);

	if(count==-1)
	{
		cout<<"Error in reading file";
		exit(1);
	}

	write(fdout,buf,count);

	cout<<"\n Done\n";

	close(fdin);
	close(fdout);

}
 