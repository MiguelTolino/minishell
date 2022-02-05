/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 00:25:26 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/05 00:30:10 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//Expand word without quotes
//Example: $> $LSH -l -> ls -h -l

char *expand_word(char *cmd)
{
	char *aux;
	char *var_name;
	char *new_cmd;
	char *expand_var;
	int i;
	int len;
	int start;
	int simple;
	int doble;
	i = 0;
	len = 0;
	start = 0;
	simple = count_closed_quotes(cmd, '\'');
	doble = count_closed_quotes(cmd, '\"');
	aux = NULL;
	new_cmd = NULL;
	var_name = NULL;

	while (cmd[i])
	{
		ignore_quotes(cmd, '\'', &i, simple);
		ignore_quotes(cmd, '\"', &i, doble);
		if (cmd[i] == '$')
		{
			aux = ft_substr(cmd, start, i);
			i++;
			while (ft_isalnum(cmd[i + len]) || cmd[i + len] == '_')
				len++;
			var_name = ft_substr(cmd, i, len);
			if ((expand_var = getenv(var_name)) == NULL)
				expand_var = ft_strdup(" ");
			i += len;
			start = i;
			new_cmd = ft_strjoin(aux, expand_var);
		}
		i++;
	}
	aux = ft_substr(cmd, start, i);
	printf("%s\n", new_cmd);
	return (new_cmd);
}