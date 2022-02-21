/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:09:23 by user42            #+#    #+#             */
/*   Updated: 2022/02/21 17:51:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int ft_calc_exit_nb(char *cmd, int *i)
{
	long	lim;
	int		signe;

	lim = 0;
	while (*cmd == ' ' || *cmd == '\t' || *cmd == '\n')
		cmd++;
	if (*cmd == '-')
	{
		signe = -1;
		cmd++;
	}
	else
		signe = 1;
	while (*cmd >= '0' && *cmd <= '9')
	{
		lim = lim * 10 + (*cmd++ - 48);
		if ((lim > 2147483647 && signe == 1) || (lim > 2147483648 && signe == -1))
			return (-1);
	}
	if (*cmd)
		return (-1);
	*i = signe * lim;
	return (0);
}


int ft_built_in_exit(char **cmd, char **envp)
{
    int i;
    int argc;
    int fout;
    int j;
    int fd[2];

    j = 0;
    argc = 0;
    if (cmd[1] == NULL)
        i = 0;
    else if (cmd[2])
        return (ft_custom_error("exit: too many arguments"));
    else
    {
        if (ft_calc_exit_nb(cmd[1], &i))
			return (ft_custom_error("exit: bad number"));
        printf("salut");
    }
    
    ft_free_charr(cmd);
    while (j <= 150)
    {
        close(j);
        j++;
    }
    printf("exit\n");
	exit(i);
}