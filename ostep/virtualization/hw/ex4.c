#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>


int main(int argc, char **argv)
{
    int x = 10;
    int rc = fork();
    if (rc == 0) 
    {
        char* argx[2];
        argx[0] = strdup("ls");
        argx[1] = NULL;
        execvp(argx[0], argx);
        fprintf(stdout, "This should not be printed\n");
    }
    else
    {
        int wt = wait(NULL);
        fprintf(stdout, "goodbye\n");
    }
    return 0;
}
