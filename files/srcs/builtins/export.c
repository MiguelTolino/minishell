/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:19:52 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/14 20:23:49 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *free_join(char *join, char *str)
{
	char *s;

	s = 0;
	if (join)
	{
		s = ft_strjoin(join, str);
		free(join);
	}
	return (s);
}

char *getvar(char *cmd)
{
	int i;
	char *str;
	char **vars;

	i = 0;
	str = NULL;
	vars = global.env;
	while (vars[i] && !ft_strnstr(vars[i], cmd, ft_strlen(cmd)))
		i++;
	if (vars[i] && ft_strnstr(vars[i], cmd, ft_strlen(cmd)))
	{
		if (vars[i][ft_strlen(cmd)] == '=')
			str = vars[i] + (ft_strlen(cmd) + 1);
	}
	else
		return (NULL);
	return (str);
}

char *get_name(char *cmd)
{
	int i;
	char *str;

	i = 0;
	str = (char *)malloc(1);
	while (cmd[i] && cmd[i] != '=')
	{
		str[i] = cmd[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void add_new(char *new_var)
{
	int i;

	i = 0;
	while (global.env[i])
		i++;
	global.env[i] = ft_strdup(new_var);
	global.env[i + 1] = NULL;
}

void change_val(char *var_name, char *cmd)
{
	int i;

	i = 0;
	while (global.env[i] && !ft_strnstr(global.env[i], var_name, ft_strlen(var_name)))
		i++;
	free(global.env[i]);
	global.env[i] = ft_strdup(cmd);
}

void export(char *cmd)
{
	char *new_var;
	char *var_name;

	if (cmd)
	{
		var_name = get_name(cmd);
		new_var = getvar(var_name);
		if (ft_strchr(cmd, '=') && !new_var)
			add_new(cmd);
		else if (ft_strchr(cmd, '=') && new_var)
			change_val(var_name, cmd);
		free(var_name);
	}
}