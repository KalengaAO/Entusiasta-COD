#include "arquivo.h"
#include "tools.h"

char	*print_meaning(int fd)
{
	char	*buffer;
	char	*tmp;
	char	*input;
	size_t	len;

	buffer = init_str_din();
	input = init_str_din();
	len = 0;
	while ((read(fd, buffer, 1)) && (*buffer != '\n'))
	{
		len++;
		tmp = input;

		if (!(input = (char *) malloc(sizeof(char) * len + 1)))
			exit(EXIT_FAILURE);
		input[0] = '\0';
		ft_strcat(input, tmp);
		ft_strncat(input, buffer, 1);
		free(tmp);
	}
	free(buffer);
	close(fd);
	input[len] = '\0';
	return (input);
}
