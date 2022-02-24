/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:19:52 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/24 23:54:14 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	export_aux(char *cmd)
{
	char	*new_var;
	char	*var_name;

	var_name = get_name(cmd);
	new_var = getvar(var_name);
	if (ft_strchr(cmd, '=') && !new_var)
		add_new(cmd);
	else if (ft_strchr(cmd, '=') && new_var)
		change_val(var_name, cmd);
	if (var_name)
		free(var_name);
	if (new_var)
		free(new_var);
}

void	print_export_env(void)
{
	int	i;

	i = 0;
	while (g_global.env_export[i])
		printf("%s\n", g_global.env_export[i++]);
}

char	*get_name(char *cmd)
{
	int		i;
	char	*str;

	i = 0;
	if (!cmd)
		return (NULL);
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

int	export(char **cmd)
{
	int	i;

	i = 1;
	if (len_array(cmd) == 1)
		print_export_env();
	while (cmd[i])
	{
		if (cmd[i])
			export_aux(cmd[i]);
		i++;
	}
	if (g_global.env_export)
	{
		dfree(g_global.env_export);
		g_global.env_export = create_env_export();
	}
	return (1);
}
