#include "types.h"
#include "user.h"
#include "syscall.h"

int
main(int argc, char *argv[]){
  int pid = fork();
  if(pid>0){
    int i;
    for(i=0;i<200;i++)
      printf(1,"Parent %d, Tickets %d\n",i,1);
    wait();
  }
  else{
    int tickets = 20000;
    settickets(tickets);
    int i;
    for(i=0;i<200;i++)
      printf(1,"Child %d, Tickets %d\n",i,tickets);
  }
  exit();
}
