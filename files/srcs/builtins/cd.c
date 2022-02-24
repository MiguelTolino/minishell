/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:13:01 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/24 13:45:53 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//FIXME: Genera leaks

char	*change_home(char *path)
{
	char	*tmp;
	char	*tmp2;

	if (path[0] == '~')
		tmp = getvar("HOME");
	path += 1;
	if (path[0] != '/')
	{
		tmp2 = ft_strjoin(tmp, "/");
		free(tmp);
		tmp = tmp2;
	}
	path = ft_strjoin(tmp, path);
	free(tmp);
	return (path);
}

void	change_old_new_pwd(void)
{
	char	*tmp;
	char	*old_path;
	char	*new_path;

	old_path = ft_strjoin("OLDPWD=", getvar("PWD"));
	tmp = getcwd(NULL, 1000);
	new_path = ft_strjoin("PWD=", tmp);
	change_val("PWD", new_path);
	change_val("OLDPWD", old_path);
	free(old_path);
	free(tmp);
	free(new_path);
}

void	change_directory(char **cmd)
{
	char	*path;

	if (cmd[2] && cmd[1])
	{
		printf("cd: too many arguments\n");
		return ;
	}
	if (!cmd[1])
		path = getvar("HOME");
	else
		path = cmd[1];
	if (path && path[0] == '~')
		path = change_home(path);
	if (path && path[0] == '-' && !path[1])
	{
		path = getvar("OLDPWD");
		printf("%s\n", path);
	}
	if (chdir(path) < 0)
	{
		printf("cd: string not in pwd: %s\n", path);
		return ;
	}
	change_old_new_pwd();
}
