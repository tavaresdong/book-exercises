#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(int argc, char **argv)
{
    int x = 10;
    int rc = fork();
    if (rc == 0) 
    {
        fprintf(stdout, "hello\n");
    }
    else
    {
        sleep(1);
        fprintf(stdout, "goodbye\n");
    }
    return 0;
}
