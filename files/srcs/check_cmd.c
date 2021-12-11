/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:50:51 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/11 12:08:38 by mmateo-t         ###   ########.fr       */
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
	int	bool;

	i = 0;
	bool = 0;
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

/*	1. Check cmd and paths is different of null
	2. check cmd is an actually path
	3. if dont -> add_path and check if exists
	4. double free
	5.return cmd
*/

char *check_cmd(char *cmd)
{
	char *path;
	char **paths;
	char *new_cmd;

	path = getenv("PATH");
	paths = ft_split(path, ':');
	if (!cmd || !paths)
		return (NULL);
	if (!(access(cmd, X_OK)))
		new_cmd = cmd;
	else
		cmd = search_cmd(cmd, paths);
	dfree(paths);
	return (new_cmd);
}