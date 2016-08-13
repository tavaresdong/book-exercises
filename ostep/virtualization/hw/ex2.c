#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>


int main(int argc, char **argv)
{
    int x = 10;
    int fd = open("test.txt", O_WRONLY | O_CREAT, 0644);
    int rc = fork();
    if (rc == 0) 
    {
        char c[10] = "good\n";
        for (int i = 0; i < 1000; i++)
            write(fd, &c, sizeof(c)); 
        close(fd);
    }
    else
    {
        char c[10] = "job\n";
        for (int i = 0; i < 1000; i++)
            write(fd, &c, sizeof(c));
        int wc = wait(NULL);
        close(fd);
    }
    return 0;
}
