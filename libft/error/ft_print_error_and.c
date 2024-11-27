/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:04:55 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/27 15:31:26 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_print_error_and_exit(char *message, int exit_number)
{
	ft_putstr_fd(message, STDERR_FILENO);
	exit(exit_number);
}

bool	ft_print_error_and_false(char *message)
{
	ft_putstr_fd(message, STDERR_FILENO);
	return (false);
}

bool	ft_print_error_and_true(char *message)
{
	ft_putstr_fd(message, STDERR_FILENO);
	return (true);
}

void *ft_print_error_and_null(char *message)
{
	ft_putstr_fd(message, STDERR_FILENO);
	return (NULL);
}







