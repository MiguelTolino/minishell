/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:05:47 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/01/15 19:48:35 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ignore_quotes(char *cmd, char type, int *i, int num)
{
	if(cmd[*i] == type && num)
	{
		(*i)++;
		while (cmd[*i] != type)
		{
			(*i)++;
		}
		num--;
	}
}

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
	t_cmd_data *cmd_data;

	i = 0;
	start = 0;
	list = NULL;
	while (shell->cmdline[i])
	{
		cmd_data = (t_cmd_data *)malloc(sizeof(cmd_data));
		if (shell->cmdline[i] == '|')
		{
			cmd_data->cmd = ft_substr(shell->cmdline, start, i - start);
			list = ft_lstnew(cmd_data);
			ft_lstadd_back(&shell->cmdlist, list);
			start = i + 1;
		}
		ignore_quotes(shell->cmdline, '\'', &i, single);
		ignore_quotes(shell->cmdline, '\"', &i, doble);
		i++;
	}
	cmd_data->cmd = ft_substr(shell->cmdline, start, i - start);
	list = ft_lstnew(cmd_data);
	ft_lstadd_back(&shell->cmdlist, list);
}

void	quoting(t_shell *shell)
{
	int n_single;
	int n_doble;

	shell->cmdlist = NULL;
	n_single = count_closed_quotes(shell->cmdline, '\'') / 2;
	n_doble = count_closed_quotes(shell->cmdline, '\"') / 2;
	search_cmdline(shell, n_single, n_doble);
	dividing(shell, n_single, n_doble);
}