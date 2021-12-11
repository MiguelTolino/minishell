/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:34:35 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/11 11:45:29 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char ***parsing_pipes(char *cmdline, int n_pipes)
{
	char **split_pipes;
	int i;
	char ***split_cmds;
	
	i = 0;
	split_pipes = ft_split(cmdline, '|');
	split_cmds = (char ***)malloc(sizeof(char **) * n_pipes + 1);
	while (i < n_pipes)
	{
		split_cmds[i] = ft_split(split_pipes[i], ' ');
		i++;
	}
	//split_cmds[i] = '\0';
	return (split_cmds);
}