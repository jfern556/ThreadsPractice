#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>


//-------------------
void* SimpleThread(int);
void* say_hello();
int validateInput(char, int);
//-------------------
int SharedVariable = 0; 
//-------------------

int main( int argc, char *argv[]){
	
	printf("*******************************\n");
	printf("*** The Program has Started ***\n");
	printf("*******************************\n");

	char c;
	c = (*argv[1]);

	int result;
	
	result = validateInput(c, argc);

	printf("this is argc: %d and this is the number: %d\n" ,argc , result);

	pthread_t myThread;

	pthread_create(&myThread, NULL, say_hello, "Hello" );

	pthread_join(myThread, NULL);

	
		
}

//if you add 0 to a char, it basically returns its ASCII value.
//so if we do char - 48 we get the actual digit from ASCII (0 = 48 ASCII)
int validateInput(char input, int argc){
	
	if (argc != 2)
		return 0;
	int result = 0;
	if((input - 48) >=0 && (input - 48 ) <=9 )
		result = 1;
	return result;
}//so far this validates the first char of the input, also needs to validate that there is one
//input

void* say_hello(void* data)
{
    char *str;
    str = (char*)data;
 
        printf("%s\n",str);

}

void* SimpleThread (int which){

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
