/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:41:18 by rgirondo          #+#    #+#             */
/*   Updated: 2022/02/23 19:17:30 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
		if (cmd[0] == '$')
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

char	*expand_ident_2(char *cmd, int n_single, int n_double)
{
	char	*tmp;

	if (n_double == 2)
	{
		tmp = cmd;
		cmd = ft_strtrim(cmd, "\"");
		free(tmp);
		tmp = expand_dollar(cmd);
		free(cmd);
		cmd = tmp;
	}
	if (n_single == 2)
	{
		tmp = cmd;
		cmd = ft_strtrim(cmd, "\'");
		free(tmp);
	}
	if (n_single == 0 && n_double == 0)
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

	i = 0;
	new_str = ft_strdup("");
	if (cmd[i] == '\"' || cmd[i] == '\'')
		i++;
	while (cmd[i])
	{
		if (cmd[i] == '\"' || cmd[i] == '\'')
		{
			if (cmd[0] == cmd[i])
				i++;
			join_expand_1(&new_str, &cmd, i, 1);
			cmd += i;
			i = 0;
		}
		i++;
	}
	join_expand_1(&new_str, &cmd, i, 1);
	return (new_str);
}
