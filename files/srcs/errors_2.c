/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:45:39 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/25 00:10:52 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	throw_error(const char *error)
{
	perror(error);
	return (1);
}

int	throw_set_error(const char *error, int error_code)
{
	perror(error);
	g_global.exit_status = error_code;
	return (-1);
}

void	exit_ctrld(char *cmdline)
{
	free(cmdline);
	rl_clear_history();
	printf("exit\n");
	exit_shell();
}
