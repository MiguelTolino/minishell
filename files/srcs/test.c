/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:02:48 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/11 23:34:52 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void test(t_shell shell)
{
	int i;
	int j;

	i = 0;
	j = 0;
	printf("CMDLINE:%s\n", shell.cmdline);
	printf("NUM_PIPES:%i\n", shell.n_pipes);
	while (*shell.words)
	{
		printf("CMD[%i]:%s\n", i++, *shell.words);
		shell.words++;
	}
	i = 0;
	if (shell.n_pipes)
	{
		while (i <= shell.n_pipes)
		{
			printf("CMD[%i][0]:(%s)\n", i, shell.cmds_pipe[i][0]);
			i++;
		}
	}
}