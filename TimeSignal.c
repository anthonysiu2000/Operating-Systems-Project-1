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



	gettimeofday(&end, NULL);
	//obtains time elapsed in microseconds
	float seconds = end.tv_sec - start.tv_sec;
	float microseconds = end.tv_usec - start.tv_usec;
	float microElapsed = seconds * 1000000 + microseconds;
	float averageTime = microElapsed / 100000;

	//prints output
	printf("Exceptions Occurred: \n");
	printf("Total Elapsed Time: %f microseconds\n", microElapsed);
	printf("Average Time Per Exception: %f microseconds\n", averageTime);

	return 0;

}
