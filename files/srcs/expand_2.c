/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:41:18 by rgirondo          #+#    #+#             */
/*   Updated: 2022/02/25 04:16:46 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	expand_aux_2(char *cmd, char *quotes, int *i)
{
	int	j;

	j = *i;
	if (cmd[j] == '\"' || cmd[j] == '\'')
		*quotes = cmd[j++];
	else
		*quotes = 0;
	*i = j;
}

char	*expand_dollar(char *cmd)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = ft_strdup("");
	while (cmd[i])
	{
		if (cmd[i] == '$' && i != 0)
		{
			join_expand_1(&new_str, &cmd, i, 2);
			cmd += i;
			i = 0;
		}
		if (cmd[0] == '$' && cmd[1] != ' ' && cmd[1] != '\0')
		{
			cmd += 1;
			while (ft_isalnum(cmd[i]) || cmd[i] == '?')
				i++;
			join_expand_2(&new_str, &cmd, i);
			cmd += i--;
		}
		i++;
	}
	join_expand_1(&new_str, &cmd, i, 2);
	return (new_str);
}

char	*expand_ident_2(char *cmd, char quotes)
{
	char	*tmp;

	if (quotes == '\"')
	{
		tmp = cmd;
		cmd = ft_strtrim(cmd, "\"");
		free(tmp);
		tmp = expand_dollar(cmd);
		free(cmd);
		cmd = tmp;
	}
	if (quotes == '\'')
	{
		tmp = cmd;
		cmd = ft_strtrim(cmd, "\'");
		free(tmp);
	}
	else
	{
		tmp = expand_dollar(cmd);
		free(cmd);
		cmd = tmp;
	}
	return (cmd);
}

char	*expand(char *cmd)
{
	char	*new_str;
	int		i;
	char	quotes;

	i = 0;
	new_str = ft_strdup("");
	expand_aux_2(cmd, &quotes, &i);
	while (cmd[i])
	{
		if (cmd[i] == '\"' || cmd[i] == '\'')
		{
			if (cmd[i++] == quotes)
				quotes = 0;
			else if (quotes != 0)
				continue ;
			else
				quotes = cmd[--i];
			join_expand_1(&new_str, &cmd, i, 1);
			cmd += i;
			i = 0;
		}
		i++;
	}
	join_expand_1(&new_str, &cmd, i, 1);
	return (new_str);
}
