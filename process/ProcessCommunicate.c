#include "signal.h"
#include "unistd.h"
#include <stdio.h>
#include "time.h"

// 信号处理
void signalHandle(int signal){
  switch (signal) {
    case SIGHUP:
    printf("SIGHUP %d\n", signal);break;
    case SIGINT:
    printf("SIGINT %d\n", signal);break;
    case SIGQUIT:
    printf("SIGQUIT %d\n", signal);break;
    case SIGALRM:
    printf("SIGALRM %d\n", signal);break;
    default:
    printf("Unknown signal %d\n", signal);
  }
}

int main(int argc, char const *argv[]) {
  int sec_delay = 5;
  printf("Current Process Id %d\n", (int)getpid());
  // 安装信号
  signal(SIGINT,signalHandle);
  signal(SIGQUIT,signalHandle);
  signal(SIGALRM,signalHandle);

  // 发送信号
  alarm(sec_delay);
  while (1) {
    pause();
  }
  return 0;
}
