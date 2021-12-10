/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:22:35 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/10 19:18:20 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char **parsing(char *cmdline, char **envp)
{
	char **cmds;

	cmds = ft_split(cmdline, ' ');
	cmds[0] = add_path(cmds[0], envp);
	return(cmds);
}