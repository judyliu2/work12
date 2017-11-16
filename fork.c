#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
int main(){
  srand(time(NULL));
  int ran = rand() % 25 + 5;
  int f1, f2;
  int stat;

  printf("initial message\n");

  f1 = fork();
  wait(&stat);
  if (f1 ==0){
    printf("Child 1: %d\n", getpid());
    sleep(ran);
    printf("Child 1 finished. \n");
  }
  printf("complete child 1 pid : %d \n" , getpid());
  printf("parent 1 finished\n");

  f2 = fork();
  wait(&stat);
  if (f2 == 0){
    printf("Child 2: %d\n", getpid());
    sleep(ran);
    printf("Child 2 finished. \n");
  }

  printf("Parent PID:%d\n",getppid());
 
  
}
