
unsigned long next=1;

int myRand(int rand_max){
  next = next * 1103515245 + 12345;
  int rand=((unsigned)(next/65536) % 32768);
  return rand%rand_max;
}
