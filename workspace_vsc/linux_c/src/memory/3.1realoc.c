#include <stdlib.h>
#include <stdio.h>
_main()
{
    char *p;
    p = (char *)malloc(100);
    if (p)
        printf("Memory Allocated at: %x", p);
    else
        printf("Not Enough Memory!\n");
    getchar();
    p = (char *)realloc(p, 256);
    if (p)
        printf("Memory Reallocated at: %x", p);
    else
        printf("Not Enough Memory!\n");
    free(p);
    getchar();
    return 0;
}
