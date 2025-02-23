#include "arquivo.h"
#include "tools.h"
#include <fcntl.h>
#define		SIZE_EXT 5

char	*ft_creat_name(char c)
{
	int	i;
	char	*ext = ".txt";
	char	*file;

	if (!(file = (char *) malloc(sizeof(char) * SIZE_EXT)))
		return (0);
	i = 0;
	if (c >= 'a' && c <= 'z')
			c -= 32;
	file[i++] = c;

	while (*ext)
	{
		file[i++] = *ext;
		++ext;
	}
	file[i] = '\0';
	return (file);
}

int	open_archive(char file)
{
	int	fd;
	char	*name_file;

	name_file = ft_creat_name(file);
	fd = 0;
	if ((file >= 'A' && file <= 'Z') || (file >= 'a' && file <= 'z'))
	{
		fd = open(name_file, O_RDONLY);
		if (fd == -1)
		{
			ft_putstr(name_file);
			write(0, " Arquivo inexistente!\n", 22);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		write(0, "erro! Entrada invalida\n", 24);
		exit(EXIT_FAILURE);
	}
	free(name_file);
	return (fd);
}
