/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:14:58 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/24 17:23:18 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exec_builtins(char **cmd)
{
	int	is_builtin;

	is_builtin = 0;
	if (!ft_strncmp(cmd[0], "pwd", ft_strlen("pwd")))
	{
		builtins_pwd(cmd);
		is_builtin = 1;
	}
	else if (!ft_strncmp(cmd[0], "env", ft_strlen("env")))
	{
		print_env(cmd);
		is_builtin = 1;
	}
	else if (!ft_strncmp(cmd[0], "exit", ft_strlen("exit")))
	{
		exit_cmd(cmd);
		is_builtin = 1;
	}
	else if (!ft_strncmp(cmd[0], "cd", ft_strlen("cd")))
	{
		change_directory(cmd);
		is_builtin = 1;
	}
	else if (!ft_strncmp(cmd[0], "echo", ft_strlen("echo")))
	{
		echo(cmd);
		is_builtin = 1;
	}
	else if (!ft_strncmp(cmd[0], "export", ft_strlen("export")))
	{
		export(cmd);
		is_builtin = 1;
	}
	else if (!ft_strncmp(cmd[0], "unset", ft_strlen("unset")))
	{
		unset(cmd);
		is_builtin = 1;
	}
	return (is_builtin);
}
