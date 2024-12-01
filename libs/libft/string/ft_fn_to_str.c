#include "../libft.h"

static char	*ft_parse_text(int file)
{
	int		size_read;
	char	*content;
	char	*temp;
	char	buffer[BUFFER_SIZE + 1];

	content = ft_calloc(1, sizeof(char));
	if (!content)
		return (NULL);
	size_read = BUFFER_SIZE;
	while (size_read > 0)
	{
		size_read = read(file, buffer, BUFFER_SIZE);
		if (size_read == -1)
		{
			free(content);
			return (NULL);
		}
		buffer[size_read] = '\0';
		temp = content;
		content = ft_strjoin(content, buffer);
		free(temp);
	}
	return (content);
}

char	*ft_fn_to_str(char *filename)
{
	int		file;
	char	*content;

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (NULL);
	content = ft_parse_text(file);
	if (!content)
	{
		close(file);
		return(NULL);
	}
	close(file);
	return(content);
}
