/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:52:43 by yafilali          #+#    #+#             */
/*   Updated: 2024/07/28 00:54:10 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putendl(char *string, int fd)
{
	int	i;

	i = 0;
	if (!string || string[i] == '\0')
		return ;
	while (string[i])
	{
		write(fd, &string[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_error(void)
{
	ft_putendl("Error", 2);
	exit(EXIT_FAILURE);
}

void	ft_free(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
}
