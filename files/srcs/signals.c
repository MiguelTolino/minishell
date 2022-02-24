/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:22:42 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/24 13:36:25 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	sigint_handler(int sig)
{
	(void)sig;
	if (g_global.whereami == 0)
	{
		g_global.exit_status = 130;
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	if (g_global.whereami == HD)
	{
		g_global.exit_status = 130;
		g_global.signal_status = SIGINT;
		ft_putchar_fd('\n', STDOUT_FILENO);
		//exit(g_global.exit_status);
	}
}

void	signal_handler(void)
{
	signal(SIGINT, &sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}
