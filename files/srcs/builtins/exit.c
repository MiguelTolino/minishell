/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:38:48 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/19 14:51:54 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	contains_digits(char *cmd)
{
	int i;

	i = 0;
	while (cmd[i])
	{
		if (!ft_isdigit(cmd[i]))
			return (0);
		i++;
	}
	return (1);
}

void	exit_cmd(char **cmd)
{
	if (!contains_digits(cmd[1]))
		throw_error("Error: Bad expression");
	if (len_array(cmd) > 2)
		throw_error("Error: Too many arguments");
	if(!cmd[1])
		exit(EXIT_SUCCESS);
	else
		exit(ft_atoi(cmd[1]));
}
