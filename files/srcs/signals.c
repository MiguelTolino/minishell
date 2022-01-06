/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:22:42 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/01/04 17:50:51 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void sigint_handler(int sig)
{
	rl_replace_line("", 0);
	ft_putstr_fd("\b\b", STDOUT_FILENO);
	ft_putstr_fd("  ", STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	rl_on_new_line();
	rl_redisplay();
}

void signal_handler()
{
	signal(SIGINT, &sigint_handler);
}