/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 01:42:35 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/25 01:43:48 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	child_process(int fd_in, t_list *cmdlist, char **cmd, int p[2])
{
	g_global.whereami = CHILD;
	signal(SIGQUIT, SIG_DFL);
	dup2(fd_in, STDIN_FILENO);
	if (cmdlist->next != NULL)
		dup2(p[WRITE_END], STDOUT_FILENO);
	close(p[READ_END]);
	if (!exec_builtins(cmd))
	{
		check_path(&cmd[0]);
		execve(cmd[0], cmd, g_global.env);
		throw_error("Execution Error");
		exit(g_global.exit_status);
	}
	exit(g_global.exit_status);
}
