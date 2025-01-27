#include "arquivo.h"
#include "tools.h"
#include <string.h>
#include <stdio.h>

char	*init_input()
{
	char	*input;

	if (!(input = (char *) malloc(sizeof(char))))
		exit(EXIT_FAILURE);
	input[0] = '\0';
	return (input);
}

char	*get_word(int fd, char *src_word)
{
	char *buffer;
	char	*tmp;
	char	*input;
	int	len;

	if	(!(buffer = (char *) malloc(sizeof(char))))
		return (0);
	input = init_input();
	len = 0;
	while ((read(fd, buffer, 1) > 0) && ft_strcmp(input, src_word))
	{
		++len;
		tmp = input;
		if (!(input = (char *) malloc(sizeof(char) * (len + 1))))
			return (0);
		input[0] = '\0';
		ft_strcat(input, tmp);
		ft_strncat(input, buffer, 1);
		free(tmp);
		if (*buffer == ':')
		{
			len = 0;
			while (*buffer != '\n')
				read(fd, buffer, 1);
			free(input);
			input = init_input();
		}
	}
	input[len] = '\0';
	return (input);
}
