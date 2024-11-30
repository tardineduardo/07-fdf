/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok_multi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:19:39 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/28 20:45:45 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// typedef struct s_token
// {
// 	char			*current_token;
// 	char			*next_token_ptr;
// 	struct s_token	*next;	
// } t_token;

static char	*ft_skip_delimiters(char *input_str, char *delimiters)
{
	int	index;

	index = 0;
	while (input_str[index] != '\0')
	{
		if (!ft_strchr(delimiters, input_str[index]))
			return (&input_str[index]);
		input_str[index] = '\0';
		index++;
	}
	return (NULL);
}

static char	*ft_mark_token_end(char *input_str, char *delimiters)
{
	int	index;

	if (!input_str)
		return (NULL);
	index = 0;
	while (input_str[index] != '\0' && !ft_strchr(delimiters, input_str[index]))
		index++;
	if (input_str[index] == '\0')
		return (NULL);
	input_str[index] = '\0';
	return (&input_str[index + 1]);
}

char	*ft_strtok(char *input_str, char *delimiters)
{
	static t_token	**tokens;
	t_token			*tokenized;

	if (!delimiters || delimiters[0] == '\0')
		return (NULL);

	tokenized = (ft_lst_find_value(tokens, input_str, (offsetof(t_list, content) + offsetof(t_token, original))));

	if (!tokenized)
		return (ft_new_string(tokens, input_str));
	else
		return (ft_existing_string(tokens, tokenized));
}

static	char *ft_new_string(t_list **head, char *input_string)
{


	if (!(*tokens)->next_token_ptr)
		return (NULL);
	else if (input_str)
	{
		current_token = ft_skip_delimiters(input_str, delimiters);
		next_token_ptr = ft_mark_token_end(current_token, delimiters);
	}
	else
	{
		current_token = ft_skip_delimiters(next_token_ptr, delimiters);
		next_token_ptr = ft_mark_token_end(current_token, delimiters);
	}
	return (current_token);
}
