#include<stdio.h> 
 #include<stdlib.h> 
 #include <sys/types.h> 
 #include <dirent.h> 
#include <string.h>  
 int main(void) 
 { 
    int i=0; 
    DIR *p = NULL;
char fileName[255]; 
    struct dirent *dptr = NULL;     
    p = opendir((const char*)"./");  
    for(i = 0;(dptr = readdir(p)) != NULL; i++) 
    {
strncpy(fileName, dptr->d_name, 254);
if(strncmp(fileName,".",sizeof(fileName))!= 0 && strncmp(fileName,"..",sizeof(fileName)!=0))
        printf("%s\n  ",dptr->d_name); 
    } 
    return 0; 
 }