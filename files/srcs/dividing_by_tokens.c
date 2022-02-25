/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dividing_by_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:14:24 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/25 11:19:55 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#define I 0
#define START 1
#define OLD_TYPE 2

int	ignore_chars(int *i, int *single, int *doble, char *cmd)
{
	int	quote;

	while (cmd[*i] != ' ' && cmd[*i])
	{
		quote = ignore_quotes(cmd, '\'', i, single);
		if (!quote)
			quote = ignore_quotes(cmd, '\"', i, doble);
		else
			ignore_quotes(cmd, '\"', i, doble);
		if (!cmd[*i])
			break ;
		(*i)++;
	}
	return (quote);
}

void	save_token(char *cmd, t_list **token_list, int *single, int *doble)
{
	t_list	*list;
	int		var[3];
	t_token	*token;
	int		quote;

	list = NULL;
	var[I] = 0;
	var[START] = 0;
	var[OLD_TYPE] = -1;
	while (cmd[var[I]])
	{
		ignore_spaces(cmd, &var[I]);
		if (!cmd[var[I]])
			break ;
		var[START] = var[I];
		quote = ignore_chars(&var[I], single, doble, cmd);
		token = (t_token *)malloc(sizeof(t_token));
		token->word = ft_substr(cmd, var[START], var[I] - var[START]);
		token->type = select_type(token, var[OLD_TYPE]);
		token->quote = quote;
		var[OLD_TYPE] = token->type;
		list = ft_lstnew(token);
		ft_lstadd_back(token_list, list);
	}
}

void	dividing_by_token(t_shell *shell, int *single, int *doble)
{
	t_list		*cmdlist;
	t_cmd_data	*data;

	cmdlist = shell->cmdlist;
	while (cmdlist)
	{
		data = ((t_cmd_data *)cmdlist->content);
		data->token = NULL;
		data->exec_cmd = NULL;
		save_token(data->cmd, &data->token, single, doble);
		cmdlist = cmdlist->next;
	}
}
