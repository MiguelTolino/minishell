/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:46:43 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/10 21:52:40 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*set_directory(char *dir)
{
	int		size;
	char	*ptr;

	size = MAXCOM;
	dir = (char *)malloc((size_t)size);
	if (dir != NULL)
		ptr = getcwd(dir, (size_t)size);
	else
		throw_error(PROMPT_ERROR);
	return (ptr);
}

char	*build_prompt(void)
{
	char	*prompt;
	char	*dir;
	char	*user;

	user = getenv("USER");
	if (!user)
		throw_error(PROMPT_ERROR);
	dir = set_directory(dir);
	prompt = (char *)malloc(sizeof(char) * MAXCOM);
	ft_strlcat(prompt, COLOR(1, 33), ft_strlen(COLOR(1, 33)) + 1);
	ft_strlcat(prompt, user, ft_strlen(prompt) + ft_strlen(user) + 1);
	ft_strlcat(prompt, NC, ft_strlen(prompt) + ft_strlen(NC) + 1);
	ft_strlcat(prompt, SIMBOL1, ft_strlen(prompt) + ft_strlen(SIMBOL1) + 1);
	ft_strlcat(prompt, COLOR(1, 34), ft_strlen(prompt)
		+ ft_strlen(COLOR(1, 34)) + 1);
	ft_strlcat(prompt, dir, ft_strlen(prompt) + ft_strlen(dir) + 1);
	ft_strlcat(prompt, NC, ft_strlen(prompt) + ft_strlen(NC) + 1);
	ft_strlcat(prompt, SIMBOL2, ft_strlen(prompt) + ft_strlen(SIMBOL2) + 1);
	free(dir);
	return (prompt);
}
