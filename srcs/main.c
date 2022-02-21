/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:07:53 by adaloui           #+#    #+#             */
/*   Updated: 2022/02/21 17:05:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*buffer = NULL;
	char	**cmd = NULL;
	char	*pwd;
	
	ft_signals();
	while (1)
	{
		pwd = getcwd(NULL, 0);
		buffer = readline(pwd);
		free(pwd);
		cmd = ft_split(buffer, ' ');
		if (cmd[0] == NULL)
			ft_putstr_fd(NULL, 0);
		if (cmd[0] != NULL)
		{
			add_history(buffer);
			free(buffer);
			if (ft_is_built_in(cmd[0]) == 1)
				exec_built_in(cmd, env);
			else
				ft_putstr_fd("built-in introuvable", 0);
		}
	}
	return (0);
}
