#include <stdio.h>
#include <unistd.h>
int rmdir(char *dir)
{
	if (rmdir(dir) == -1)
	{
		perror("failed!");
		return 1;
	}
	printf("remove successful!\n");
	return 0;
}
