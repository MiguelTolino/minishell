/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:16:30 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/07 19:41:41 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//FIXME: -n option

void echo(char **str, char option)
{
	int i;

	i = 1;
	while (str[i])
	{
		if (option == 'n')
			printf("%s", str[i]);
		else
			printf("%s ", str[i]);
		i++;
	}
	printf("\n");
}