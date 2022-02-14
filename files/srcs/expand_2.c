/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:41:18 by rgirondo          #+#    #+#             */
/*   Updated: 2022/02/14 20:25:54 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*expand_str(char *str)
{
	char **matrix;
	char *new_str;
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i] != '$')
		i++;
	matrix = ft_split(str, '$');
	if (i != 0)
		i = 1;
	else
		i = 0;
	while (matrix[i])
	{
	    if (!ft_strncmp(matrix[i], "?", ft_strlen(matrix[i])))
        {
            free(matrix[i]);
            matrix[i] = ft_strdup(ft_itoa(global.exit_status));
        }
        else
        {
            free(matrix[i]);
		    matrix[i] = getvar(matrix[i]);
		    if (matrix[i])
			    matrix[i] = ft_strdup(matrix[i]);
		    else
			    matrix[i] = ft_strdup("\0");
        }
        i++;
	}
	i = 0;
	while (matrix[i])
		len += ft_strlen(matrix[i++]);
	i = 0;
	new_str = malloc(sizeof(char) * (len + 1));
	new_str[0] = '\0';
	while (matrix[i])
	{
		ft_strlcat(new_str, matrix[i], ft_strlen(new_str) + ft_strlen(matrix[i]) + 1);
		i++;
	}
	free(str);
	free_matrix(matrix);
	return (new_str);
}

void unsplit(char **matrix, t_token *token)
{
	char *new_str;
	int j;
	int len;

	j = 0;
	len = 0;
	while (matrix[j])
		len += (ft_strlen(matrix[j++]) + 1);
	new_str = malloc(sizeof(char) * (len + 1));
	new_str[0] = '\0';
	j = 0;
	while (matrix[j])
	{	
		if (matrix[j][0])
			ft_strlcat(new_str, matrix[j], ft_strlen(new_str) + ft_strlen(matrix[j]) + 1);
		if (matrix[j + 1])
			ft_strlcat(new_str, " ", ft_strlen(new_str) + 2);
		j++;
	}
	if (token->word)
		free(token->word);
	token->word = new_str;
	free_matrix(matrix);
}