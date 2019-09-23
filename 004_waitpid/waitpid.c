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
        printf("child process is running!\n");
        sleep(10);
        printf("child process is over!\n");
        exit(5);
    }
    else if (pid > 0)
    {
        /*father*/
        printf("i am father, my pid is %d.\n", getpid());
	printf("father process is running!, wait child quit\n");
	while(1)
	{
	    pid_t ret = waitpid(pid, &status, WNOHANG);
      	    if (ret == -1)
            {
                printf("not child process!\n");
            }
            else if (ret == 0)
            {
                printf("i am father process, child process is running!\n");
            }
	    else if (ret > 0)
  	    {
		printf("i am father process, child process(pid=%d) is over(%d)\n",\
                       ret,\
                       WIFEXITED(status) ? WEXITSTATUS(status) :\
                       WIFSIGNALED(status) ? WTERMSIG(status) : -1);
            }
	    sleep(1);
        }
        printf("father process is over!\n");
        exit(0);
    }
    else
    {
        printf("error.\n");
        exit(-1);
    }

    return 0;
}


