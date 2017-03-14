#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>

using namespace std;

int execute(char **argv);
void lsh_loop();
char **split(char *line);
char *readline();
int i=0;


//Maintaining history of commands
char *history(char c)
{
	int k,l,fd,temp=0,size=1024;
	char buf2[100];
	char *buffer;

		buffer =(char*) malloc(sizeof(char) * size);


		if((fd=open("history",O_RDWR|O_APPEND))==-1)
			{cout<<"opening error\n";}

	switch(c){

				case 'A':
					
					do{
          				
          				if((k=read(fd,buf2,1))==-1)
          					perror("read error:");


          				if((l=write(1,buf2,1))==-1)
          					perror("write standard error:");

          			buffer[temp++]=buf2[0];

      				}while(buf2[0]!='\n' || buf2[0]!=' ');
      		
      				//lsh_loop();
      				return buffer;
      				break;

    		}
}





//Function for basic shell functionality


int execute(char **argv)
{
	pid_t pid,wpid;
	int status;
char *arg[10];
	
	 if(strcmp(argv[0],"exit")==0)
     {
     	cout<<" Exiting... Bye\n";
     	return 0;
     }


    //creating a new child process
    pid = fork();


    

// Child process executing
	if(pid==0)
	{
		cout<<"Child process runningg...\n";
		int l=0;
		

     for(int k=0;k<i;k++)
     	arg[l++]=argv[k];


     argv[i] = NULL;

     cout<<"Executing : "<<argv[0]<<endl;


		if(execv(argv[0],argv) == -1)
		{
			// cout<<argv[0];
			perror("shell command execution error");

		}

		cout<<"\n Done"<<endl;

		//exit(1);
	}

	else if(pid<0)
	{
		perror("Error forking\n");
	}	

	else
	{
		cout<<"Parent process waiting...\n";
		
          do {
       wpid = waitpid(pid, &status, WUNTRACED);
     } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  
	}

return 1;
} 


//function to run the shell continuously
void lsh_loop()
{
	char *line;
	char buf[100],buf1[100],buf2[100],c;
	char *argv;
	char *list[10];
	int status;
	int fd,n,m,k,l,temp=0;
	char in;

	do{

		cout<<"Myshell$ ";
		line=readline();

		for(m=0;m<strlen(line);m++)
        buf[m]=line[m]; 

		buf[m]=NULL;

		if((fd=open("history",O_RDWR|O_APPEND))==-1)
			{cout<<"opening error\n";}



        if(strcmp(buf1,buf)!=0)
        { 

			if((n=write(fd,buf,strlen(buf)))==-1)
				{
					perror("error writing:");
				}

			write(fd,"\n",1);
		}



		for(m=0;m<strlen(buf);m++)
        buf1[m]=buf[m]; 

        buf1[m]=NULL;

          

        //Tokenizing the command and arguments
		while((argv=strtok(line," \n")) != NULL)
			{	
			 	list[i++] = argv;
			 	line = NULL;
			}

				
		status=execute(list);

		int j;

		close(fd);
		
		
		
		free(line);
		free(argv);
		i=0;
	}while(status);
}


//to read the input
char *readline()
{
	int n,pos=0,size=1024;
	char *buf;
	char c,nav;

	buf =(char*) malloc(sizeof(char) * size);

	if(!buf)
		{
			perror("Allocation error\n");
			exit(1);
		}

	while(1)
		{
			c=getchar();

			if(c=='\n' || c==EOF)
				{
					buf[pos]='\0';
					return buf;
				}

			else if(c=='\033')
				{
					getchar();
					nav=getchar();

					buf=history(nav);
					n=strlen(buf);
					buf[n]='\0';

					cout<<"buffer"<<buf<<endl;
					return buf;
				}

			else
				buf[pos++]=c;
	


 			if(strlen(buf)>=size)
 				{
 					size+=1024;
 					buf=(char *)realloc(buf,size);

 					if(!buf)
 						{
 								perror("Reallocation error\n");
 						}
 				}
 		}
 

 //return buf;

}




int main(int argc,char **argv )
{
 lsh_loop();
}

	








