/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:42:24 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/11 23:38:47 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// (   ls  )
// 1.Calcular len

char *trim(char *str)
{
	char *aux;
	
	aux = ft_strtrim(str, " ");
	free(str);
	return (aux);
}

int	search_pipes(char *cmdline)
{
	int		n_pipes;
	char	*str;

	n_pipes = 0;
	str = ft_strchr(cmdline, '|');
	while (str != NULL)
	{
		str++;
		n_pipes++;
		str = ft_strchr(str, '|');
	}
	return (n_pipes);
}

int	quoting(t_shell *shell)
{
	int		i;
	char	*ptr;

	i = 0;
	shell->n_pipes = search_pipes(shell->cmdline);
	if (shell->n_pipes)
	{
		shell->words = ft_split(shell->cmdline, '|');
		while (i <= shell->n_pipes && i < MAXLIST)
		{
			shell->words[i] = trim(shell->words[i]);
			shell->cmds_pipe[i] = ft_split(shell->words[i], ' ');
			i++;
		}
	}
	else
		shell->words = ft_split(shell->cmdline, ' ');
	return (0);
}
