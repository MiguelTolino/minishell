/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:22:42 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/17 12:24:40 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// FIXME: REPLACE_^C

void	sigint_handler(int sig)
{
	if (sig == SIGINT)
	{
/* 		rl_on_new_line();
		rl_replace_line("", 0);
		write(1, "\n", 1);
		rl_redisplay(); */
		rl_on_new_line();
		rl_replace_line("", 0);
		write(1, "\b\b", 2); // move cursor behind of ^C
		write(1, "  ", 2); // remove ^C by printing spaces.
		write(1, "\b\b", 2); // reset cursor pos
	}
}

void	signal_handler(void)
{
	signal(SIGINT, &sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}
