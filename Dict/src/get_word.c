#include "arquivo.h"
#include "tools.h"
#include <string.h>
#include <stdio.h>
#include <gtk/gtk.h>

char	*get_word(int fd, const char *src_word)
{
	char *buffer;
	char	*tmp;
	char	*input;
	char	*word;
	int	len;
	int	pos;

	word =(char *) src_word;
	if (word[0] >= 'a' && word[0] <= 'z')
		word[0] -= 32;

	len = 0;
	pos = -1;
	buffer = init_str_din();
	input = init_str_din();
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
		pos = ft_strcmp(input, word);
		if (*buffer == ':')
		{
			len = 0;
			while (*buffer != '\n')
				read(fd, buffer, 1);
			free(input);
			input = init_str_din();
		}
	}
	if (pos != 0)
		return('\0');
	free(buffer);
	input[len] = '\0';
	return (input);
}
