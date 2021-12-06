/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:13:01 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/06 11:50:28 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void change_directory(char *path)
{
	char *new_path;
	new_path = strrchr(path, ' ');
	if (!new_path)
	{
		new_path = vars.home;
	}
	if (chdir(new_path) < 0)
		throw_error("Chdir Error:");
}