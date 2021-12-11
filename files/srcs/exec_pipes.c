/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:57:35 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/11 22:02:46 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	child_process(int *fd, char **cmds, char **envp)
{
	close(fd[READ_END]);
	if (dup2(fd[WRITE_END], STDOUT_FILENO) < 0)
		throw_error("Error:");
	close(fd[WRITE_END]);
	if (execve(cmds[0], cmds, envp) < 0)
		throw_error("Execution Failed");
}

void	parent_process(int *fd, char **cmds, char **envp)
{
	int pid;
	
	close(fd[WRITE_END]);
	pid = fork();
	if (!pid)
	{
		if (dup2(fd[READ_END], STDIN_FILENO) < 0)
			throw_error("Error:");
		if (execve(cmds[0], cmds, envp) < 0)
			throw_error("Execution Failed");
	}
	else if (pid > 0)
	{
		close(fd[READ_END]);
	}
	else
		throw_error("Error en hijo 2");
}

 void	exec_pipes(char **cmds[MAXLIST], int n_pipes, char **envp)
{
	int				fd[2];
	pid_t			pid;
	int				status;
	
	if (pipe(fd) < 0)
		throw_error("Pipe Error");
	pid = fork();
	if (!pid)
		child_process(fd, cmds[0], envp);
	else if (pid > 0)
		parent_process(fd, cmds[1], envp);
	else
		throw_error("Fork Error");
	wait(&status);
	wait(&status);
}