/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:41:18 by rgirondo          #+#    #+#             */
/*   Updated: 2022/02/15 21:09:59 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char *expand(char *cmd)
{
	char *new_str;
	char *tmp;
	char *tmp2;
	int i;

	i = 0;
	tmp = NULL;
	tmp2 = NULL;
	new_str = ft_strdup("");
	while (cmd[i])
	{
		if (cmd[i] == '$' && i != 0)
		{
			tmp = ft_substr(cmd, 0, i);
			cmd += i;
			i = 0;
			tmp2 = ft_strjoin(new_str, tmp);
			free(new_str);
			new_str = tmp2;
			free(tmp);
		}
		if (cmd[0] == '$')
		{
			cmd += 1;
			while (ft_isalnum(cmd[i]) || cmd[i] == '?')
				i++;
			tmp = ft_substr(cmd, 0, i);
			tmp2 = ft_strdup(getvar(tmp));
			free(tmp);
			cmd += i;
			i = -1;
			tmp = ft_strjoin(new_str, tmp2);
			free(new_str);
			new_str = tmp;
			free(tmp2);
		}
		i++;
	}
	tmp = ft_substr(cmd, 0, i);
	tmp2 = ft_strjoin(new_str, tmp);
	free(new_str);
	new_str = tmp2;
	free(tmp);
	return (new_str);
}

char *expand_2(char *cmd)
{
	char *tmp;
	int n_single;
	int n_double;

	n_single = count_closed_quotes(cmd, '\'');
	n_double = count_closed_quotes(cmd, '\"');
	if (n_double == 2)
	{
		tmp = cmd;
		cmd = ft_strtrim(cmd, "\"");
		free(tmp);
		tmp = expand(cmd);
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
		tmp = expand(cmd);
		free(cmd);
		cmd = tmp;
	}
	return (cmd);
}

char *expand_quoted(char *cmd)
{
	char *new_str;
	char *tmp;
	char *tmp2;
	int i;

	i = 0;
	tmp = NULL;
	tmp2 = NULL;
	new_str = ft_strdup("");
	if (cmd[i] == '\"' || cmd[i] == '\'')
		i++;
	while (cmd[i])
	{
		if (cmd[i] == '\"' || cmd[i] == '\'')
		{
			if (cmd[0] == cmd[i])
				i++;
			tmp = ft_substr(cmd, 0, i);
			tmp = expand_2(tmp);
			cmd += i;
			i = 0;
			tmp2 = ft_strjoin(new_str, tmp);
			free(new_str);
			new_str = tmp2;
			free(tmp);
		}
		i++;
	}
	tmp = ft_substr(cmd, 0, i);
	tmp = expand_2(tmp);
	tmp2 = ft_strjoin(new_str, tmp);
	free(new_str);
	free(tmp);
	new_str = tmp2;
	return (new_str);
}