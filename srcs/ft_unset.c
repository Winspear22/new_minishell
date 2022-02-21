/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 22:59:07 by user42            #+#    #+#             */
/*   Updated: 2022/02/21 23:54:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int ft_built_in_unset(char **cmd, char **envp)
{
    char **env_var;
    int i;
    
    i = 0;
    if (cmd[1] == NULL)
        printf("\n");
    else
    {
        env_var = ft_get_var_env_2(envp, cmd[1]);
        if (env_var != NULL)
        {
            while (env_var[i])
            {
                printf("env_var = %s\n", env_var[i]);
                i++;
            }
        }
    }
    return (SUCCESS);
}