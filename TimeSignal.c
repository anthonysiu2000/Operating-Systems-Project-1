#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>


void handle_sigfpe(int signum){

	// Handler code goes here

}

int main(int argc, char *argv[]){

	//declares structures that store seconds and microseconds
	struct timeval start, end;
	gettimeofday(&start, NULL);

	for (int i = 0; i < 100000; i++) {
		getpid();
	}

	gettimeofday(&end, NULL);
	//obtains time elapsed in microseconds
	long seconds = end.tv_sec - start.tv_sec;
	long microseconds = end.tv_usec - start.tv_usec;
	long microElapsed = seconds * 1000000 + microseconds;
	long averageTime  = microElapsed / 100000;

	//prints output
	printf("Syscalls Performed: 100000\n");
	printf("Total Elapsed Time: %d microseconds\n", microElapsed);
	printf("Average Time Per Syscall: %d microseconds\n", averageTime);

	return 0;

}
