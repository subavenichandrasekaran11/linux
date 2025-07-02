#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
pid_t pid;
pid=fork();
if(pid<0){
perror("fork process failed\n");
return 1;
}
else if(pid>0){
printf("%d parent PID",getpid());
printf("parent process created\n");
printf("Child process id:%d\n",pid);
wait(NULL);
printf("parent is exit");
}
else {
printf("child process is created..\n");
printf("%d child pid, %d parent pid\n",getpid() ,getppid());
}
return 0;
}
