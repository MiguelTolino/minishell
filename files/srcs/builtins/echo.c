/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:16:30 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/01/24 17:11:41 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void echo(char *token)
{
	/*if (option)
		printf("%s", cmd);
	else
		printf("%s\n", cmd);*/
	printf("%s ", token);
}