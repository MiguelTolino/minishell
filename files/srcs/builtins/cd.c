/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:13:01 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/18 20:02:53 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//FIXME: 1. No funciona con mas de 1 argumento -> //TODO: Lanzar error
// 2. Que funcione solo -
// 3. ERROR --     cd: string not in pwd: r3

void change_directory(char *path)
{
	char *new_path;
	char *old_path;
	char *tmp;
	char *tmp2;

	if (!path)
		path = getvar("HOME");
	if (path && (path[0] == '~' || path[0] == '-'))
	{
		if (path[0] == '~')
			tmp = getvar("HOME");
		else
			tmp = getvar("OLDPWD");
		path += 1;
		if (path[0] != '/')
		{	
			tmp2 = ft_strjoin(tmp, "/");
			free(tmp);
			tmp = tmp2;
		}
		path = ft_strjoin(tmp, path);
		free(tmp);
	}
	old_path = ft_strjoin("OLDPWD=", getvar("PWD"));
	if (chdir(path) < 0)
	{
		perror("Chdir Error");
		return;
	}
	tmp = getcwd(NULL, 1000);
	new_path = ft_strjoin("PWD=", tmp);
	change_val("PWD", new_path);
	change_val("OLDPWD", old_path);
	free(old_path);
	free(tmp);
	free(new_path);
}