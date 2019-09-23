#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

  

int main(void)
{
    pid_t pid = -1;
    int fd[2] = {0, 0};
    int ret = 0;

    /* 1.create a pipe */
    ret = pipe(fd);
    if (ret != 0)
    {
        perror("pipe:");
    }

    /* 2.create process. */
    pid = fork();
    if (pid == 0)
    {
        /*child*/
        char str[32] = {0, };
        int  str_len = sizeof(str)/sizeof(str[0]);
        printf("i am child, my pid is %d\n", getpid());
	while(1)
        {
            printf("child process:please input a string(<32ch)!\n");
            memset(str, 0, str_len);
            scanf("%s", &str[0]);
            write(fd[1], str, str_len);
            if(!strncmp("over", str, strlen("over")))
            {
                break;
            }
        }	
        printf("child process:quit process!\n");
        close(fd[1]);
        exit(0);
    }
    else if (pid > 0)
    {
        /*father*/
        char str[32] = {0, };
        int  str_len = sizeof(str)/sizeof(str[0]);
        printf("i am father, my pid is %d.\n", getpid());
        while(1)
        {
            memset(str, 0, str_len);
            read(fd[0], str, str_len);
            printf("father process read: %s\n", str);
            if (!strncmp("over", str, strlen("over")))
            {
                break;
            }
        }
        printf("father process:quit process!");
        close(fd[0]);
        exit(0);
    }
    else
    {
        printf("error.\n");
        exit(-1);
    }

    return 0;
}


