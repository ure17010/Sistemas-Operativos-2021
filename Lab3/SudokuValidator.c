#include <sys/mman.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>

char sudoku[9][9] = {0}; //inicializamos array
int i,j,ni,nj;
pthread_t pthread;
pid_t pid1;


#pragma omp parallel for
for(int i=0;i<9;i++){
	for(int j=0;j<9;j++){
		fscanf(fptr, "%c",&sudoku[i][j]);
		printf("%c",sudoku[i][j]);
		}//termina loop del scan
	}// termina loop filas

int main(){
	FILE *fptr;
	fptr = fopen("Lab3/sudoku.21","r");
	const char* DirecMem = static_cast<const char*>(mmap(NULL, length, PROT_READ, MAP_PRIVATE, fptr, 0u));
//revisada cuadro 3x3
	void revtresxtres(int sudoku[i][j]){
		#pragma omp parallel for
		for(ni=0;ni<3;ni++){
			for(nj=0;nj<3;nj++){
				flag = 0x0000;
				for(i=0;i<3;i++){
					for(j=0;j<3;j++){
						flag|=1<<(sudoku[ni*3+1][nj*3+j]-1);
						}//loop afuera
				if(flag!=0x01FF)
					report("3x3",ni*3+i-1,nj*3+j-1);
	}//loop medio
	}//loop medio2
		}//loop inicial
			}//funcion 3x3
	void revtresxtres(int sudoku[i][j]);
//revisada por columnas
	void revcol(int sudoku[i][j]){
		#pragma omp parallel for
		for(j=0;j<9;j++){
			flag=0x0000;
			for(i=0;i<9;i++)
				flag|=1<<(sudoku[i][j]-1);
			if(flag!=0x01FF)
				report("col", i-1,j);
	}//loops
	}//funcion columnas
//funcion filas
	void revfilas(int sudoku[i][j]){
		#pragma omp parallel for
		for(i=0;i<9;i++){
			flag=0x0000;
			for(j=0;j<9;j++)
				flag|=1<<(sudoku[i][j]);
			if(flag!=0x01FF)
				report("fila",i,j-1);
}//loops
}//funcion filas

	pid_t pid1 = getpid();
	print("pid: %lun", pid1);
	//en el proceso padre
	p_thread t1;
	pthread_create(&t1,NULL,revcol,int sudoku[i][j]);
	int pthread_join(t1,NULL);
	syscall(SYS_gettid);

	fork();//proceso hijo
	printf("primer fork \n");
	//covertir numero de proceso padre a texto
	execlp(ps -p >#proc> -lLf);
	wait();
	revfilas(int sudoku[i][j]);
	printf("\El sudoku es valido!");
	fork();
	execlp(ps -p >#proc> -lLf);
	wait();
	return 0;

}//main
