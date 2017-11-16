#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(){
  srand(time(NULL));
  int t1 = rand() % 16 + 5;
  int t2 = rand() % 16 + 5;
  int f1, f2;
  int stat;

  printf("Initial Message\n");
  printf("\n1st Fork\n");
  f1 = fork();
  
  wait(&stat);
  if (f1 ==0){
    printf("Child PID: %d\n", getpid());
    sleep(t1);
    printf("Child with PID of %d is finished. \n", getpid());
    //printf("Child with PID of %d ran for %d seconds. \n", getpid(), y1);
  }
  else{
    printf("\nParent PID: %d \n", getppid());
    printf("Child with PID of %d ran for %d seconds. \n", getpid(), t1);

    printf("Parent with PID of %d finished\n", getppid());
  }

 printf("\n2nd Fork\n");
  f2 = fork();
  
  wait(&stat);
  if (f2 == 0){
    printf("Child PID: %d\n", getpid());
    //t2 = ran;
    sleep(t2);
    printf("Child with PID of %d is finished. \n", getpid());
    //printf("Child with PID of %d ran for %d seconds. \n", getpid(), t2);
  }
  else{
    printf("\nParent PID:%d\n",getppid());
    printf("Child with PID of %d ran for %d seconds. \n", getpid(), t2);
    printf("Parent with PID of %d finished\n", getppid());
  }
  
}
