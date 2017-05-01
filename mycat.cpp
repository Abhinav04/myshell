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
	int fd,n=1,i=1;
	char buf[1];

	struct stat stin;

	cout<<"\n hel";

	if(argc<2)
	{
		cout<<"error\n";
		exit(1);

	}

cout<<"Not reach";


if(strcmp(argv[1],"-n")==0)
{
	cout<<"Reach";
	i=2;

	
		if((fd=open(argv[i],O_RDWR|O_CREAT,S_IRWXU ))==-1)
		{
			cout<<"Error\n";
			exit(1);
		}

cout<<"\n";
			while(buf[0]!=27)
			{
				n=read(0,buf,1);
				
				if(buf[0]==27)
				exit(0);
				
				write(fd,buf,n);	
	
		}

close(fd);
return 0;

}
	

 else{

 	while(i<=argc)
 	{

        if((fd=open(argv[i],O_RDONLY))==-1)
	{
		cout<<"Error opening the file\n";
		exit(1);

	}

 		stat(argv[i],&stin);

	if(S_ISREG(stin.st_mode))
	{

	  n=1;
      //buf=(char*) malloc(1*sizeof(argv[1]));

      while(n!=0)
      {
      n=read(fd,buf,300);
      //cout<<"\nread bytes"<<n<<endl;  
      write(1,buf,n);
  }

   }

   i++;
}
}

   return 0;
}
