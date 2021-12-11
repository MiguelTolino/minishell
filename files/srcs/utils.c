/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:11:30 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/11 14:16:42 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	len_array(char **array)
{
	int i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
	{
		i++;
	}
	return (i);
}

int	dfree(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}