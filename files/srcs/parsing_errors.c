/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:32:26 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/24 17:46:15 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		valid_operator_arg(t_list *token)
{
	int i;
	char quotes;
	t_token *token_data;

	i = 0;
	quotes = 0;
	if (!token || !token->content)
		return (0);
	token_data = token->content;
	while (token)
	{
		token_data = token->content;
		if (token_data->type >= 2 && token_data->type <= 5)
		{
			token = token->next;
			if (token)
				token_data = token->content;
			else
				return (throw_set_error("minishell: error near operator argument", 258));
			while (token_data->word[i])
			{
				if (token_data->word[i] == '\"' || token_data->word[i] == '\'')
				{
					quotes = token_data->word[i];
					i++;
					while (token_data->word[i] != quotes)
						i++;
				}
				if (ft_strchr("<>", token_data->word[i]))
					return (throw_set_error("minishell: error near operator argument", 258));
				i++;
			}
		}
		token = token->next;
	}
	return (0);
}

int		validate_operators(t_list *token)
{
	int i;
	t_token *token_data;

	i = 0;
	if (!token)
		return (0);
	token_data = token->content;
	while (token)
	{
		token_data = token->content;
		if (token_data->word[i] == '>' || token_data->word[i] == '<')
		{
			if (token_data->word[i] == token_data->word[i + 1])
				i++;
			if (token_data->word[i + 1])
				return (throw_set_error("minishell: error near operator argument", 258));
		}
		token = token->next;
	}
	return (0);
}

//FIXME: Peta en pipes

int		validate_pipes(t_list *cmd_list)
{
	int i;
	t_cmd_data *cmd_data;

	i = 0;
	cmd_data = cmd_list->content;
	while (cmd_list)
	{
		cmd_data = cmd_list->content;
		if (validate_operators(cmd_data->token))
			return (-1);
		if (valid_operator_arg(cmd_data->token))
			return (-1);
		while (cmd_data->cmd[i] == ' ')
			i++;	
		if (!cmd_data->cmd[i])
			return (throw_set_error("minishell: error near operator argument", 258));
		cmd_list = cmd_list->next;
	}
	return (0);
}

int		parsing_errors(t_list *cmdlist)
{
	if (validate_pipes(cmdlist))
		return (0);
	return(1);
}