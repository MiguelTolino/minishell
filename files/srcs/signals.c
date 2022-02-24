/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:22:42 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/25 00:45:59 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	nothing(int signal)
{
	(void)signal;
	ft_putchar_fd('\n', STDERR_FILENO);
}

void	ctrl_c(int sig)
{
	(void)sig;
		if (g_global.whereami == MAIN)
			printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		if (g_global.whereami == MAIN)
			rl_redisplay();
}

void	stop_heredoc(int sig)
{
	(void)sig;
	ft_putstr_fd("\n", STDERR_FILENO);
	g_global.exit_status = 130;
	exit(g_global.exit_status);
}

void	signal_handler(void)
{
	signal(SIGINT, &ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}

void	newline(int signal)
{
	(void)signal;
	ft_putstr_fd("\n", STDERR_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_global.exit_status = 130;
}
