/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:32:26 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/24 20:10:53 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	valid_op_arg_aux(t_token *token_data)
{
	int		i;
	char	quotes;

	i = 0;
	quotes = 0;
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
			return (throw_set_error(PARSING_ERROR_OP_ARG, 258));
		i++;
	}
	return (0);
}
