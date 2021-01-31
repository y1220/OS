#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (){
	char str[100];
	int i;

	setbuf(stdout,0);
	fork();
	for(i=0; i<2; i++){
		if(fork()!=0){
		sprintf (str, "echo system with i=%d", i);
		system("echo i+i");
		}else{
			sprintf(str, "exec with i=%d", i);
			execlp("echo", "myPgrm", "i*i", NULL);
		}
	}
	return(0);
}