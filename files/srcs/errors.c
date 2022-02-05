/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:45:39 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/05 19:50:16 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exit_ctrld(t_shell shell)
{
	free(shell.prompt);
	exit_shell();
}

void	exit_shell()
{
	exit(global.exit_status);
}

void	throw_error(const char *error)
{
	perror(error);
}

void	check_args(int argc)
{
	if (argc != 1)
	{
		throw_error("Numbers of arguments invalid");
		exit(EXIT_FAILURE);
	}
}
