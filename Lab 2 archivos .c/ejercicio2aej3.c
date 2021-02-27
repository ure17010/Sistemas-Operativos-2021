#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
   pid_t pid1, pid2, pid3;
   clock_t tiempo1, tiempo2;
   double resultado;
   int i;

   tiempo1 = clock();
   printf("Empezando..., tiempo1 = %lu\n", tiempo1);
   pid1 = fork();
   if (pid1== 0){
	pid2 = fork();
	if(pid2 == 0){
		pid3 = fork();
		for(i; i<1000000; i++){
		printf("I1");
		}
	}else{
		wait(NULL);
		for(i; i<1000000; i++){
		printf("I2");
		}
	}
	wait(NULL);
	for(i; i<10000000;i++){
	printf("I3");
	}
	}else{
		wait(NULL);
		tiempo2 = clock();
		resultado = (double)(tiempo2 - tiempo1);
		printf("\ntiempo de cpu: %f\n", resultado);
	}
	return(0);
       }
