#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include<sys/stat.h>

using namespace std;

int front=0,rear=0;


int main()
{
struct stat st;
int fd,k=0,i=0;
char tempread[500];
char *arg;
char *line;
char *buffer[100];


if((fd=open("history",O_RDWR|O_APPEND))==-1)
	{cout<<"opening error\n";}

stat("history",&st);

	
		//cout<<k;
		if((k=read(fd,tempread,st.st_size))==-1)
          	{
			perror("read error:");	
			}

		line=tempread;

		
		cout<<line<<endl;
	
	

	while((arg=strtok(line,"\n")) != NULL)
	{	
		buffer[rear++] =arg;
		line = NULL;
	}

rear--;

//cout<<buffer[0];

while(front<=rear)
cout<<buffer[front++]<<"\n";
close(fd);
return 0;
}
