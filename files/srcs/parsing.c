/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:22:35 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/11 11:46:11 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char **parsing(char *cmdline, char **envp)
{
	char **cmds;

	cmds = ft_split(cmdline, ' ');
	cmds[0] = check_cmd(cmds[0]);
	return(cmds);
}