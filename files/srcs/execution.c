/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:08:02 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/01/19 11:54:38 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int exec(char **cmds)
{
	int pid;

	pid = fork();
	if (!pid)
	{
		execve(cmds[0], cmds, global.env);
		perror("Execution error");
	}
	else if (pid)
		wait(&global.exit_status);
	else
		perror("Fork error\n");
	return (0);
}

int execution(t_shell *shell)
{
	t_cmd_data *data;
	t_list *list;

	list = shell->cmdlist;
	if (ft_lstsize(list) > 1)
	{
		//exec_pipes()
	}
	else
	{
		data = (t_cmd_data *)list->content;
		if (!exec_builtins(data->exec_cmd))
		{
			data->exec_cmd[0] = check_cmd(data->exec_cmd[0]);
			exec(data->exec_cmd);
		}
	}
	return (global.exit_status);
}