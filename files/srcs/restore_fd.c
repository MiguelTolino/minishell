/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:42:21 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/01/25 10:46:47 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	restore_fd(void)
{
	int fd;
	char buff[8];

	if (!read(STDIN_FILENO, buff, 8))
	{
		exit_shell();
	}
	return (0);
}