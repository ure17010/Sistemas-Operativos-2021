#include <stdio.h>
#include <sys/types.h>
int main(){
fork();
fork();
fork();
fork();
printf("fork\n");
return 0;
}
