/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:27:13 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/07 19:35:30 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../lib/libft/libft.h"
# include "colors.h"

# define SIMBOL "$> "

typedef struct g_env
{
	char *home;
	char *user;
	char *hostname;
	char *pwd;
	char *old_pwd;
}	g_env;

g_env vars;

char* build_prompt(char *prompt);
void action(char **cmd, char **envp);
int	save_env(char **envp);
void throw_error(const char *error);
void check_args(int argc);
char **parsing(char *cmdline);

//Commands
void	env(char **envp);
void change_directory(char *str);
void	echo(char **str, char option);
void 	exit_shell();

#endif