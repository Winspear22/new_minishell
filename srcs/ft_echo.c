/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 22:05:30 by user42            #+#    #+#             */
/*   Updated: 2022/02/23 23:06:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void ft_built_in_echo_n(char ***args, int *newline)
{
	char	**ptr;
	char	*s;

	ptr = *args;
	while (1)
	{
		if (*ptr && **ptr == '-' && *(*ptr + 1) == 'n')
		{
			s = *ptr;
			s++;
			while (*s == 'n')
				s++;
			if (!*s)
			{
				*newline = 0;
				ptr++;
				continue ;
			}
		}
		break ;
	}
	*args = ptr;
}



int ft_built_in_echo(char **cmd)
{
    int		newline;
	char	**ptr;

	ptr = cmd + 1;
	newline = 1;
	ft_built_in_echo_n(&ptr, &newline);
	while (1)
	{
		if (!*ptr)
			break ;
		if (printf("%s", *ptr++) < 0)
			return (ft_system_error());
		if (*ptr && printf(" ") < 0)
			return (ft_system_error());
	}
	if (!newline)
		return (SUCCESS);
	if (printf("\n") < 0)
		return (ft_system_error());
	return (SUCCESS);
}