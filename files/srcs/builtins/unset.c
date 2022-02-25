/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:20:57 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/25 11:21:33 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	unset_aux(char *cmd, char **envp)
{
	int		i;
	char	*old_var;

	i = 0;
	old_var = 0;
	while (envp[i] && !ft_strnstr(envp[i], cmd, ft_strlen(cmd)))
		i++;
	if (envp[i])
	{
		old_var = envp[i];
		while (envp[i])
		{
			envp[i] = envp[i + 1];
			i++;
		}
		free(old_var);
		g_global.env_len -= 1;
	}
}

int	unset(char **cmd)
{
	int		j;
	char	**envp;

	j = 0;
	envp = g_global.env;
	while (cmd[j])
	{
		if (cmd[j])
			unset_aux(cmd[j], envp);
		j++;
	}
	if (g_global.env_export)
	{
		dfree(g_global.env_export);
		g_global.env_export = create_env_export();
	}
	return (1);
}
