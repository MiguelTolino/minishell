/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:22:35 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/11 22:15:55 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int parsing_pipes(t_shell *shell)
{
	int i;
	char *cmd;

	i = 0;
	while (i <= shell->n_pipes)
	{
		cmd = check_cmd(shell->cmds_pipe[i][0]);
		free(shell->cmds_pipe[i][0]);
		shell->cmds_pipe[i][0] = ft_strdup(cmd);
		free(cmd);
		i++;
	}
	return (0);
}

int parsing(t_shell *shell)
{
	char *cmd;

	if (!shell->n_pipes)
	{
		cmd = check_cmd(shell->words[0]);
		if (!cmd)
		{
			perror("CMD not found");
			return (1);
		}
		free(shell->words[0]);
		shell->words[0] = ft_strdup(cmd);
		free(cmd);
	}
	else
		parsing_pipes(shell);
	return (0);
}