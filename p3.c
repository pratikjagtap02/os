#include<stdio.h>
#include<sys/types.h>

void main()
{
    pid_t pid;
    pid=fork();

    if(pid == 0)
    {
        sleep(5);
        printf("\nIn child process..\n");
        printf("\nchild process id:%d\n",getpid());
        printf("\nparent id from child:%d",getppid());
        
    }

    else
    {
        printf("In parent process...\n");
        printf("\nparent process id: %d\n",getpid());
    }
}