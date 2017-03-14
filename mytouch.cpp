#include<stdio.h>
#include <ctime>
#include<iostream>
#include<utime.h>
#include<sys/time.h>
//#include<fstream.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
int main(int argc,char**argv)
{
char buf[1];
if(argc>1){
for(int i=1;i<argc;i++){
  struct utimbuf *times = NULL;
  struct stat statbuf;
  stat(argv[i], &statbuf);
int fd1=open(argv[i],O_RDWR|O_CREAT,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
utime(argv[i],times);
close(fd1);

cout<<"Done\n";
}
}
else{
printf("Touch expects atleast one arg\n");
}
}

