/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:03:44 by user42            #+#    #+#             */
/*   Updated: 2022/02/23 23:02:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_is_built_in(char *cmd)
{
	const char	*built_in[] = {"pwd", "cd", "exit", "env", "export", "echo", "unset", NULL};
	int i;

	i = 0;
	while (built_in[i])
	{
		if (!strcmp(built_in[i], cmd))
			return (1); 
		i++;
	}
	return (0);
}

int	exec_built_in(char **built_in, char **envp)
{
	int ret;
	
	if (!ft_strcmp(built_in[0], "pwd"))
		ret = ft_builtin_pwd(built_in);
	else if (!ft_strcmp(built_in[0], "cd"))
		ret = ft_built_in_cd(built_in, envp);
	else if (!ft_strcmp(built_in[0], "exit"))
		ret = ft_built_in_exit(built_in, envp);
	else if (!ft_strcmp(built_in[0], "echo"))
		ret = ft_built_in_echo(built_in);
	else if (!ft_strcmp(built_in[0], "env"))
		ft_built_in_env(built_in, envp);
	else if (!ft_strcmp(built_in[0], "export"))
		printf("built_in executé avec succès\n");
	else if (!ft_strcmp(built_in[0], "unset"))
		ft_built_in_unset(built_in, envp);
	else
		return (FAILURE);
	return (ret + 0xFF);
}

/*int	builtin_load(char *str, int *fd)
{
	int		ret;
	char	**args;
	
	printf("popo\n");
	args = (char **)malloc(sizeof(char *) * ft_strlen(str + 1));
	args[0] = str;
	printf("lolo\n");
	if (!ft_strcmp(args[0], "echo"))
		printf("built in ok\n");
	//	ret = builtin_echo(args);
	else if (!ft_strcmp(args[0], "cd"))
	printf("built in ok\n");

	//	ret = builtin_cd(args);
	else if (!ft_strcmp(args[0], "pwd"))
		printf("built in ok\n");
	//	ret = builtin_pwd(args);
	else if (!ft_strcmp(args[0], "export"))
		printf("built in ok\n");
	//	ret = builtin_export(args);
	else if (!ft_strcmp(args[0], "unset"))
		printf("built in ok\n");
	//	ret = builtin_unset(args);
	else if (!ft_strcmp(args[0], "env"))
		printf("built in ok\n");
	//	ret = builtin_env(args);
	else if (!ft_strcmp(args[0], "exit"))
		printf("built in ok\n");
	//	ret = builtin_exit(args, fd);
	else
		return (FAILURE);
	return (ret + 0xff);
}*/