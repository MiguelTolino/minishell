/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:28:38 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/18 15:11:35 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#define SIZE 1024

int	check_limit(int fd, char *limit)
{
	char *buff;
	int	found;
	
	found = 0;
	close(fd);
	fd = open("heredoc.tmp", O_RDONLY);
	buff = calloc(SIZE, sizeof(char));
	read(fd, buff, SIZE);
	if (ft_strnstr(buff, limit, SIZE))
		found = 1;
	free(buff);
	return(found);
}

/*
1. Create a temporal file
2. Use readline to read line by line
3. Save in file string
4. Read the entire file and check if str is in file
5. Delete file

*/

int	limitor_function(char *limit)
{
	int fd;
	int stop;
	char *str;

	stop = 0;
	while (!stop)
	{
		fd = open("heredoc.tmp", O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd < 0)
		{
			throw_error("Could not create temporary file\n");
			return (1);
		}
		signal_handler();
		str = readline("heredoc > ");
		if (!str)
			break;
		ft_putstr_fd(str, fd);
		ft_putchar_fd('\n', fd);
		if (check_limit(fd, limit))
			stop = 1;
		free(str);
	}
	return (0);
}