/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:02:48 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/11 20:31:34 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void test(t_shell shell)
{
	int i;
	
	i = 0;
	printf("CMDLINE: %s\n", shell.cmdline);
	while (*shell.words)
	{
		printf("CMD[%i]: %s\n", i++, *shell.words);
		shell.words++;
	}
}