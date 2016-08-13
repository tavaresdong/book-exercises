#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    int fds[2];
    pipe(fds);
    int x = 10;
    int rc = fork();
    if (rc == 0) 
    {
        // Another child
        dup2(fds[1], STDOUT_FILENO);
        close(fds[1]);
        close(fds[0]);
        execlp("ls", "ls", (char* ) NULL);
    }

    rc = fork();
    if (rc == 0)
    {
        // One child
        dup2(fds[0], STDIN_FILENO);
        close(fds[1]);
        close(fds[0]);
        execlp("wc", "wc", "-l", (char *) NULL);
    }

    // Why we should close before wait?
    close(fds[0]);
    close(fds[1]);
    wait(NULL);
    wait(NULL);
    
    exit(0);
}
