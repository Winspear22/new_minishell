/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 22:59:07 by user42            #+#    #+#             */
/*   Updated: 2022/03/01 16:00:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_reinitialize_k(int i)
{
	static int k;

	printf("k unset avant = %d\n", k);
	if (k > 0)
		k++;
	if (k == 0)		
		k++;
	g_ectx->unset_minus = k;
	//if (g_ectx->unset_minus == 0)
		k = 0;
	printf("k unset après = %d\n", k);
	printf("unset_minus UNSET = %d\n", g_ectx->unset_minus);
}

void	ft_built_in_unset_2(char **cmd, char **envp, t_decompte p)
{
	while (cmd[++p.j])
	{
        while (envp[++p.i])
        {
            if (ft_strnstr(envp[p.i], cmd[p.j], ft_strlen(cmd[p.j])))
            {
				ft_reinitialize_k(g_ectx->unset_minus);
				if (envp[p.i][ft_strlen(cmd[p.j])] == '=')
				{
               		envp[p.i] = memset(envp[p.i], 0, ft_strlen(envp[p.i]));
                	while (envp[p.i])
                	{
                    	envp[p.i] = envp[p.i + 1];
                    	p.i++;
                	}
                	p.i = 0;
                	break ;
				}
            }
		}
		p.i = 0;
    }
}

int ft_built_in_unset(char **cmd, char **envp)
{
	t_decompte p;
	g_ectx->unset_minus = 0;
    
    p.i = -1;
	p.j = 0;		
    if (cmd[1] == NULL)
        ft_putstr_fd("", 0);
    else
	{
	/*	if (k == 0)
			k = g_ectx->unset_minus;
		printf("k unset avant = %d\n", k);
		if (k > 0)
			k++;
		if (k == 0)
			k++;
		g_ectx->unset_minus = k;
		//if (g_ectx->unset_minus == 0)
			k = 0;*/
		ft_built_in_unset_2(cmd, g_ectx->envp_2, p);
		/*printf("k unset après = %d\n", k);
		printf("unset_minus UNSET = %d\n", g_ectx->unset_minus);*/

	}
    return (SUCCESS);
}
