/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:14:58 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/10 18:33:00 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int action(char **cmd, char **envp)
{
	if (!ft_strncmp(cmd[0], "pwd", ft_strlen(cmd[0])))
	{
		printf("%s\n", getenv("PWD"));
		return (1);
	}
	if (!ft_strncmp(cmd[0], "env", ft_strlen(cmd[0])))
	{
		env(envp);
		return (1);
	}
	if (!ft_strncmp(cmd[0], "cd", ft_strlen(cmd[0])))
	{
		change_directory(cmd[1]);
		return (1);
	}
	if (!ft_strncmp(cmd[0], "exit", ft_strlen(cmd[0])))
	{
		exit(EXIT_SUCCESS);
	}
	if (!ft_strncmp(cmd[0], "echo", ft_strlen(cmd[0])))
	{
		echo(cmd, 'x');
		return (1);
	}
	return (0);
}