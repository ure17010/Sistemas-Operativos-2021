#include <stdio.h>
#include <sys/types.h>

int main(){
int i;
for (int i = 0; i<3; i++)
{
   fork();
   printf("fork\n");
}
}
