#ifndef		ARQUIVO_H
#define		ARQUIVO_H

#include <stdlib.h>
#include <unistd.h>

int	open_archive(char file);
char	*get_word(int fd, char *src_word);
void	print_meaning(int fd);

#endif
