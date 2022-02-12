/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:59:30 by rgirondo          #+#    #+#             */
/*   Updated: 2022/02/12 18:32:55 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	expansion(t_token *token)
{
	char **cmd_matrix;
	int j;

	j = 0;
	cmd_matrix = ft_split(token->word, ' ');
	while (cmd_matrix[j])
	{
		if (ft_strchr(cmd_matrix[j], '$'))
			cmd_matrix[j] = expand_str(cmd_matrix[j]);
		j++;
	}
	unsplit(cmd_matrix, token);
}

void	word_expand(t_list *token_list)
{
	t_token *token;
	char **matrix;
	int i;

	i = 0;
	token = ((t_token *)token_list->content);
	expansion(token);
	matrix = ft_split(token->word, ' ');
	if (matrix[0] && matrix[1])
	{
		token->word = matrix[0];
		i++;
		while (matrix[i])
		{
			new_token(token_list);
			token_list = token_list->next;
			token = ((t_token *)token_list->content);
			token->word = matrix[i];
			i++;
		}
		token_list = token_list->next;
	}
	free(matrix[i]);
	free(matrix);
}

void expand_first(void *content)
{
	t_cmd_data	*data;
	t_list		*token_list;
	t_token		*token;

	data = ((t_cmd_data *)content);
	token_list = data->token;
	while (token_list)
	{
		token = ((t_token *)token_list->content);
		if (token->quote == 1)
			remove_quote(token, "\'");
		if (token->quote == 2)
		{
			remove_quote(token, "\"");
			expansion(token);
		}
		if (token->quote == 0 && (token->type == CMD || token->type == ARG))
			word_expand(token_list);
		if (token->type == OPEN_FILE || token->type == EXIT_FILE)
			expansion(token);
		token_list = token_list->next;
	}
}

void token_expansion(t_shell *shell)
{
	ft_lstiter(shell->cmdlist, expand_first);
}