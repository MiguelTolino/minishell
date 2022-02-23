/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:45:39 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/23 21:55:27 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exit_shell(void)
{
	exit(g_global.exit_status);
}

void	exit_ctrld(t_shell shell)
{
	free(shell.prompt);
	rl_clear_history();
	printf("exit\n");
	exit_shell();
}

int	throw_error(const char *error)
{
	perror(error);
	return (1);
}

void	check_args(int argc)
{
	if (argc != 1)
	{
		throw_error("Numbers of arguments invalid");
		exit(EXIT_FAILURE);
	}
}

bool	search_errors(char *cmdline)
{
	int	i;

	i = 0;
	while (cmdline[i])
	{
		if (cmdline[i] == '|' && ((!ft_isalnum(cmdline[i + 1]) && cmdline[i + 1] != ' ') || (!ft_isalnum(cmdline[i - 1])
					&& cmdline[i - 1] != ' ')))
			return (true);
		i++;
	}
	return (false);
}

int	error_parsing(char *cmdline)
{
	char	*errors[6];
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(cmdline);
	errors[0] = "><";
	errors[1] = "<>";
	errors[2] = "<|";
	errors[3] = "|||";
	errors[4] = "||";
	errors[5] = NULL;
	while (errors[i])
	{
		if (ft_strnstr(cmdline, errors[i], len) || search_errors(cmdline))
		{
			throw_error("Unexpected operators");
			g_global.exit_status = 2;
			return (1);
		}
		i++;
	}
	return (0);
}
