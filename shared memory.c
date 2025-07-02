#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
int main()
{
//Generate unique key
key_t key = ftok("shmfile",65);

//create access using the shared memory id
int shmid=shmget(key,1024,0666|IPC_CREAT);

//get data and attach to the process address
char *shared_data=(char*)shmat(shmid,NULL,0);
  
printf("Enter the data write into the shared memory\n");  
fgets(shared_data,1024,stdin);

printf("getting from shared memory\n");
printf("shared memory contain :%s\n",shared_data);

//detach from the shared memory
shmdt(shared_data);
shmctl(shmid,IPC_RMID,NULL);
return 0;
}



/*output
nter the data write into the shared memory
Hi.I am subaveni...
getting from shared memory
shared memory contain :Hi.I am subaveni...*/


