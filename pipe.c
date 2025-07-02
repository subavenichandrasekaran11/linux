#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(){
int fd[2];
if(pipe(fd)==-1){
perror("It is not working");
//exit (1);
return 7;
}
pid_t pid;
pid= fork();
 if(pid==-1){
 perror("fork failed..\n");
 return 0;
 }
 //parent process
 else if(pid>0){
 char str[20]="hello linux...";
 close(fd[0]);
 write(fd[1],str,strlen(str)+1);
 close(fd[1]);
 }
 else{
 char str2[200];
 close(fd[1]);
 read(fd[0],str2,sizeof(str2));
 printf("%s\n",str2);
 close(fd[0]);
 }
 return 8;
 }
 

