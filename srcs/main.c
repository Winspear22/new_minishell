/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:07:53 by adaloui           #+#    #+#             */
/*   Updated: 2022/02/26 16:52:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

struct s_ectx	*g_ectx;

/*int	error_cmd_handling(char *message, char *str)
{
	if (1)
	{
		write(2, message, ft_strlen(message));
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	return (0);
}

void	*error_cmd(char *message, char *str)
{
	error_cmd_handling(message, str);
	return (NULL);
}

char	*path_add(char *location, char *cmd)
{
	char	*str;

	str = ft_strjoin(location, "/");
//	printf("%s\n", str);
	if (!str)
		return (NULL);
//	printf("%s\n", str);
	str = ft_strjoin(str, cmd);
//	printf("%s\n", str);
	if (!str)
	{	
		free(str);	
		return (NULL);
	}	
	return (str);
}

char	*get_file_location(char *cmd, char **location)
{
	char	*cmd_location;
	int		fd;
	char	*str;

	str = "Error";
	int i = 0;
	while (*location)
	{
		cmd_location = path_add(*location, cmd);
		fd = open(cmd_location, O_RDONLY);
		if (fd > 0)
		{	
			close(fd);
			return (cmd_location);
		}
		free(cmd_location);
		location++;
	}
	error_cmd("zsh: command not popo found: ", cmd);
	return (str);
}

char *parse_cmd_bin(char **cmd, char **paths)
{
	char *str;

	str = NULL;
	if (ft_strncmp(cmd[0], "/bin/", 5) == 0)
	{
		cmd = ft_split(cmd[0], '/');
		if (cmd[1] != NULL)
		{
			ft_strlcpy(cmd[0], cmd[1], ft_strlen(cmd[0]));
			cmd = ft_split(cmd[1], ' ');
			str = get_file_location(cmd[0], paths);
			return (str);
		}
		else	
			error_cmd("zsh: command not found: ", "/bin/");
	}
	return (str);
}
char *parse_cmd_2(char **cmd, char **paths, int i)
{
	char *str;
	if (ft_strncmp(cmd[i], "/bin/", 5) != 0)
		str = get_file_location(cmd[i], paths);
	if (ft_strncmp(cmd[i], "/bin/", 5) == 0)
		str = parse_cmd_bin(cmd, paths);
	return (str);
}

char	**get_cmd_location(char **envp)
{
	char	**location;
	char str[] = "/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
	while (*envp)
	{
		if (ft_strnstr(*envp, "PATH", 10))
		{
			while (**envp != '/')
				*envp += 1;
			location = ft_split(*envp, ':');
			return (location);
		}
		envp++;
	}
	location = ft_split(str, ':');
	return (location);
}

char	**get_file_paths(char **cmd, char **envp)
{
	char **paths;
	int i = 0;

	paths = get_cmd_location(envp);
	cmd[0] = parse_cmd_2(cmd, paths, i);
	ft_free_charr(paths);
	return (cmd);
	
}



void	exec_cmd(char **cmd, char **env)
{
	g_ectx->pid = 0;
	g_ectx->exit_value = 0;

	g_ectx->pid = fork();
	printf("coucou\n");
	if (g_ectx->pid < 0)
	{
		ft_free_charr(cmd);
		perror("Error with the fork process.\n");
	}
	else if (g_ectx->pid > 0) 
	{
		wait(&g_ectx->pid);
		//kill(pid, SIGTERM);
	} 
	else 
	{
		printf("salut\n");
		status_child();
		if (execve(cmd[0], cmd, env) == -1)
			perror("salut");
		exit(EXIT_FAILURE);
	}
	wait(&g_ectx->pid);
	status_child();
}

*/

void		status_child(void)
{
	if (WIFEXITED(g_ectx->pid))
		g_ectx->exit_value = WEXITSTATUS(g_ectx->pid);
	if (WIFSIGNALED(g_ectx->pid))
	{
		g_ectx->exit_value = WTERMSIG(g_ectx->pid);
		if (g_ectx->exit_value != 131)
			g_ectx->exit_value += 128;
	}
}

int	main(int argc, char **argv, char **env)
{
	g_ectx = malloc(sizeof(struct s_ectx));
	if (!g_ectx)
	{
		ft_system_error();
		return (0);
	}
	g_ectx->buffer = NULL;
	g_ectx->cmd = NULL;
	g_ectx->pwd = NULL;
	
	ft_signals();
	while (1)
	{
		g_ectx->pwd = getcwd(NULL, 0);
		g_ectx->buffer = readline(g_ectx->pwd);
		free(g_ectx->pwd);
		g_ectx->cmd = ft_split(g_ectx->buffer, ' ');
		if (g_ectx->cmd[0] == NULL)
			ft_putstr_fd(NULL, 0);
		if (g_ectx->cmd[0] != NULL)
		{
		/*	if (ft_is_built_in(g_ectx->cmd[0]) == 0) 
		{
			g_ectx->cmd = get_file_paths(g_ectx->cmd, env);
			printf("%s\n", g_ectx->cmd[0]);
			if (ft_strncmp(g_ectx->cmd[0], "Error", 6) != 0)
				exec_cmd(g_ectx->cmd, env);
		}
			else
				exec_built_in(g_ectx->cmd, env);
			g_ectx->cmd = get_file_paths(g_ectx->cmd, env);
			exec_cmd(g_ectx->cmd, env);*/
			add_history(g_ectx->buffer);
			free(g_ectx->buffer);
			if (ft_is_built_in(g_ectx->cmd[0]) == 1)
				exec_built_in(g_ectx->cmd, env);
			else
				ft_putstr_fd("built-in introuvable", 0);
			ft_free_charr(g_ectx->cmd);
		}
	}
	return (0);
}
