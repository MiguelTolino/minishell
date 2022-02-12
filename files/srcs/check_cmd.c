/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:50:51 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/08 22:02:18 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*add_slash(char *path)
{
	char *new_path;

	if (!path)
		return (NULL);
	new_path = ft_strjoin(path, "/");
	return (new_path);
}

char	*search_cmd(char *cmd, char **paths)
{
	int i;
	char *aux;
	char *full_cmd;

	i = 0;
	while (paths[i])
	{
		aux = add_slash(paths[i]);
		full_cmd = ft_strjoin(aux, cmd);
		free(aux);
		if (!(access(full_cmd, X_OK)))
			return (full_cmd);
		else
			free(full_cmd);
		i++;
	}
	return (NULL);
}

/*
	1. Check cmd and paths is different of null
	2. check cmd is an actually path
	3. if dont -> add_path and check if exists
	4. double free
	5.return cmd
*/

//FIXME: CHECK_CMD LEAKS, int function returns 0 or 1 and change cmd value

int	check_path(char *cmd)
{
	char *path;
	char **paths;
	char *new_cmd;
	int check;

	check = 0;
	path = getenv("PATH");
	paths = ft_split(path, ':');
	if (!cmd || !paths)
		check = 0;
	if (!(access(cmd, X_OK)))
	{
		new_cmd = cmd;
		check = 1;
	}
	else
	{
		new_cmd = search_cmd(cmd, paths);
		if (new_cmd)
			check = 1;
	}
	dfree(paths);
	if (check)
	{
		
	}
	
	return (check);
}