/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:13:01 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/24 21:07:54 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*change_home(char *path)
{
	char	*tmp;
	char	*tmp2;

	if (path[0] == '~')
		tmp = getvar("HOME");
	if (path[1] != '/')
	{
		tmp2 = ft_strjoin(tmp, "/");
		free(tmp);
		tmp = tmp2;
	}
	tmp2 = ft_strjoin(tmp, (path + 1));
	if (path)
		free(path);
	path = tmp2;
	free(tmp);
	return (path);
}

void	change_old_new_pwd(void)
{
	char	*tmp;
	char	*old_path;
	char	*new_path;
	char	*pwd;

	pwd = getvar("PWD");
	old_path = ft_strjoin("OLDPWD=", pwd);
	tmp = getcwd(NULL, 1000);
	new_path = ft_strjoin("PWD=", tmp);
	change_val("PWD", new_path);
	change_val("OLDPWD", old_path);
	free(old_path);
	free(tmp);
	free(new_path);
	if (pwd)
		free(pwd);
}

void	go_old_pwd(char **path)
{
	free(*path);
	*path = getvar("OLDPWD");
	printf("%s\n", *path);
}

int	change_directory(char **cmd)
{
	char	*path;

	if (cmd[2] && cmd[1])
	{
		printf("cd: too many arguments\n");
		return (1);
	}
	if (!cmd[1])
		path = getvar("HOME");
	else
		path = ft_strdup(cmd[1]);
	if (path && path[0] == '~')
		path = change_home(path);
	if (path && path[0] == '-' && !path[1])
		go_old_pwd(&path);
	if (chdir(path) < 0)
	{
		printf("cd: string not in pwd: %s\n", path);
		free(path);
		return (1);
	}
	if (path)
		free(path);
	change_old_new_pwd();
	return (1);
}
