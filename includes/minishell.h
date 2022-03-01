/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:08:32 by adaloui           #+#    #+#             */
/*   Updated: 2022/03/01 09:16:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <errno.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdint.h>

# define SUCCESS 0
# define FAILURE 1
# define NB_TOKEN 14

extern struct s_ectx	*g_ectx;

typedef struct s_decompte
{
	int i;
	int j;
}				t_decompte;

struct s_ectx
{
	char *buffer;
	char **cmd;
	char *pwd;
	pid_t pid;
	char **envp_2;
	int	exit_value;
	int	unset_minus;
};

enum e_token
{
	TOKEN_ERROR = -1,
	TOKEN_BLANK = 0,
	TOKEN_NEWLINE = 1,
	TOKEN_SEMICOLON = 2,
	TOKEN_PIPE = 3,
	TOKEN_RLEFT = 4,
	TOKEN_RRIGHT = 5,
	TOKEN_ALEFT = 6,
	TOKEN_ARIGHT = 7,
	TOKEN_COMMENT = 8,
	TOKEN_SQUOTE = 9,
	TOKEN_DQUOTE = 10,
	TOKEN_ESCAPE = 11,
	TOKEN_VAR = 12,
	TOKEN_WORD = 13
};

/*	FT_SIGNALS	*/
void	ft_signals(void);
void	ft_signals_handler(int signal);

/*	FT_ERRORS_HANDLERS	*/
void	ft_free_charr(char **path);
int		ft_custom_error(char *errstr);
int		ft_system_error(void);

/*	FT_BUILT_IN_CHECKER	*/
int		ft_is_built_in(char *cmd);
int		exec_built_in(char **built_in, char **envp);

/*	FT_PWD	*/
int		ft_builtin_pwd(char **argv);

/*	FT_CD	*/
int		ft_built_in_cd(char **path, char **envp);

/*	FT_EXIT	*/
int		ft_built_in_exit(char **cmd, char **envp);

/*	FT_ENV	*/
void	ft_built_in_env(char **built_in, char **env);

/*	FT_ECHO	*/
int		ft_built_in_echo(char **cmd);

/*	FT_UNSET	*/
int 	ft_built_in_unset(char **cmd, char **envp);

/*	FT_EXPORT	*/
int		ft_built_in_export(char **cmd, char **envp);

/*	FT_GET_VAR_ENV	*/
char	**ft_get_var_env(char **envp, char *str);
char	**ft_get_var_env_2(char **envp, char *var_env);

void		status_child(void);
char		**ft_env_cpy(char **envp, char **envp_2);


#endif