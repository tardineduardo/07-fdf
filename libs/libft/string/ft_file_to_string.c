#include "../libft.h"

bool ft_check_errors(int file, char *str)
{
    if (file < 0 && !str)
    {
        return (true);
    }
    if (file < 0 && str)
    {
        free(str);
        return (true);
    }
    if (file >= 0 && !str)
    {
        close(file);
        return (true);
    }
    if (file >= 0 && str)
    {
        free(str);
        return (false);
    }
    return (true);
}

char *ft_parse_fd_to_string(char *filename)
{
	int		file;
	int		sread;
	char	*cont;
	char	*temp;
	char	buffer[BUFFER_SIZE + 1];

	file = open(filename, O_RDONLY);
	cont = ft_calloc(1, sizeof(char));
	if (ft_check_errors(file, cont))
		return (NULL);
	while (1)
	{
		sread = read(file, buffer, BUFFER_SIZE);
		buffer[sread] == 0;
		temp = cont;
		cont = ft_strjoin(cont, buffer);
		free(temp);
		if (!cont)
			return(ft_free_and_null(cont));
		if (sread < BUFFER_SIZE)
			break;
	}
	close(file);
	return (cont);
}

void ft_parse_fd_to_string_void(char *filename, char *cont)
{
	int		file;
	int		sread;
	char	*cont;
	char	*temp;
	char	buffer[BUFFER_SIZE + 1];

	file = open(filename, O_RDONLY);
	cont = ft_calloc(1, sizeof(char));
	if (ft_check_errors(file, cont))
		return (NULL);
	while (1)
	{
		sread = read(file, buffer, BUFFER_SIZE);
		buffer[sread] == 0;
		temp = cont;
		cont = ft_strjoin(cont, buffer);
		free(temp);
		if (!cont)
			return(ft_free_and_null(cont));
		if (sread < BUFFER_SIZE)
			break;
	}
	close(file);
}