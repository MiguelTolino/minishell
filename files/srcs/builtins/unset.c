/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:20:57 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/23 19:48:31 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	unset(char **cmd)
{
	int		i;
	int		j;
	char	*old_var;
	char	**envp;

	j = 0;
	envp = g_global.env;
	while (cmd[j])
	{
		if (cmd[j])
		{
			i = 0;
			while (envp[i] && !ft_strnstr(envp[i], cmd[j], ft_strlen(cmd[j])))
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
		j++;
	}
}
