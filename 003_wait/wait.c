#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

static int num = 100;

int main(void)
{
    pid_t pid = -1;
    pid_t ret = 0;
    int status = 0;
    
    printf("create new process.\n\n");
    
    pid = fork();
    if (pid == 0)
    {
        /*child*/
        printf("i am child, my pid is %d\n", getpid());
	sleep(10);
        exit(5);
    }
    else if (pid > 0)
    {
        /*father*/
        printf("i am father, my pid is %d.\n", getpid());
	pid_t ret = wait(&status);
	if (ret == -1)
        {
            printf("not child process!\n");
        }
	else
	{
	    printf("wait process pid is %d\n", ret);
	}
	if (WIFEXITED(status))
        {
            printf("normal exit, status:%d\n", WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status))
	{
            printf("signal exit, status:%d\n", WTERMSIG(status));	    
	}
        exit(0);
    }
    else
    {
        printf("error.\n");
        exit(-1);
    }

    return 0;
}


