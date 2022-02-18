/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:28:38 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/18 18:31:04 by mmateo-t         ###   ########.fr       */
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

int	limitor_function(t_token *limit)
{
	int fd;
	int stop;
	char *str;
<<<<<<< HEAD
	char buff[1028];
	fd = 5;
	
	(void)str;
	(void)fd;
	while (read(STDIN_FILENO, buff, ft_strlen(limit)) > 0)
=======

	stop = 0;
	fd = open("heredoc.tmp", O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		throw_error("Could not create temporary file\n");
		return (1);
	}
	while (!stop)
>>>>>>> 6df98fb76b4d94e38136069c16fcfc159035287d
	{
		signal(SIGINT, &sigint_heredoc); //FIXME: Solucionar ^C
		str = readline("heredoc > ");
		if(!str)
			continue ;
		//if(!limit->quote)
			//TODO: EXPAND
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
	return (0);
}
<<<<<<< HEAD

int	limitor_function(char *limit)
{
	int fd;
	char buff[16];
	int bytes;

	(void)bytes;
	fd = open("LIMITOR.txt", O_RDWR);
	if (fd < 0)
		throw_error("Error in fd");
	while (!exists_limitor(fd, limit))
	{
		bytes = read(STDIN_FILENO, buff, 16);
		ft_putstr_fd(buff, fd);
	}
	return (fd);
}
=======
>>>>>>> 6df98fb76b4d94e38136069c16fcfc159035287d
