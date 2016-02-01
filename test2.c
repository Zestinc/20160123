#include "types.h"
#include "user.h"
#include "syscall.h"

int
main(int argc, char *argv[]){
  int pid = fork();
  if(pid>0){
    int pid2 = fork();
    if(pid2>0){
      status(pid);
      status(pid2);
      sleep(500);
      kill(pid);
      kill(pid2);
      status(pid);
      status(pid2);
      printf(1,"%d %d\n",pid ,pid2);
      wait();
    }
    else{
      int tickets = 1;
      settickets(tickets);
      while(1){
      }
    }
    wait();
  }
  else{
    int tickets = 20;
    settickets(tickets);
    while(1){
    }
  }
  exit();
}
