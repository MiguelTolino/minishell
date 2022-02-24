/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:22:42 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/24 23:52:06 by mmateo-t         ###   ########.fr       */
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
	exit(130);
}

void	sigint_handler(int sig)
{
	(void)sig;
/* 	if (g_global.whereami == 0)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		 */ 
		if (g_global.whereami == HD)
		{
			g_global.exit_status = 130;
			g_global.signal_status = SIGINT;
			ft_putchar_fd('\n', STDOUT_FILENO);
			return ;
			//exit(g_global.exit_status);
		}
 		g_global.exit_status = 130;
		if (g_global.whereami == MAIN)
			printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		if (g_global.whereami == MAIN)
			rl_redisplay();
	
}

void	signal_handler(void)
{
	signal(SIGINT, &ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}
