#ifndef		ARQUIVO_H
#define		ARQUIVO_H

#include <stdlib.h>
#include <unistd.h>
#include <gtk/gtk.h>

int	open_archive(char file);
char	*get_word(int fd, const char *src_word);
char	*print_meaning(int fd);

#endif
