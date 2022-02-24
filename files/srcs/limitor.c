/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:28:38 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/25 00:50:06 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
1. Create a temporal file
2. Use readline to read line by line
3. Save in file
4. if str == limit
5. Delete file

*/

int	limitor_function_ps(t_token *limit)
{
	int		fd;
	int		stop;
	char	*str;
	char	*tmp;
	pid_t	pid;

	stop = 0;
	g_global.whereami = HD;
	fd = open("heredoc.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		throw_error("Could not create temporary file\n");
		return (1);
	}
	pid = fork();
	if (!pid)
	{
		while (!stop)
		{
			signal(SIGINT, &stop_heredoc);
			str = readline("heredoc > ");
			if (!str)
				continue ;
			if (!limit->quote)
			{
				tmp = expand(str);
				free(str);
				str = tmp;
			}
			if (!ft_strnstr(str, limit->word, ft_strlen(limit->word)))
			{
				ft_putstr_fd(str, fd);
				ft_putchar_fd('\n', fd);
			}
			else
			{
				ft_putchar_fd('\n', fd);
				stop = 1;
			}
			free(str);
		}
		exit(g_global.exit_status);
	}
	else if (pid > 0)
	{
		signal(SIGINT, SIG_IGN);
		waitpid(pid, &g_global.exit_status, 0);
		close(fd);
	}
	else
		return (throw_error("Error in fork"));
	return (0);
}
