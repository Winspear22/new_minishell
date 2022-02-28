/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:10:54 by user42            #+#    #+#             */
/*   Updated: 2022/02/28 18:02:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_built_in_env(char **built_in, char **env)
{
	int i;
	int j;

	i = 0;
	if (built_in[1])
		ft_custom_error("env: aucun argument n'est possible");
	else
	{
		while (g_ectx->envp_2[i])
		{
			j = 0;
			while (g_ectx->envp_2[i][j] && g_ectx->envp_2[i][j] != '\n')
			{
				ft_putchar_fd(g_ectx->envp_2[i][j], 0);
				j++;
			}
			ft_putchar_fd('\n', 0);
			i++;
		}
	}
}