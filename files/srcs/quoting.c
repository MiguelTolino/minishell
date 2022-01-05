/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:05:47 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/01/05 18:43:28 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	count_closed_quotes(char *cmdline, char quote)
{
	int num;
	char *aux;

	num = 0;
	aux = ft_strchr(cmdline, quote);
	while (aux)
	{
		aux++;
		num++;
		aux = ft_strchr(aux, quote);
	}
	return (num);
}

void search_cmdline(t_shell *shell, int single, int doble)
{
	int i;
	int start;
	t_list *list;
	char *word;

	i = 0;
	start = 0;
	while (shell->cmdline[i])
	{
		if (shell->cmdline[i] == '|')
		{
			word = ft_substr(shell->cmdline, start, i - start);
			list = ft_lstnew(word);
			ft_lstadd_back(&shell->cmd_list, list);
			start = i + 1;
		}
		if(shell->cmdline[i] == '\'' && single)
		{
			i++;
			while (shell->cmdline[i] != '\'')
			{
				i++;
			}
			single--;
		}
		if ( shell->cmdline[i] == '\"' && doble)
		{
			i++;
			while (shell->cmdline[i] != '\"')
			{
				i++;
			}
			doble--;
		}
		i++;
	}
	word = ft_substr(shell->cmdline, start, i - start);
	list = ft_lstnew(word);
	ft_lstadd_back(&shell->cmd_list, list);
}

void	quoting(t_shell *shell)
{
	int n_single;
	int n_doble;
	
	shell->cmd_list = NULL;
	n_single = count_closed_quotes(shell->cmdline, '\'') / 2;
	n_doble = count_closed_quotes(shell->cmdline, '\"') / 2;
	search_cmdline(shell, n_single, n_doble);
}