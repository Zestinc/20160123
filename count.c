#include "types.h"
#include "user.h"
#include "syscall.h"

int
main(int argc, char *argv[])
{
  int cpid = getpid();
  int arg = atoi(argv[1]);
  printf(1, "arg = %d\n", arg);
  count(arg);
  // printf(1, "ID of current process %d\nAnd it's count:%d\n\n", arg, count(arg));
  // printf(1, "ID of current process %d\nAnd it's count:%d\n\n", cpid, count(arg));
  sleep(1);
  if(fork() == 0){
    cpid = getpid();
    count(cpid);
    // sleep(1);
    // printf(1, "ID of current process %d\nAnd it's count:%d\n\n", cpid, count(arg));
  }
  else{
    sleep(2);
    count(cpid);
    // printf(1, "ID of current process %d\nAnd it's count:%d\n\n", cpid, count(arg));
  }
  wait();
  exit();
}