/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:14:58 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/25 14:15:18 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exec_builtins(char **cmd)
{
	int	is_builtin;

	is_builtin = 0;
	if (!ft_strcmp(cmd[0], "pwd"))
		is_builtin = builtins_pwd(cmd);
	else if (!ft_strcmp(cmd[0], "env"))
		is_builtin = print_env(cmd);
	else if (!ft_strcmp(cmd[0], "exit"))
		is_builtin = exit_cmd(cmd);
	else if (!ft_strcmp(cmd[0], "cd"))
		is_builtin = change_directory(cmd);
	else if (!ft_strcmp(cmd[0], "echo"))
		is_builtin = echo(cmd);
	else if (!ft_strcmp(cmd[0], "export"))
		is_builtin = export(cmd);
	else if (!ft_strcmp(cmd[0], "unset"))
		is_builtin = unset(cmd);
	return (is_builtin);
}
