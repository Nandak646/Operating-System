#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
char* cmnd="ls";
char* argument[]={"ls","-l",NULL};
pid_t p=fork();
if(p==0)
{
printf("Child process\n");
int status=execvp(cmnd,argument);
if(status==-1)
{
printf("Terminated\n");
exit(1);
}
else
{
printf("Parent process\n");
printf("Done\n");
}
}
}
