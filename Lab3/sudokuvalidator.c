#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <omp.h>
#include <sys/wait.h>

int sudoku[9][9];

void revfilas();
void revcolum();
void rev3x3();

int i,j;
int si,sj,flag;

//reporte de fallo en funciones (3)
void report(char *s,int i,int j)
{
   printf("\nSudoku incorrecto");
   printf("\nin %s. fila:%d,columna:%d",s,i+1,j+1);
   getch();
   exit(0);
}

int main(int argc, char *argv[]){
//abrir archivo
//argv es el segundo  operador
   int file = open(argv[1], O_RDONLY);
//guardamos las variables pera luego meterlas al array
   int counter = 0;
   char secuencia[81];
   int lista[81];
   read(file, &secuencia, 81);

   for(int i=0; contador=0; i<9; i++){
	for(int j = 0; j<9; ++j, contador++){
		sudoku[i][j] = secuencia[contador];
		}
}
//printf("%d ", sudoku[i][j]);
//for con funcionpara revisar 3x3 

//proceso hijo
   pid_t hijo = fork();
   if (hijo == 0)
    {
        pid_t procIntID = getppid();
        char proc[10];
        sprintf(proc, "%ld", (long int)procIntID);
//no sirve con excl
        char command[100] = "ps -p ";
        strcat(command, proc);
        strcat(command, " -lLf");
        printf("Executing command: %s\n", command);
        system(command);
    }
   //en el proceso padre
   else{
	pthread_t thread_idcolum, thread_idfilas, thread_id3x3;
	printf("-> Thread a string %lu", syscall(SYS_gettid));
	if (pthread_create(&thread_idcolum, NULL, &revcolum, NULL) != 0)
        {
            printf("Columnas fallarom.");
        }
        if (pthread_create(&thread_idfilas, NULL, &revfilas, NULL) != 0)
        {
            printf("Filas fallaron.");
        }
        if (pthread_create(&thread_id3x3, NULL, &rev3x3, NULL) != 0)
        {
            printf("3x3 fallo.");
	}
	wait(NULL);
	if(thread_idcolum==1 && thread_idfilas==1 && thread_id3x3==1){
	   printf("Sudoku valido!\n");
        }
        else
        {
            printf("Sudoku invalido!");
	}
   }
//nuevo fork
  	pid_t sChild = fork();

        if (sChild == 0)
        {
            pid_t procIntID = getppid();
            char proc[10];
            sprintf(proc, "%ld", (long int)procIntID);

            char command[100] = "ps -p ";
            strcat(command, proc);
            strcat(command, " -lLf");
            printf("Executing command: %s\n", command);
            system(command);
        }
        else {
            wait(NULL);
            return 0;
        }

}


void rev3x3(){
for(si=0;si<3;si++)
    {
    for(sj=0;sj<3;sj++)
        {
        flag=0x0000;
        for(i=0;i<3;i++)
            {
            for(j=0;j<3;j++)
                flag|=1<<(sudoku[si*3+i][sj*3+j]-1);

            }
        if(flag!=0x01FF)
                report("3x3",si*3+i-1,sj*3+j-1);
        }
    }

void revfilas(){
for(i=0;i<9;i++)
    {
    flag=0x0000;
    for(j=0;j<9;j++)
        flag|=1<<(sudoku[i][j]-1);
    if(flag!=0x01FF)
        report("fila",i,j-1);
    }
}

void revcolum(){
for(j=0;j<9;j++)
    {
    flag=0x0000;
    for(i=0;i<9;i++)
        flag|=1<<(sudoku[i][j]-1);
    if(flag!=0x01FF)
        report("col",i-1,j);
    }
}


}
