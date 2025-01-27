#include "arquivo.h"
#include "tools.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "erro!\n", 6);
		return (0);
	}

	int	fd;
	char  *str;
	fd = 0;

	fd = open_archive(argv[1][0]);
	str = get_word(fd, argv[1]);
	free(str);
	print_meaning(fd);
	return (0);
}
