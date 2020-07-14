#include <fcntl.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void	print_file(char *format)
{
	FILE	*fd;

	fd = fopen("visualizer_log.txt", "a+");
	fprintf(fd, "%s\n", format);
	fclose(fd);
}
