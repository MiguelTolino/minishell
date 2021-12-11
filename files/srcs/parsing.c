/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:22:35 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/11 20:38:32 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int parsing(t_shell *shell)
{
	char *cmd;

	cmd = check_cmd(shell->words[0]);
	if (!cmd)
	{
		perror("CMD not found");
		return (1);
	}
	free(shell->words[0]);
	shell->words[0] = ft_strdup(cmd);
	free(cmd);
	return (0);
}