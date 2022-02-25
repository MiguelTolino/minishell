/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 03:06:11 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/25 03:15:54 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

unsigned int	choose_type(int old_type)
{
	int	type;

	type = 0;
	if (old_type == FILE_IN)
		return (OPEN_FILE);
	if (old_type == FILE_OUT)
		return (EXIT_FILE);
	if (old_type == HERE_DOC)
		return (LIMITOR);
	if (old_type == FILE_OUT_SUR)
		return (EXIT_FILE_RET);
	if (old_type < 0)
		return (CMD);
	if (old_type <= 1)
		return (ARG);
	return (type);
}

unsigned int	select_type(t_token *token, int old_type)
{
	size_t			len;

	len = ft_strlen(token->word);
	if (!ft_strncmp(token->word, "<", len))
		return (FILE_IN);
	if (!ft_strncmp(token->word, "<<", len))
		return (HERE_DOC);
	if (!ft_strncmp(token->word, ">", len))
		return (FILE_OUT);
	if (!ft_strncmp(token->word, ">>", len))
		return (FILE_OUT_SUR);
	return (choose_type(old_type));
}
