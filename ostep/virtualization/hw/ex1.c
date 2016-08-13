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
        fprintf(stdout, "child: Original x is %d\n", x);
        x = 11;
        fprintf(stdout, "child: After changing, x is %d\n", x);
    }
    else
    {
        sleep(1);
        fprintf(stdout, "father: Original x is %d\n", x);
        x = 9;
        fprintf(stdout, "father: After changing, x is %d\n", x);
        int wc = wait(NULL);
    }
    return 0;
}
