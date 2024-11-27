/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:08:54 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/27 18:23:28 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static bool	ft_is_in_set(char *set, char c, int set_len)
{
	int	a;

	a = 0;
	while (a < set_len)
	{
		if (set[a] == c)
			return (true);
	}
	return (false);
}

char *ft_strtok(char *string, char *set)
{
	int			a;
	int			set_len;
	char		*ret_pnter;
	static char *nxt_token;


	if (!set || set[0] == 0 || (!string && !nxt_token))
		return (NULL);
	else if (string || !nxt_token)
	{
		ft_move_nx

	}
	else if (!string || nxt_token)
	{



	}
	return()
}

	if(!nxt_token)
	{
		a = 0;
		set_len = ft_strlen(set);
		while (string[a])
		{
			if (ft_is_in_set(set, string[a], set_len))
				string[a] = 0;
		}
		curr = string;
	}	
	return (ft_move_curr(curr));
}
