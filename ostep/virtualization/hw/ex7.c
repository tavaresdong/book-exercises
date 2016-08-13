#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>


int main(int argc, char **argv)
{
    int x = 10;
    int rc = fork();
    if (rc == 0) 
    {
        close(STDOUT_FILENO);
        fprintf(stdout, "HELLO\n");
    }
    else
    {
        int wt = wait(NULL);
        fprintf(stdout, "goodbye\n");
    }
    return 0;
}
