/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:46:43 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/25 11:16:05 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*build_prompt(void)
{
	char	*prompt;
	char	*dir;
	char	*user;

	user = getvar("USER");
	dir = getvar("PWD");
	prompt = (char *)calloc(sizeof(char), MAXCOM);
	if (!dir || !user || !prompt)
	{
		throw_error("Error building prompt");
		exit(1);
	}
	ft_strlcat(prompt, BLUE, ft_strlen(BLUE) + 1);
	ft_strlcat(prompt, user, ft_strlen(prompt) + ft_strlen(user) + 1);
	ft_strlcat(prompt, NC, ft_strlen(prompt) + ft_strlen(NC) + 1);
	ft_strlcat(prompt, SIMBOL1, ft_strlen(prompt) + ft_strlen(SIMBOL1) + 1);
	ft_strlcat(prompt, GREEN, ft_strlen(prompt)
		+ ft_strlen(GREEN) + 1);
	ft_strlcat(prompt, dir, ft_strlen(prompt) + ft_strlen(dir) + 1);
	ft_strlcat(prompt, NC, ft_strlen(prompt) + ft_strlen(NC) + 1);
	ft_strlcat(prompt, SIMBOL2, ft_strlen(prompt) + ft_strlen(SIMBOL2) + 1);
	free(dir);
	free(user);
	return (prompt);
}
