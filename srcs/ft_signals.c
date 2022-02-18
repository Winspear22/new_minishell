/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:27:34 by adaloui           #+#    #+#             */
/*   Updated: 2022/02/18 09:11:39 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_signals_handler(int signal)
{
	if (signal == SIGINT)
	{
		ft_putstr_fd("\n", 0);
		ft_putstr_fd("\033[0;33muser\033[0;35m42->\033[0;37m", 0);
	}
	if (signal == SIGSEGV)
	{
		ft_putstr_fd("\nexit\n", 0);
		exit(EXIT_FAILURE);
	}
	if (signal == SIGQUIT)
		ft_putstr_fd("", 0);
}

void	ft_signals(void)
{
	signal(SIGINT, &ft_signals_handler);
	signal(SIGSEGV, &ft_signals_handler);
	signal(SIGQUIT, &ft_signals_handler);
}
