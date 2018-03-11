#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
/*
 * 编译选项 -lpthread
 * 两个线程倒计数
 */
pthread_mutex_t mutex;  //互斥量
int count = 0;
char msg_buff[64];
void *SetMsg_Func(void *);
void PrintMsg_Func(void);
int main(int argc, char const *argv[]) {
  int ret;
  pthread_t set_pthread;
  count = 4;
  pthread_mutex_init(&mutex,NULL);      //互斥量初始化

  ret = pthread_create(&set_pthread,NULL,SetMsg_Func,NULL);   //创建成功返回0
  if(ret != 0){
    perror("Thread Create Failed");
    exit(EXIT_FAILURE);
  }
  PrintMsg_Func();

  ret = pthread_join(set_pthread, NULL);
  if(ret != 0){
    perror("Thread Join Failed");
    exit(EXIT_FAILURE);
  }
  pthread_mutex_destroy(&mutex);
  printf("Finished\n");
  return 0;
}

void * SetMsg_Func(void * p){
  while (count > 0 ) {
    pthread_mutex_lock(&mutex);
    memset(msg_buff,0,64);
    sprintf(msg_buff,"count=%d.\n",count--);
    pthread_mutex_unlock(&mutex);
    srand((int)time(0));
    sleep(rand()%3);  //转交控制权
  }
  pthread_exit(0);
}

void PrintMsg_Func(void){
  while (count >= 0 ) {
    pthread_mutex_lock(&mutex);
    printf("%s\n", msg_buff);
    pthread_mutex_unlock(&mutex);
    if(0 == count)
      break;
    srand((int)time(0));
    sleep(rand()%3);  //转交控制权
  }
}
