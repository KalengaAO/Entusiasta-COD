#include <string.h>
#include <stdlib.h>
#include "tools.h"

char	*init_str_din(void)
{
	char	*str;

	if (!(str = (char *) malloc(sizeof(char))))
		exit(EXIT_FAILURE);
	str[0] = '\0';
	return (str);
}
