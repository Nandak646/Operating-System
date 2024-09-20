#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
printf("Begin\n");
pid_t p=fork();
if(p<0)
{
printf("Fork failed\n");
}
else if(p==0)
{
printf("Child process\n");
}
else
{
printf("Parent process\n");
wait(NULL);
printf("Child Terminated\n");
}
printf("Done\n");
}

