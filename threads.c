#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>



void SimpleThread(int);

int SharedVariable = 0; 

int main( int argc, char *argv[]){
	
	printf("*** The Program has Started\n");

	int SharedVariable = 0; 

	
		
}

void SimpleThread (int which){

	int num, val;
	for(num = 0; num < 20; num++){
		if(random()> RAND_MAX/2)
			usleep(500);
	
		val = SharedVariable;
		printf("*** thread %d sees value %d\n", which, val);
		SharedVariable = val +1 ;	
	}
	
	val = SharedVariable;
	printf("Thread %d sees final value %d\n", which, val);

}
