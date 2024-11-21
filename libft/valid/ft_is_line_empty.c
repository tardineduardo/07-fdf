#include "../libft.h"

bool ft_is_line_empty(char *s)
{
	while (*s)
	{
		if (!(ft_isspace(*s)) && *s !='\n')
			return (false);
		s++;	
	}
	return (true);
}