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
	int	pos;

	if (src_word[0] >= 'a' && src_word[0] <= 'z')
		src_word[0] -= 32;

	if	(!(buffer = (char *) malloc(sizeof(char))))
		return (0);
	input = init_input();
	len = 0;
	pos = -1;
	while ((read(fd, buffer, 1) > 0) && pos)
	{
		++len;
		tmp = input;
		if (!(input = (char *) malloc(sizeof(char) * (len + 1))))
			exit(EXIT_FAILURE);
		input[0] = '\0';
		ft_strcat(input, tmp);
		ft_strncat(input, buffer, 1);
		free(tmp);
		pos = ft_strcmp(input, src_word);
		if (*buffer == ':')
		{
			len = 0;
			while (*buffer != '\n')
				read(fd, buffer, 1);
			free(input);
			input = init_input();
		}
	}
	if (pos != 0)
	{
		write(1, "Palavra não encontrada!\n", 25);
		exit(EXIT_FAILURE);
	}
	input[len] = '\0';
	return (input);
}
