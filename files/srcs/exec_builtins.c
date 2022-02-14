/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:14:58 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/14 16:22:51 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int exec_builtins(char **cmd)
{
	if (!ft_strncmp(cmd[0], "pwd", ft_strlen(cmd[0])))
		printf("%s\n", getvar("PWD"));
	if (!ft_strncmp(cmd[0], "env", ft_strlen(cmd[0])))
		print_env();
	if (!ft_strncmp(cmd[0], "exit", ft_strlen(cmd[0])))
		exit(EXIT_SUCCESS);
	if (!ft_strncmp(cmd[0], "cd", ft_strlen(cmd[0])))
		change_directory(cmd);
	if (!ft_strncmp(cmd[0], "echo", ft_strlen(cmd[0])))
		echo(cmd);
	if (!ft_strncmp(cmd[0], "export", ft_strlen(cmd[0])))
		export(cmd);
	if (!ft_strncmp(cmd[0], "unset", ft_strlen(cmd[0])))
		unset(cmd);
	return (0);
}
