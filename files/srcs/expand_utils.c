/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:41:28 by rgirondo          #+#    #+#             */
/*   Updated: 2022/02/23 19:36:16 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_matrix(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
	{
		free(mtx[i]);
		i++;
	}
	free(mtx);
}

void	new_token(t_list *token_list)
{
	t_list	*new;
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	token->word = NULL;
	token->type = ARG;
	token->quote = 0;
	new = (t_list *)malloc(sizeof(t_list));
	new->content = token;
	new->next = token_list->next;
	token_list->next = new;
}

void	join_expand_1(char **new_str, char **cmd, int i, int type)
{
	char	*tmp;
	char	*tmp2;
	int		n_single;
	int		n_double;

	n_double = 0;
	n_single = 0;
	tmp = NULL;
	tmp2 = NULL;
	tmp = ft_substr(cmd[0], 0, i);
	if (type == 1)
	{
		n_double = count_closed_quotes(tmp, '\"');
		n_single = count_closed_quotes(tmp, '\'');
		tmp = expand_ident_2(tmp, n_single, n_double);
	}
	tmp2 = ft_strjoin(new_str[0], tmp);
	free(new_str[0]);
	free(tmp);
	new_str[0] = tmp2;
}

void	join_expand_2(char **new_str, char **cmd, int i)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	tmp = ft_substr(cmd[0], 0, i);
	tmp2 = getvar(tmp);
	free(tmp);
	if (tmp2)
	{
		tmp = ft_strjoin(new_str[0], tmp2);
		free(new_str[0]);
		free(tmp2);
		new_str[0] = tmp;
	}
}
