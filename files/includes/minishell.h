/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:27:13 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/01/26 20:44:09 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <fcntl.h>
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

# define MAXCOM 1024 // max number of letters to be supported
# define MAXLIST 100 // max number of commands to be supported
# define MAXHIST 128 // max number of commands to be saved

# define READ_END 0
# define WRITE_END 1

enum	e_type
{
	CMD, //defaut set
	ARG, //word
	FILE_IN, //word == '<'
	HERE_DOC, // word == '<<'
	FILE_OUT, //word == '>'
	FILE_OUT_SUR, //word == '>>'
	OPEN_FILE, // word following '<'
	LIMITOR, // word following '<<'
	EXIT_FILE, // word followinf '>'
	EXIT_FILE_RET // word following '>>'
};

typedef struct s_token
{
	char	*word;
	enum	e_type type;
}	t_token;

typedef struct	s_cmd_data
{
	char		*cmd;
	t_list		*token;
	char		**exec_cmd;
	int			cmd_len;
}	t_cmd_data;

typedef struct s_shell
{
	t_list *cmdlist;
	char *cmdline;
	char *prompt;
}	t_shell;

typedef struct g_global
{
	char	**env;
	int		exit_status;
}	g_global;

g_global global;

char*	build_prompt();
int		exec_builtins(char **cmd);
int		save_env(char **envp);
void	throw_error(const char *error);
void	check_args(int argc);
void	parsing(t_shell *shell);
int		execution(t_shell *shell);
int		search_pipes(char *cmdline);
int		len_array(char **array);
char	*check_cmd(char *cmd);
int		dfree(char **array);
void	free_shell(t_shell *shell);
void	quoting(t_shell *shell);
void	test(t_shell shell);
void	signal_handler();
void	lexer(t_shell *shell);
void	dividing(t_shell *shell, int single, int doble);
void	ignore_quotes(char *cmd, char type, int *i, int num);
void	redirections(t_shell *shell);
int		restore_fd(void);

void print(void *content);

//Builtins
void	env(char **envp);
void	change_directory(char *str);
void	echo(char **cmd);
void	exit_shell();

#endif