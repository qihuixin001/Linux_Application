#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int num = 100;

int main(void)
{
    pid_t pid = -1;
    
    printf("create new process.\n\n");
    
    pid = fork();
    if (pid == 0)
    {
        /*child*/
        printf("i am child, my pid is %d\n", getpid());
        //execl("/work/study/linux/process/002_exec/test", "test", NULL);
        execlp("ls", "ls", "-al", NULL);
        printf("i am child, my pid is %d\n", getpid());  //ignore
        exit(0);
    }
    else if (pid > 0)
    {
        /*father*/
        printf("i am father, my pid is %d.\n", getpid());
        printf("i am father, my son pid is %d.\n", pid);
        exit(0);
    }
    else
    {
        printf("error.\n");
        exit(-1);
    }

    return 0;
}


