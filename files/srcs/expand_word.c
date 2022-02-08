/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 00:25:26 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/08 11:53:58 by mmateo-t         ###   ########.fr       */
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

/*
1. Iterar sobre la lista de tokens
2. If token.quote == NONE || token.quote == DOUBLE
	if NONE -> do something
	if DOUBLE -> do something

*/

char	*expand_var(t_token *token)
{
	int i;
	int start;
	char *prev;
	char *varname;
	char *expand;
	char *aux;
	bool exist;

	i = 0;
	start = 0;
	while (token->word[i])
	{
		if (token->word[i] == '$')
		{
			prev = ft_substr(token->word, start, i - start);
			if (!prev)
				prev = ft_strdup(" ");
			i++;
			start = i;
			while (ft_isalnum(token->word[i]) || token->word[i] == '_')
				i++;
			varname = ft_substr(token->word, start, i - start);
			expand = getenv(varname);
			if (!expand)
			{
				expand = ft_strdup(" ");
			}
			aux = ft_strjoin(prev, expand);
			exist = true;
		}
		i++;
	}
	printf("Token->word:%s\n", token->word);
	return (aux);
}

int	search_dollar(t_token *token)
{
	char *new_word;

	new_word = NULL;
	if (ft_strchr(token->word, '$'))
	{
		new_word = expand_var(token);
		free(token->word);
		token->word = new_word;
	}
	return (0);
}

void	iteration(void *content)
{
	t_list	*token_list;
	t_token *token;

	token_list = ((t_cmd_data *)content)->token;
	while (token_list)
	{
		token = ((t_token *)token_list->content);
		search_dollar(token);
		token_list = token_list->next;
	}
}

int	expand_word2(t_list *cmdlist)
{
	ft_lstiter(cmdlist, iteration);
	return (0);
}