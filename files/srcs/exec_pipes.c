/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:57:35 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/01/25 18:22:15 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	loop_pipe(t_list *cmdlist)
{
	int	p[2];
	pid_t pid;
	int	fd_in;
	char **cmd;

	fd_in = 0;
	while (cmdlist)
	{
		cmd = ((t_cmd_data *)cmdlist->content)->exec_cmd;
		if (pipe(p) < 0)
			throw_error("Pipe Error:");
		if ((pid = fork()) < 0)
			throw_error("Fork Error:");
		else if (!pid)
		{
			dup2(fd_in, STDIN_FILENO); //change the input according to the old one
			if (cmdlist->next != NULL)
				dup2(p[WRITE_END], STDOUT_FILENO);
			close(p[READ_END]);
			execve(cmd[0], cmd, global.env);
			throw_error("Execution Error:");
		}
		else
		{
			wait(&global.exit_status);
			close(p[WRITE_END]);
			fd_in = p[READ_END]; //save the input for the next command
			cmdlist = cmdlist->next;
		}
	}
}
