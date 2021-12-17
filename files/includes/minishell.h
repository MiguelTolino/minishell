/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:27:13 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/17 20:16:09 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
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
#define MAXHIST 128 // max number of commands to be saved

# define READ_END 0
# define WRITE_END 1

typedef struct s_history
{
	
} t_history;

typedef struct s_shell
{
	char *cmdline;
	char *prompt;
	char **cmds;
	char *cmd;
	char **words;
	char **operators;
	int	n_pipes;
	char **cmds_pipe[MAXLIST];
}	t_shell;

typedef struct g_global
{
	char **envp;
	char **local_env;

	//Signals
}	g_global;

g_global global;

char* build_prompt();
int exec_builtins(char **cmd, char **envp);
int	save_env(char **envp);
void throw_error(const char *error);
void check_args(int argc);
int parsing(t_shell *shell);
int exec(char **cmds, char **envp);
int	search_pipes(char *cmdline);
int	len_array(char **array);
char *check_cmd(char *cmd);
int	dfree(char **array);
void free_struct(t_shell shell);
int quoting(t_shell *shell);
void test(t_shell shell);
void	exec_pipes(char **cmd[MAXLIST], int n_pipes, char **envp);
void	signal_handler();


//Builtins
void	env(char **envp);
void change_directory(char *str);
void	echo(char **cmd);
void 	exit_shell();

#endif