/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:51:44 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/08 23:02:56 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	cmd_size(t_list *token_list)
{
	int len;
	t_token *token;

	len = 0;
	while (token_list)
	{
		token = ((t_token *)token_list->content);
		if (token->type == CMD || token->type == ARG)
			len++;
		token_list = token_list->next;
	}
	return (len);
}

void	prepare_execution(void	*content)
{
	t_cmd_data	*data;
	t_list		*token_list;
	t_token		*token;
	t_list		*list;
	int i;
	int len;

	i = 0;
	data = ((t_cmd_data *)content);
	token_list = data->token;
	list = data->token;
	//len = cmd_size(token_list);
	len = 50;
	data->exec_cmd = (char **)malloc(sizeof(char *) * (len + 1));
	data->exec_cmd[len] = NULL;
	printf("222:%s\n", data->cmd);
	while (list)
	{
		token = ((t_token *)list->content);
		if (token->type == CMD || token->type == ARG)
			data->exec_cmd[i] = ft_strdup(token->word);
			printf("222:%s\n", data->exec_cmd[i]);
		i++;
		list = list->next;
	}
}

//FIXME: Prepare execution breaks cmds;
//HACERLO ITERANDO

void	parsing(t_shell *shell)
{
	ft_lstiter(shell->cmdlist, print);
	//ft_lstiter(shell->cmdlist, prepare_execution);
	ft_lstiter(shell->cmdlist, print);
}