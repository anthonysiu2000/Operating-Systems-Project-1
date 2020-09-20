#include <stdlib.h>
#include <stdio.h>


void handle_sigfpe(int signum){

	// Handler code goes here

}

int main(int argc, char *argv[]){

	//prints output
	printf("Exceptions Occurred: \n");
	printf("Total Elapsed Time: %f microseconds\n", microElapsed);
	printf("Average Time Per Exception: %f microseconds\n", averageTime);

	return 0;

}
