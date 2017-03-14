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

struct stat stin,stout;

int directory(char *source,char *destination);
int regfile(char *s,char *d);
int filedir(char *s,char *d);


int regfile(char *s,char *d)
{
	cout<<"Hrllofile\n";
	int fdin,fdout,count;
	char buf[2048];

	//buf = (char*) malloc(1*sizeof(s));

	if((fdin=open(s,O_RDONLY))==-1)
	{
		cout<<"Error opening the source file\n";
		exit(1);
	}

	else if((fdout=open(d,O_RDWR|O_CREAT))==-1)
	{
		cout<<"Error opening the destination regular file\n";
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

    unlink(s);
    return 0;
}

int filedir(char *s,char *d)
{
	cout<<"Hellofiledir\n";
	int fdin,fdout,count;
	char buf[2048];

	if((fdin=open(s,O_RDONLY))==-1)
	{
		cout<<"Error opening the source file\n";
		exit(1);
	}

strcat(d,"/");
strcat(d,s);

	 if((fdout=open(d,O_RDWR|O_CREAT))==-1)
	{
		cout<<"Error opening the destination dir\n";
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

    unlink(s);

    return 0;
}


int directory(char *source, char *destination)
{
    DIR *dir_ptr = NULL;
    char fileName[255]; 

    struct dirent *direntp;
    char tempDest[strlen(destination)+1];
    char tempSrc[strlen(source)+1];

    strcpy(tempDest, destination);
    strcpy(tempSrc, source);
     

    struct stat fileinfo;

    cout<<"HelloDir\n";

    cout<<source<<"\n";
     
 
 
   if( (dir_ptr = opendir(source)) == NULL )
   {
     cout<<"\n Error in reading source";
      return 0;
   }

 

      for(int i=0; direntp->d_name!=NULL;i++)
      {      
    {
strncpy(fileName, direntp->d_name, 254);
if(strncmp(fileName,".",sizeof(fileName))!= 0 && strncmp(fileName,"..",sizeof(fileName)!=0))
        printf("%s  ",direntp->d_name); 
  


            stat(direntp->d_name,&fileinfo);

   /*   	if(S_ISDIR(fileinfo.st_mode))
          {
          	directory(direntp->d_name,destination);
          }*/

      if(S_ISREG(fileinfo.st_mode))  
      {   	
             
        strcat(tempDest, direntp->d_name);
      	
          cout<<"Hie\n";          
          strcat(tempDest, direntp->d_name);
          regfile(tempSrc, tempDest);
              strcpy(tempDest, destination);
          strcpy(tempSrc, source);            
      }
      }
      closedir(dir_ptr);
      rmdir(source);
      return 1;
   
 
 }
}



int main(int argc,char **argv)
{

	char *s,*d;

	if(argc!=3)
	{
		cout<<"Source and destination files are not mentioned";

	}

cout<<"HIe\n";

	s=argv[1];
	d=argv[2];

	
	stat(s,&stin);
	stat(d,&stout);

	 if (S_ISDIR(stin.st_mode) && S_ISDIR(stout.st_mode))
		{
			directory(s,d);
		}	

	if(S_ISREG(stin.st_mode) && S_ISREG(stout.st_mode))
		{
			regfile(s,d);
			link(s,d);
			unlink(s);
		}

	 if(S_ISREG(stin.st_mode) && S_ISDIR(stout.st_mode))
		{
			filedir(s,d);

		}	



		return 0;
}