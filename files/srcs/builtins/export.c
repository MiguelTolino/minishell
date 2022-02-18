/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:19:52 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/18 19:38:09 by rgirondo         ###   ########.fr       */
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

char    *getvar(char *cmd)
{
	int i;
	char *str;
	char *var_name;
	int len;

	i = 0;
	str = 0;
	var_name = get_name(global.env[i]);
	if (var_name && ft_strlen(var_name) > ft_strlen(cmd))
		len = ft_strlen(var_name);
	else
		len = ft_strlen(cmd);
	while (global.env[i] && ft_strncmp(var_name, cmd, len))
	{
		free(var_name);
		i++;
		var_name = get_name(global.env[i]);
		if (var_name && ft_strlen(var_name) > ft_strlen(cmd))
			len = ft_strlen(var_name);
		else
			len = ft_strlen(cmd);
	}
	if (var_name)
		free(var_name);
	if (global.env[i])
		str = global.env[i] + (ft_strlen(cmd) + 1);
	else if (!ft_strncmp(cmd, "?", ft_strlen(cmd)))
		return (ft_strdup(ft_itoa(global.exit_status)));
	else
		return (NULL);
	return (ft_strdup(str));
}

char *get_name(char *cmd)
{
	int i;
	char *str;

	i = 0;
	if (!cmd)
		return(NULL);
	while (cmd[i] && cmd[i] != '=')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
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
	char **tmp;

	i = 0;
	tmp = global.env;
	global.env_len += 1;
	global.env = init_env(tmp);
	free_matrix(tmp);
	while (global.env[i])
		i++;
	global.env[i] = ft_strdup(new_var);
	global.env[i + 1] = NULL;
}

void change_val(char *var_name, char *cmd)
{
	int i;

	i = 0;
	while (!ft_strnstr(global.env[i], var_name, ft_strlen(var_name)) && global.env[i])
		i++;
	free(global.env[i]);
	global.env[i] = ft_strdup(cmd);
}

void export(char **cmd)
{
	char *new_var;
	char *var_name;
	int i;

	i = 1;
	while (cmd[i])
	{
		if (cmd[i])
		{
			var_name = get_name(cmd[i]);
			new_var = getvar(var_name);
			if (ft_strchr(cmd[i], '=') && !new_var)
				add_new(cmd[i]);
			else if (ft_strchr(cmd[i], '=') && new_var)
				change_val(var_name, cmd[i]);
			if (var_name)
				free(var_name);
		}
		i++;
	}	
}