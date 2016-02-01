#include "hash.h"


int
get_processor_hash(int pid)
{
  int hash_id = pid % NPROC;
  int count = NPROC;
  while(hs[hash_id].pid != pid && count--) hash_id++;
  if(!count){
    cprintf("Find pid in hash table error!\n");
    insert_new_pid(pid);
  }
  return hash_id;
}
// Insert new pid to hash_table
int
insert_new_pid(int pid)
{
	int hash_id = pid % NPROC;
	int count = NPROC;
	while(hs[hash_id].exist && count--)	hash_id++;
	if(!count){
		cprintf("No empty space for process!\n");
		return -1;
	}
	hs[hash_id].exist = 1;
	hs[hash_id].count = 0;
	return hash_id;
}
// Erase pid in hash_table when pid is killed.
void
erase_pid(int pid)
{
	int hash_id = get_processor_hash(pid);
	hs[hash_id].exist = 0;
	hs[hash_id].count = 0;
}