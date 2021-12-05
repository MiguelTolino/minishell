/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:14:58 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/05 20:51:30 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void action(char *cmdline, char **envp)
{
	if(!ft_strncmp(cmdline, "pwd", ft_strlen(cmdline)))
		printf("%s\n", vars.pwd);
	if(!ft_strncmp(cmdline, "env", ft_strlen(cmdline)))
		env(envp);
	if(!ft_strncmp(cmdline, "cd", ft_strlen(cmdline)))
		change_directory(cmdline);	
}