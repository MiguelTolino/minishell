/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:08:02 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/21 15:47:13 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//FIXME: EXEC WITH PIPE
//FIXME: Me crea varios procesos y no se cierra
//FIXME: Aprender a usar kill para eliminiar procesos abiertos

void exec_pipe(t_list *cmdlist)
{
	int p[2];
	pid_t pid;
	int fd_in;
	char **cmd;

	fd_in = STDIN_FILENO;
	cmd = NULL;
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
			check_path(&cmd[0]);
			execve(cmd[0], cmd, global.env);
			throw_error("Execution Error:");
		}
		else
		{
			wait(&global.exit_status);
			wait(NULL);
			close(p[WRITE_END]);
			fd_in = p[READ_END]; //save the input for the next command
			cmdlist = cmdlist->next;
		}
	}
}

int exec_simple(char **cmds)
{
	pid_t pid;

	pid = fork();
	if (!pid)
	{
		execve(cmds[0], cmds, global.env);
		perror("Execution error");
		exit(global.exit_status);
	}
	else if (pid)
		wait(&global.exit_status);
	else
		perror("Fork error\n");
	wait(NULL);
	return (0);
}

int execution(t_shell *shell)
{
	t_cmd_data *data;

	data = (t_cmd_data *)shell->cmdlist->content;
/* 	if (ft_lstsize(shell->cmdlist) > 1)
		exec_pipe(shell->cmdlist);
	else */
	{
		if (!exec_builtins(data->exec_cmd))
		{
			check_path(&(data->exec_cmd[0]));
			exec_simple(data->exec_cmd);
		}
	}
	return (global.exit_status);
}