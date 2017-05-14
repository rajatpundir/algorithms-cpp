#include<stdio.h>
#include<string.h>
#include<sys/ipe.h>
#include<sys/types.h>
#include<sys/shm.h>
int main()
{
	int shmid;
	void *ptr;
	key_t key;
	key = ftok(".\\",'A');
	shmid = shmget(key, 1024, 0666|IPC_CREAT);
	ptr = shmat(shmid, NULL, 0);
	puts("\nEnter data for shared memory\n");
	gets(ptr);
	shmdt(ptr);
	return 0;
}