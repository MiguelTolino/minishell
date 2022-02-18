/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:14:58 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/18 19:36:44 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int exec_builtins(char **cmd)
{
	int is_builtin;

	is_builtin = 0;
	if (cmd[0][0] == '\0')
		return(is_builtin);
	else if (!ft_strncmp(cmd[0], "pwd", ft_strlen(cmd[0])))
	{
		printf("%s\n", getvar("PWD"));
		is_builtin = 1;
	}
	else if (!ft_strncmp(cmd[0], "env", ft_strlen(cmd[0])))
	{
		//print_env();
		is_builtin = 1;
	}
	else if (!ft_strncmp(cmd[0], "exit", ft_strlen(cmd[0])))
	{
		exit_cmd(cmd);
		is_builtin = 1;
	}
	else if (!ft_strncmp(cmd[0], "cd", ft_strlen(cmd[0])))
	{
		//change_directory(cmd[1]);
		is_builtin = 1;
	}
	else if (!ft_strncmp(cmd[0], "echo", ft_strlen(cmd[0])))
	{
		echo(cmd);
		is_builtin = 1;
	}
	else if (!ft_strncmp(cmd[0], "export", ft_strlen(cmd[0])))
	{
		export(cmd);
		is_builtin = 1;
	}
	else if (!ft_strncmp(cmd[0], "unset", ft_strlen(cmd[0])))
	{
		unset(cmd);
		is_builtin = 1;
	}
	return (is_builtin);
}
