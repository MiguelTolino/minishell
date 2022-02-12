/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:41:28 by rgirondo          #+#    #+#             */
/*   Updated: 2022/02/12 16:54:26 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void free_matrix(char **mtx)
{
	int i;

	i = 0;
	while (mtx[i])
	{
		free(mtx[i]);
		i++;
	}
	free(mtx);
}

void	remove_quote(t_token *token, char *set)
{
	char *tmp;

	tmp = ft_strtrim(token->word, set);
	free(token->word);
	token->word = tmp;
}

void	new_token(t_list *token_list)
{
	t_list	*new;
	t_token *token;

	token = (t_token *)malloc(sizeof(t_token));
	token->word = NULL;
	token->type = ARG;
	token->quote = 0;
	new = (t_list *)malloc(sizeof(t_list));
	new->content = token;
	new->next = token_list->next;
	token_list->next = new;
}