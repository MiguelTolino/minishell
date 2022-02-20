/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:52:45 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/19 15:23:28 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	print_env(char **cmd)
{
	int i;

	i = 0;
	if (len_array(cmd) > 1)
	{
		throw_error("Error: Too many arguments");
		return (1);
	}
	while (global.env[i])
	{
		printf("%s\n", global.env[i]);
		i++;
	}
	return (0);
}
