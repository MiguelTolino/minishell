/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:28:38 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/08 20:47:49 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exists_limitor(int fd, char *limit)
{
	char *str;
	char buff[1028];
	fd = 5;
	
	str = NULL;
	while (read(STDIN_FILENO, buff, ft_strlen(limit)) > 0)
	{
		if (ft_strncmp(buff, limit, ft_strlen(buff)))
		{
			return (1);
		}
	}
	return (0);
}

int	limitor_function(char *limit)
{
	int fd;
	char buff[16];
	int bytes;

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