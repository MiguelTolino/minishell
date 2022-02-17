/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:56:26 by rgirondo          #+#    #+#             */
/*   Updated: 2022/02/17 19:58:18 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**init_env(char **envp)
{
	char	**new_envp;
	int		i;

	new_envp = (char **)malloc(sizeof(char *) * global.env_len);
	i = 0;
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
	int i;

	i = 0;
	while(envp[i])
		i++;
	global.env_len = (i + 2);
	global.env = init_env(envp);
	global.exit_status = 0;
	global.fd_stdin = dup(STDIN_FILENO);
	global.fd_stdout = dup(STDOUT_FILENO);
	(void)argv;
}
