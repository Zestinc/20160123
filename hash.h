#define NPROCC 64
struct htable{
	int pid;
	int count;
	int exist;
};
static struct htable hs[NPROCC];
// return the hash number of specific pid;


int get_processor_hash(int pid);
int insert_new_pid(int pid);
void erase_pid(int pid);