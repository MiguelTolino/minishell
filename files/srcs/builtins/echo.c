/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:16:30 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/14 20:53:26 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void echo(char **cmd)
{
	int i;
	
	i = 1;
	while (cmd[i])
		printf("%s ", cmd[i++]);
	if (ft_strncmp(cmd[1], "-n", ft_strlen(cmd[1])))
		printf("\n");
}
