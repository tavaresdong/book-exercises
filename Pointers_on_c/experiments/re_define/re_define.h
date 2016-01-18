#include <stdio.h>

static int i = 2; 

int func()
{
    extern int i;
    printf("%d\n", i);
}
