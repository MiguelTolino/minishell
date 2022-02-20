/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:52:45 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/14 20:20:58 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_env(char **cmd)
{
	int i;

	i = 0;
	if (cmd[1])
	{
		printf("env : too many arguments\n");
		return;
	}
	while (global.env[i])
	{
		printf("%s\n", global.env[i]);
		i++;
	}
}
