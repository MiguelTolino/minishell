/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:16:41 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/19 13:25:54 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//FIXME: Segfault

/*	$> echo 'ls -l $PATH | pwd $USER' | grep a
*/

void search_quotes(t_shell *shell)
{
	int i;
	int j;
	int len;
	int start;
	int end;
	char *cmd;

	i = 0;
	while (shell->cmdline[i])
	{
		if (shell->cmdline[i] == '\'')
		{
			start = i + 1;
			j = i + 1;
			while (shell->cmdline[j] != '\'')
			{
				j++;
			}
			end = j - 1;
			cmd = ft_substr(shell->cmdline, start, end);
			break;
		}
		i++;
	}
	printf("Quote: %s\n", cmd);
}

void	lexer(t_shell *shell)
{
	search_quotes(shell);
}