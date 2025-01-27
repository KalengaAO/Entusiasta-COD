#include "tools.h"

char	*ft_strncat(char *dest, char *src, int nb)
{
	int i;
	int len;

	len = 0;
	while (dest[len] != '\0')
		len++;
	i = 0;
	while (i < nb && src[i] != '\0')
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}
