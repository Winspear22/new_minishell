/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:40:02 by user42            #+#    #+#             */
/*   Updated: 2022/02/27 17:49:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**realloc_envs(size_t size, char **envp)
{
	char	**new;
	size_t	i;

	if (!(new = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = 0;
	while (envp[i] && i < size)
	{
		new[i] = ft_strdup(envp[i]);
		i++;
	}
	new[size] = 0;
	//ft_free_charr(envp);
	return (new);
}

unsigned int
	str_chr(const char *s, char c)
{
	const char	*t;

	t = s;
	while (1)
	{
		if (!*t || *t == c)
			break ;
		t++;
		if (!*t || *t == c)
			break ;
		t++;
		if (!*t || *t == c)
			break ;
		t++;
		if (!*t || *t == c)
			break ;
		t++;
	}
	return (t - s);
}

unsigned int
	str_len(const char *s)
{
	register const char	*t;

	t = s;
	while (1)
	{
		if (!*t)
			return (t - s);
		t++;
		if (!*t)
			return (t - s);
		t++;
		if (!*t)
			return (t - s);
		t++;
		if (!*t)
			return (t - s);
		t++;
	}
}

static int
	ft_built_in_export_check(char *s)
{
	char			*p;

	p = s;
	while (*p)
	{
		if (!((*p >= 'a' && *p <= 'z')
				|| (*p >= 'A' && *p <= 'Z')
				|| (*p >= '0' && *p <= '9')
				|| (*p == '_')))
			return (ft_custom_error("export: not valid identifier"));
		p++;
	}
	return (SUCCESS);
}

static int
	ft_built_in_export_add(char *s, char *t, char **envp)
{
	char			*c;
	int				i;
	
	i = 0;
	if (ft_built_in_export_check(s))
		return (FAILURE);
	c = ft_strdup(t);
	if (!c)
		return (ft_system_error());*/
	while (envp[i])
		i++;
	printf("i = %d\n", i);
	printf("s = %s\n t = %s\n c = %s\n", s, t, c);
	envp = realloc_envs(i + 10, envp);
	envp[i - 1] = "POPOLOLOLOPGHJGHXHXWGHWGWRG<WEGW<G<RG<G<GF<FG<GF<G<";
	envp = realloc_envs(i + 10, envp);
	printf("salut\n");
	envp[i + 5] = "POPOLOLOLOPGHJGHXHXWGHWGWRG<";
	return (SUCCESS);
}



int ft_built_in_export(char **cmd, char **envp)
{
    unsigned int chr;
    char        tmp;
    char        *s;
    
    if (cmd[1] == NULL)
        ft_built_in_env(cmd, envp);
	else
    {
        s = cmd[1];
		chr = str_chr(s, '=');
		if (chr == str_len(s))
			ft_built_in_export_add(s, "", envp);
		else
		{
			tmp = s[chr];
			s[chr] = 0;
			ft_built_in_export_add(s, s + chr + 1, envp);
			s[chr] = tmp;
		}
    }
    return (SUCCESS);
}