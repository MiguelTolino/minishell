/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:22:42 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/17 13:19:42 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void sigint_handler(int sig)
{
	//printf("SIGNAL: %i", sig);
	rl_replace_line("", 1);
	rl_redisplay();
	ft_putchar_fd('\n', STDOUT_FILENO);
	//rl_replace_line("", MAXCOM);
	rl_on_new_line();
	rl_redisplay();
}

void signal_handler()
{
	signal(SIGINT, &sigint_handler);
}