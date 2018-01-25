#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>


//-------------------
void* SimpleThread();
void* say_hello();
int validateInput(char*, int);
//-------------------
int SharedVariable = 0; 
//-------------------

int main( int argc, char *argv[]){
	
	printf("*******************************\n");
	printf("*** The Program has Started ***\n");
	printf("*******************************\n");

	char *c;// this is basically a string
	c = (argv[1]);
	
	int result = validateInput(c, argc);

	if(result == 0){
		printf("Please enter a NUMBER greater than 0\n ");
		return 0;
	}

	pthread_t myThread[result];

	for (int i = 0; i < result; i++ ){
	 
		printf("this is argc: %d and this is i: %d\n" ,argc , i);

		pthread_create(&myThread[i], NULL, SimpleThread, &i );

	}// end of for

	for (int i=0; i < result; i++){

		pthread_join(myThread[i], NULL);

	}
		
}

//if you add 0 to a char, it basically returns its ASCII value.
//so if we do char - 48 we get the actual digit from ASCII (0 = 48 ASCII)
int validateInput(char* input, int argc){

	int result = 0;	
	if (argc != 2)
		return result;
	result = atoi((char*)input);

	return result;

}//so far this validates the first char of the input, also needs to validate that there is one
//input

void* say_hello(void* data)
{
    char *str;
    str = (char*)data;
 
        printf("%s\n",str);

}

void* SimpleThread (int* which){

	int *limit_ptr = (int*)which;
	int TID = *limit_ptr;

	printf("this is TID %d \n",TID);

	int num, val;
	for(num = 0; num < 20; num++){
		if(random()> RAND_MAX/2)
			usleep(500);
	
		val = SharedVariable;
		printf("*** thread %d sees value %d\n", TID, val);
		SharedVariable = val +1 ;	
	}
	
	val = SharedVariable;
	printf("Thread %d sees final value %d\n", TID, val);

}
