/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:14:58 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/24 19:11:44 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exec_builtins(char **cmd)
{
	int	is_builtin;

	is_builtin = 0;
	if (!ft_strncmp(cmd[0], "pwd", ft_strlen("pwd")))
		is_builtin = builtins_pwd(cmd);
	else if (!ft_strncmp(cmd[0], "env", ft_strlen("env")))
		is_builtin = print_env(cmd);
	else if (!ft_strncmp(cmd[0], "exit", ft_strlen("exit")))
		is_builtin = exit_cmd(cmd);
	else if (!ft_strncmp(cmd[0], "cd", ft_strlen("cd")))
		is_builtin = change_directory(cmd);
	else if (!ft_strncmp(cmd[0], "echo", ft_strlen("echo")))
		is_builtin = echo(cmd);
	else if (!ft_strncmp(cmd[0], "export", ft_strlen("export")))
		is_builtin = export(cmd);
	else if (!ft_strncmp(cmd[0], "unset", ft_strlen("unset")))
		is_builtin = unset(cmd);
	return (is_builtin);
}
