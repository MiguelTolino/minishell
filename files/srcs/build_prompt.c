/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:46:43 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/10 17:36:47 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//FIXME: Free prompt

char *set_directory(char *dir)
{
	int size = 1024;
	char *ptr;
	
	if ((dir = (char *)malloc((size_t)size)) != NULL)
		ptr = getcwd(dir, (size_t)size);
	return(ptr);
}

char	*build_prompt()
{
	char *prompt;
	char *dir;
	char *user;
	
	user = getenv("USER");
	prompt = (char *)malloc(sizeof(char) * 1024);
	dir = set_directory(dir);
	ft_strlcat(prompt, user, ft_strlen(user) + 1);
	ft_strlcat(prompt, SIMBOL1, ft_strlen(prompt) + ft_strlen(SIMBOL1) + 1);
	ft_strlcat(prompt, dir, ft_strlen(prompt) + ft_strlen(dir) + 1);
	ft_strlcat(prompt, SIMBOL2, ft_strlen(prompt) + ft_strlen(SIMBOL2) + 1);
	return (prompt);
}
