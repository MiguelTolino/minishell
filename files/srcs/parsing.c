/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:51:44 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/06 01:07:26 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		cmd_size(t_list *token_list)
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
	t_cmd_data *data;
	t_list *token_list;
	t_token *token;
	int i;
	int len;

	i = 0;
	data = ((t_cmd_data *)content);
	token_list = data->token;
	len = cmd_size(token_list);
	data->exec_cmd = (char **)malloc(sizeof(char *) * (len + 1));
	data->exec_cmd[len] = NULL;
	while (token_list)
	{
		token = ((t_token *)token_list->content);
		if (token->type == CMD || token->type == ARG)
			data->exec_cmd[i++] = ft_strdup(token->word);
		token_list = token_list->next;
	}
}

//FIXME: Prepare execution breaks cmds;

void	parsing(t_shell *shell)
{
//	ft_lstiter(shell->cmdlist, print);
	ft_lstiter(shell->cmdlist, prepare_execution);
//	ft_lstiter(shell->cmdlist, print);

}