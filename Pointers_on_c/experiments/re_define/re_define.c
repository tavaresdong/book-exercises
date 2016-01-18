#include <stdio.h>

int j = 2;
static int i = 2; 

int func()
{
    extern int i;
    printf("%d\n", i);
}
