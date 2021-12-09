/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:14:58 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/07 19:34:28 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void action(char **cmd, char **envp)
{
	if(!ft_strncmp(cmd[0], "pwd", ft_strlen(cmd[0])))
		printf("%s\n", getenv("PWD"));
	if(!ft_strncmp(cmd[0], "env", ft_strlen(cmd[0])))
		env(envp);
	if(!ft_strncmp(cmd[0], "cd", ft_strlen(cmd[0])))
		change_directory(cmd[1]);
	if(!ft_strncmp(cmd[0], "exit", ft_strlen(cmd[0])))
		exit(EXIT_SUCCESS);
 	if(!ft_strncmp(cmd[0], "echo", ft_strlen(cmd[0])))
		echo(cmd, 'x');
}