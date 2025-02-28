#ifndef		TOOLS_H
#define		TOOLS_H

#include <unistd.h>

char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, int n);
char	*init_str_din(void);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
void	ft_putchar(char c);

#endif
