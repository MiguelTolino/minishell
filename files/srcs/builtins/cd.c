/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:13:01 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/09 14:13:43 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void change_directory(char *path)
{
	char *new_path;
	
	if (!path)
	{
		new_path =	getenv("HOME");
	}
	if (chdir(new_path) < 0)
		perror("Chdir Error");
}