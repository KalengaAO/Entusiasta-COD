#include "arquivo.h"
#include "tools.h"
#include <string.h>
#include <fcntl.h>

#define		SIZE_EXT 5

char	*ft_creat_name(char c)
{
	int	i;
	char	*ext = ".txt";
	char	*file;

	if (!(file = (char *) malloc(sizeof(char) * SIZE_EXT)))
		return (0);
	file[0] = '\0';
	ft_strcat(file, "/usr/lib/Dic/arq/");
	i = strlen("/usr/lib/Dic/arq/");
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

	fd = 0;
	name_file = ft_creat_name(file);
	fd = open(name_file, O_RDONLY);
	if (fd == -1)
		return (0);
	free(name_file);
	return (fd);
}
