#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
/*
 * 编译选项 -lpthread
 */

#define MAX_COUNT 9
pthread_mutex_t mutex;     //互斥量
pthread_cond_t cond;       //条件变量
int count = 0;

void * AddCount_Odd_Func(void *);
void * AddCount_Even_Func(void *);

int main(int argc, char const *argv[]) {
  int ret;
  pthread_t odd_pthread, even_pthread;
  pthread_attr_t pthread_attr;

  count = 0;
  pthread_mutex_init(&mutex,NULL);
  pthread_cond_init(&cond,NULL);

  ret = pthread_attr_init(&pthread_attr);
  if(ret != 0){
    perror("Attributed Creation Failed");
    exit(EXIT_FAILURE);
  }
  pthread_attr_setdetachstate(&pthread_attr,PTHREAD_CREATE_DETACHED);

  ret = pthread_create(&odd_pthread,&pthread_attr,AddCount_Odd_Func,NULL);
  if(ret != 0){
    perror("Thread Creation Failed");
    exit(EXIT_FAILURE);
  }
  ret = pthread_create(&even_pthread,&pthread_attr,AddCount_Even_Func,NULL);
  if(ret != 0){
    perror("Thread Creation Failed");
    exit(EXIT_FAILURE);
  }
  while (count < MAX_COUNT) ;
  printf("Finished\n");
  pthread_cond_destroy(&cond);
  pthread_mutex_destroy(&mutex);
  return 0;
}

void * AddCount_Odd_Func(void *p){
  pthread_mutex_lock(&mutex);
  while (count < MAX_COUNT) {
    if(count % 2 == 1){
      count ++;
      printf("Add odd function , count = %d\n", count);
      pthread_cond_signal(&cond);             //释放被阻塞在条件cond上的线程
    }
    else
      pthread_cond_wait(&cond, &mutex);       //使线程阻塞在条件cond上
  }
  pthread_mutex_unlock(&mutex);
}

void * AddCount_Even_Func(void *p){
  pthread_mutex_lock(&mutex);
  while (count < MAX_COUNT) {
    if(count % 2 == 0){
      count ++;
      printf("Add Even function , count = %d\n", count);
      pthread_cond_signal(&cond);
    }
    else
      pthread_cond_wait(&cond, &mutex);
  }
  pthread_mutex_unlock(&mutex);
}
