/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:08:02 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/10 18:40:20 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int exec(char **cmds, char **envp)
{
	int pid;

	pid = fork();
	if (!pid)
	{
		if (execve(cmds[0], cmds, envp) < 0)
			throw_error("Execution Failed");
	}
	else if(pid)
	{
		wait(NULL);
	}
	else
		throw_error("Fork error\n");
	return(0);
}