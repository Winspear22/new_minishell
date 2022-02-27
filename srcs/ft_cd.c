/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:28:06 by user42            #+#    #+#             */
/*   Updated: 2022/02/26 16:47:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int ft_built_in_cd(char **path, char **envp)
{
    char **home;
    
    if (path[1] == NULL)
    {
        home = ft_get_var_env(envp, "HOME");
        path[1] = home[0];
        if (chdir(path[1]) == -1)
		    perror("chdir()");
    }
    else if (path[2])
        return(ft_custom_error("cd: too many arguments"));
	if (chdir(path[1]) == -1)
		perror("chdir()");
    return (SUCCESS);
}