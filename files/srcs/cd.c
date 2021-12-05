/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:13:01 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/05 20:55:35 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void change_directory(char *old_path)
{
	char *new_path;
	if (!*old_path)
	{
		new_path = vars.home;
	}
	if(*old_path == '.')
	{
		new_path = vars.pwd;
	}
	if(ft_strnstr(old_path, "..", ft_strlen(old_path)))
	{
		
	}
	chdir(new_path);
}