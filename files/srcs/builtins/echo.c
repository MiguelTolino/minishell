/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:16:30 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/24 23:51:07 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	echo(char **cmd)
{
	int	i;
	int	option;

	i = 1;
	option = 0;
	if (len_array(cmd) == 1)
	{
		printf("\n");
		return (1);
	}
	if (!ft_strcmp(cmd[i], "-n"))
	{
		option = 1;
		i++;
	}
	while (cmd[i])
	{
		if (!cmd[i + 1])
			printf("%s", cmd[i++]);
		else
			printf("%s ", cmd[i++]);
	}
	if (!option)
		printf("\n");
	return (1);
}
