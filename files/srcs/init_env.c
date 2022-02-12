/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:56:26 by rgirondo          #+#    #+#             */
/*   Updated: 2022/02/08 13:05:40 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**init_env(char **envp)
{
	char	**new_envp;
	int		i;

	i = 0;
	new_envp = (char **)malloc(sizeof(char *) * 2000); //FIXME: Mejor contar cuantos punteros tiene env y despues ir liberando
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
	global.fd_stdin = dup(STDIN_FILENO);
	global.fd_stdout = dup(STDOUT_FILENO);
	(void)argv;
}
