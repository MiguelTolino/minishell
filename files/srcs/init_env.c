/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:56:26 by rgirondo          #+#    #+#             */
/*   Updated: 2022/02/04 19:04:26 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**init_env(char **envp)
{
    char **new_envp;
	int i;

	i = 0;
	new_envp = (char **)malloc(sizeof(char *) * 2000);
	while (envp[i])
	{
		new_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	new_envp[i] = NULL;
	return (new_envp);
}

void	init_global(char **envp, char **argv)
{
	global.env = init_env(envp);
	global.exit_status = 0;
	(void)argv;
}