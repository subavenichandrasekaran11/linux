#include<stdio.h>
#include<pthread.h>
int counter=0;
pthread_mutex_t lock;
void* my_func(void* arg)
{
int thread_id = *(int*)arg;
for(int i=0;i<5;i++){
pthread_mutex_lock(&lock);
printf("thread %d achuired lock\n",thread_id);
counter++;
printf("threads:%d counter:%d\n",thread_id,counter);
pthread_mutex_unlock(&lock);
printf("thread %d released lock\n",thread_id);
}
return NULL;
}

int main()
{
pthread_mutex_init(&lock,NULL);
pthread_t t1,t2;
int id1=1,id2=2;
pthread_create(&t1,NULL,my_func,(void*)&id1);
pthread_create(&t2,NULL,my_func,(void*)&id2);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
pthread_mutex_destroy(&lock);
return 0;
}

