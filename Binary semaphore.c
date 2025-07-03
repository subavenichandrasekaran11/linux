#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
sem_t binarysem;
void* my_function(void* arg){
    int id=(int)arg;
    sem_wait(&binarysem);
    printf(" entering...thread id:%d\n",id);
    fflush(stdout); 
    sleep(5);
    printf("leaving...thread id:%d\n",id);
    fflush(stdout); 
    sem_post(&binarysem);
    return 0;
}

int main(){
    pthread_t t1,t2;
    int id1=1,id2=2;
    sem_init(&binarysem,0,1);
    pthread_create(&t1,NULL,my_function,(void*)&id1);
    pthread_create(&t2,NULL,my_function,(void*)&id2);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&binarysem);
    return 0;
    
}



/*output
entering...thread id:1
leaving...thread id:1
entering...thread id:2
leaving...thread id:2
*/
