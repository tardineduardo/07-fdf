/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclistsize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:39:36 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/13 17:28:37 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_dclstsize(t_dll **tail)
{
	size_t	count_fwd;
	t_dll	*trav_fwd;

	if (*tail == NULL)
		return (0);
	trav_fwd = *tail;
	count_fwd = 1;
	trav_fwd = trav_fwd->next;
	while (trav_fwd != *tail)
	{
		count_fwd++;
		trav_fwd = trav_fwd->next;
	}
	return (count_fwd);
}
