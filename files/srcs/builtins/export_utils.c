/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:19:52 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/24 22:01:26 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	change_val(char *name, char *cmd)
{
	int		i;
	char	**aux;

	i = 0;
	aux = g_global.env;
	while (!ft_strnstr(aux[i], name, ft_strlen(name)) && aux[i])
		i++;
	aux = 0;
	free(g_global.env[i]);
	g_global.env[i] = ft_strdup(cmd);
}

void	add_new(char *new_var)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = g_global.env;
	g_global.env_len += 1;
	g_global.env = init_env(tmp);
	dfree(tmp);
	while (g_global.env[i])
		i++;
	g_global.env[i] = ft_strdup(new_var);
	g_global.env[i + 1] = NULL;
}

char	*free_join(char *join, char *str)
{
	char	*s;

	s = 0;
	if (join)
	{
		s = ft_strjoin(join, str);
		free(join);
	}
	return (s);
}

char	*getvar(char *cmd)
{
	int		i;
	char	*str;
	char	*var_name;

	i = 0;
	str = 0;
	var_name = get_name(g_global.env[i]);
	while (g_global.env[i] && ft_strcmp(var_name, cmd))
	{
		free(var_name);
		var_name = get_name(g_global.env[++i]);
	}
	if (var_name)
		free(var_name);
	if (g_global.env[i])
		str = g_global.env[i] + (ft_strlen(cmd) + 1);
	else if (!ft_strncmp(cmd, "?", ft_strlen(cmd)))
	{
		if (g_global.exit_status > 255)
			g_global.exit_status = g_global.exit_status >> 8;
		return (ft_itoa(g_global.exit_status));
	}
	else
		return (NULL);
	return (ft_strdup(str));
}
