#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
printf("Before fork()\n");
pid_t p=fork();
printf("My id id: %d",getpid());
printf("Done\n");
return 0;
}
