#include<stdio.h>
#include<unistd.h>
int main()
{
printf("Before execvvp()\n");
int status=execvp("ls",("ls","-l",NULL));
if (status==-1)
{
printf("Terminated Incorrectly\n");
}
printf("This will not get printed");
}
