#include <stdio.h>
#include <time.h>
int main(){
   clock_t primero_t, segundo_t;
   double resultado_t;
   int i;
   primero_t = clock();
   printf("empezando ciclo de un millon de interaciones..., primero = %lu\n" , primero_t);
   for (i=0; i<1000000; i++){
   }
   for (i=0; i<1000000; i++){
   }
   for (i=0; i<1000000; i++){
   }
   segundo_t = clock();
   printf("Terminaron los 3 loops... Segundo = %lu\n", segundo_t);
   resultado_t = (double)(segundo_t - primero_t);
   printf("Tiempo de CPU: %f\n", resultado_t);
   return(0);
   }
