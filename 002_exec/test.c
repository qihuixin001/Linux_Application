#include <stdio.h>
#include <unistd.h>

static int number = 0;

int main(void)
{
    while(1)
    {
        printf("test:number = %d\n", number++);
        sleep(1);
    }

    return 0;
}


