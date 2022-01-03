/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:16:41 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/01/03 19:41:58 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//TODO: Study lists and look how to use it

//TODO:
/*	While a quote exists (USING LISTS)
	1º Find quote
	2º Create str = 'quote SPACES' which contains the size of quote1
	3º Use strlcpy or memcpy to copy the string in cmdline 
*/

void replace_quotes(char *shell)
{
	//ft_strnstr(shell->cmdline, quote1, ft_strlen(shell->cmdline));
}

char *new_quote(char *cmdline, char quote, int *index)
{
	int start;
	int j;
	int len;
	int closed;
	char *cmd;
	
	start = *index + 1;
	j = *index + 1;
	cmd = NULL;
	closed = 0;
	while (!closed && cmdline[j])
	{
		j++;
		if (cmdline[j] == quote)
			closed = 1;
	}
	len = j - *index - 1;
	if (closed)
		cmd = ft_substr(cmdline, start, len);
	*index = j;
	return (cmd);
}

void search_quotes(t_shell *shell)
{
	int i;
	char *cmd;

	i = 0;
	cmd = NULL;
	while (shell->cmdline[i])
	{
		if (shell->cmdline[i] == '\'')
		{
			cmd = new_quote(shell->cmdline, '\'', &i);
		}
		if (shell->cmdline[i] == '\"')
		{
			cmd = new_quote(shell->cmdline, '\"', &i);
		}
		i++;
	}
	printf("Quote: %s\n", cmd);
}

void lexer(t_shell *shell)
{
	search_quotes(shell);
	//replace_quotes(shell);
}