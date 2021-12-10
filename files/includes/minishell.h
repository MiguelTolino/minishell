/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:27:13 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/10 21:45:18 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../lib/libft/libft.h"
# include "colors.h"
# include "error.h"

# define SIMBOL1 " <" 
# define SIMBOL2 "> $ "

#define MAXCOM 1024 // max number of letters to be supported
#define MAXLIST 100 // max number of commands to be supported

typedef struct s_shell
{
	char *cmdline;
	char *prompt;
}	t_shell;

typedef struct g_global
{
	char **envp;
	char **local_env;
	//Signals
}	g_global;

g_global global;

char* build_prompt();
int action(char **cmd, char **envp);
int	save_env(char **envp);
void throw_error(const char *error);
void check_args(int argc);
char **parsing(char *cmdline, char **envp);
int exec(char **cmds, char **envp);
char *add_path(char *cmd, char **envp);
int	search_pipes(char *cmdline);
int	len_array(char **array);

//Commands
void	env(char **envp);
void change_directory(char *str);
void	echo(char **str, char option);
void 	exit_shell();

#endif