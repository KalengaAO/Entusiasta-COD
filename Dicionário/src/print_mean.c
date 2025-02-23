#include "arquivo.h"
#include "tools.h"

void	print_meaning(int fd)
{
	char	*buffer;
	
	if (!(buffer = (char *) malloc(sizeof(char))))
		exit(EXIT_FAILURE);
	buffer[0] = '\0';
	while ((read(fd, buffer, 1)) && (*buffer != '\n'))
		ft_putchar(*buffer);
	ft_putchar(10);
	free(buffer);
	close(fd);
}
