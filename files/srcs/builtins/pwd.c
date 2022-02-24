/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:15:45 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/24 18:54:39 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	builtins_pwd(char **cmd)
{
	char *pwd;

	if (len_array(cmd) > 1)
	{
		throw_error("Too many arguments");
		g_global.exit_status = 1;
		return (g_global.exit_status);	
	}
	pwd = getvar("PWD");
	printf("%s\n", pwd);
	free(pwd);
	return (1);
}