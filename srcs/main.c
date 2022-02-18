/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:07:53 by adaloui           #+#    #+#             */
/*   Updated: 2022/02/18 11:14:41 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*buffer;
	int		i;
	
	i = 0;
	ft_signals();
	while (1)
	{
		buffer = readline("\033[0;33madaloui\033[0;35m42->\033[0;37m");
		if (strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			while (i <= 150)
			{
				close(i);
				i++;
			}
			return (0);
		}
	}
	return (0);
}
