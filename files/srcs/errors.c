/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:45:39 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/15 17:58:43 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exit_shell(void)
{
	exit(global.exit_status);
}

void	exit_ctrld(t_shell shell)
{
	free(shell.prompt);
	exit_shell();
}


void	throw_error(const char *error)
{
	perror(error);
}

void	check_args(int argc)
{
	if (argc != 1)
	{
		throw_error("Numbers of arguments invalid");
		exit(EXIT_FAILURE);
	}
}

//TODO: Add more errors

int	error_parsing(char *cmdline)
{
	char *errors[6];
	int len;
	int i;
	
	i = 0;
	len = ft_strlen(cmdline);
	errors[0] = "><";
	errors[1] = "<>";
	errors[2] = "<|";
	errors[3] = ">|";
	errors[4] = "||";
	errors[5] = NULL;
	while (errors[i])
	{
		if (ft_strnstr(cmdline, errors[i], len))
		{
			throw_error("Unexpected operators");
			return (1);
		}
		i++;
	}
	return (0);
}
