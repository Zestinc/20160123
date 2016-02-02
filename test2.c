#include "types.h"
#include "user.h"
#include "syscall.h"


int
main(int argc, char *argv[]){
  int pid = fork();
  if(pid>0){
    int pid2 = fork();
    if(pid2>0){
      sleep(50);
      status(pid);
      status(pid2);
      sleep(500);
      kill(pid);
      kill(pid2);
      status(pid);
      status(pid2);
      wait();
    }
    else{
      int tickets = 10;
      settickets(tickets);
      while(1){
      }
    }
    wait();
  }
  else{
    int tickets =50;
    settickets(tickets);
    while(1){
    }
  }
  exit();
}

