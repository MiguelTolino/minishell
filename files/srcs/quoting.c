/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:05:47 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/21 18:07:48 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


int	ignore_quotes(char *cmd, char type, int *i, int *num)
{
	int quote;

	quote = NONE;
	if(cmd[*i] == type && *num)
	{
		(*i)++;
		while (cmd[*i] != type && cmd[*i])
		{
			(*i)++;
		}
		(*num)--;
		if (type == '\'')
			quote = SINGLE;
		else
			quote = DOUBLE;
	}
	return (quote);
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

void search_cmdline(t_shell *shell, int *single, int *doble)
{
	int i;
	int start;
	t_list *list;
	t_cmd_data *cmd_data;

	i = 0;
	start = 0;
	list = NULL;
	while (i <= (int)ft_strlen(shell->cmdline))
	{
		if (shell->cmdline[i] == '|' || shell->cmdline[i] == '\0')
		{
			cmd_data = (t_cmd_data *)malloc(sizeof(t_cmd_data));
			cmd_data->cmd = ft_substr(shell->cmdline, start, i - start);
			list = ft_lstnew(cmd_data);
			ft_lstadd_back(&shell->cmdlist, list);
			if (shell->cmdline[i] == '\0')
				break;
			start = i + 1;
		}
		ignore_quotes(shell->cmdline, '\'', &i, single);
		ignore_quotes(shell->cmdline, '\"', &i, doble);
		i++;
	}
}

int	quoting(t_shell *shell)
{
	int n_single;
	int n_doble;

	shell->cmdlist = NULL;
	n_single = count_closed_quotes(shell->cmdline, '\'') / 2;
	n_doble = count_closed_quotes(shell->cmdline, '\"') / 2;
	search_cmdline(shell, &n_single, &n_doble);
	n_single = count_closed_quotes(shell->cmdline, '\'') / 2;
	n_doble = count_closed_quotes(shell->cmdline, '\"') / 2;
	dividing_by_token(shell, &n_single, &n_doble);
  	if (validate_token(shell->cmdlist))
		return (1);
	return (0);
}