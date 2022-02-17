/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:28:38 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/17 18:16:50 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_limit(int fd, char *limit)
{
	char buff[1024];

	while (read(fd, &buff, 1024))
	{
		if (ft_strnstr(buff, limit, 1024))
			return (1);
	}
	return (0);
}

/*
1. Create a temporal file
2. Use readline to read line by line
3. Save in file string
4. check if str is in file
5. Delete file

*/

int	limitor_function(char *limit)
{
	int fd;
	int stop;
	char *str;

	stop = 0;
	fd = open("heredoc.tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		throw_error("Could not create temporary file\n");
		return (1);
	}
	while (!stop)
	{
		str = readline("heredoc > ");
		write(fd, str, ft_strlen(str));
		if (check_limit(fd, limit))
			stop = 1;
	}
	unlink("heredoc.tmp");
	return (0);
}