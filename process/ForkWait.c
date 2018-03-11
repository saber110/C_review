#include <stdio.h>
#include <unistd.h>
#include <wait.h>
/**
 * fork 失败返回-1
 *      成功返回两次数据，父进程返回子进程标记，子进程返回0
 */
int main(int argc, char const *argv[]) {
  pid_t child_pid, pid;
  int status;
  child_pid = fork();
  switch (child_pid) {
    case -1: printf("Create Process Failed\n");break;
    case 0:  printf("Child Process With ID %d\n", (int)getpid());break;
    default: printf("Parent Process With ID %d,Child Process With ID %d\n", (int)getppid(),(int)child_pid);
    pid = wait(&status);
    // 调用wait父进程马上阻塞自己，直到找到一个僵死进程。并会自动收集这个进程的信息
    printf("Child Process is Finished %d\n", child_pid);

    if(WIFEXITED(status)){
      printf("Child Processed exited with code %d\n", WEXITSTATUS(status));
    }
    else{
      printf("Child Process Terminated \n");
    }
  }
  return 0;
}
