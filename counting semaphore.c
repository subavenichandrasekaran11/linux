#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>
sem_t countsem;
int count=0;
void* my_function(void* arg){
    int threadids=*(int*)arg;
     sem_wait(&countsem);
    printf("count:%d thread_id:%d\n",++count,threadids);
    sleep(2);
    sem_post(&countsem);
    printf("thread id:%d leaving..\n",threadids);
    return NULL;
}

int main()
{
    pthread_t person[100];
    int person_ids[]={1,2,3,4,5,6,7,8,9,10};
    sem_init(&countsem, 0,5);
    for(int i=0;i<10;i++){
        pthread_create(&person[i],NULL,my_function,(void*)&person_ids[i]);
   }
   for(int i=0;i<10;i++){
        pthread_join(person[i],NULL);
    }
    sem_destroy(&countsem);
    return 0;
}



/*output
count:1 thread_id:1
count:2 thread_id:2
count:5 thread_id:5
count:3 thread_id:3
count:4 thread_id:4
thread id:1 leaving..
thread id:3 leaving..
thread id:5 leaving..
thread id:2 leaving..
thread id:4 leaving..
count:6 thread_id:10
count:7 thread_id:7
count:8 thread_id:8
count:8 thread_id:6
count:9 thread_id:9
thread id:9 leaving..
thread id:10 leaving..
thread id:6 leaving..
thread id:8 leaving..
thread id:7 leaving..
  */
