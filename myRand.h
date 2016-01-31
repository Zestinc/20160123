
unsigned long next=1;

int myRand(int rand_max){
  next = next * 1103515245 + 12345;
  int rand=((unsigned)(next/65536) % 32768);
  if(rand_max==0){
    return 0;
  }
  return rand%rand_max;
}
