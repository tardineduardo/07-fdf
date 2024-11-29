/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_find_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:19:28 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/28 20:26:24 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_list *ft_lst_find_value(t_list **head, llong value, llong offset)
{
	t_list *trav;

	if (!head || !(*head))
		return (NULL);

	trav = *head;

	while (trav)
	{
		if (*(llong *)((char *)trav + offset) == value)
			return (trav);
		trav = trav->next;
	}
	return (NULL);
}
