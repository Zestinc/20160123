#include "types.h"
#include "user.h"
#include "syscall.h"
#include "fcntl.h"

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
      wait();
    }
    else{
      int tickets = 1;
      settickets(tickets);
      int fd = open("testa",O_CREATE|O_RDWR);
      write(fd,"hello\n",6);
      close (fd);
      while(1){
        int fd2 = open("testa",O_RDWR);
        char str[6];
        read(fd2,str,6);
        write(fd2,str,6);
        close(fd2);
      }
    }
    wait();
  }
  else{
    int tickets = 1;
    settickets(tickets);
    int i=1;
    int j= 1;
    while(1){
      i=i+j;
      j=i+j;
    }
  }
  exit();
}
