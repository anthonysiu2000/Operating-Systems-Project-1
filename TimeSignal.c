#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int globalSignalCount = 0;
//declares structures that store seconds and microseconds
struct timeval start, end;

void handle_sigfpe(int signum){
	if (globalSignalCount < 100000) {
		globalSignalCount++;
		return;
	}

		gettimeofday(&end, NULL);
		//obtains time elapsed in microseconds
		float seconds = end.tv_sec - start.tv_sec;
		float microseconds = end.tv_usec - start.tv_usec;
		float microElapsed = seconds * 1000000 + microseconds;
		float averageTime = microElapsed / 100000;

		//prints output
		printf("Exceptions Occurred: 100000\n");
		printf("Total Elapsed Time: %f microseconds\n", microElapsed);
		printf("Average Time Per Exception: %f microseconds\n", averageTime);
		exit(0);
}



int main(int argc, char *argv[]){

	gettimeofday(&start, NULL);

	//divides by zero 100000 times
	int a = 1;
	int b = 0;
	int c = 0;
	signal(SIGFPE, handle_sigfpe);
	c = a / b;

	return c;

}
