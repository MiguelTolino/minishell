/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:27:13 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/05 18:50:04 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include "../lib/libft/libft.h"
# include "colors.h"

# define SIMBOL "> $ "

typedef struct s_prompt
{
	char *user;
	char *hostname;
	char *simbol;
	char *dir;
} t_prompt;

t_prompt build_prompt(char **envp);

#endif