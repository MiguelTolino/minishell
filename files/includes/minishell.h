/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:27:13 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/25 04:21:21 by rgirondo         ###   ########.fr       */
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
# include <stdbool.h>
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
# define WHITESPACE "\t\n\v\f\r "
# define REDIRECTION "|<>"

enum e_quote
{
	NONE,
	SINGLE,
	DOUBLE
};

/*
	CMD, //defaut set
	ARG, //word
	FILE_IN, //word == '<'
	HERE_DOC, // word == '<<'
	FILE_OUT, //word == '>'
	FILE_OUT_SUR, //word == '>>'
	OPEN_FILE, //word following '<'
	LIMITOR, //word following '<<'
	EXIT_FILE, // word followinf '>'
	EXIT_FILE_RET //word following '>>'
*/

enum e_type
{
	CMD,
	ARG,
	FILE_IN,
	HERE_DOC,
	FILE_OUT,
	FILE_OUT_SUR,
	OPEN_FILE,
	LIMITOR,
	EXIT_FILE,
	EXIT_FILE_RET
};

enum	e_signal
{
	MAIN,
	HD,
	CHILD
};

typedef struct s_token
{
	char			*word;
	enum e_type		type;
	enum e_quote	quote;
}	t_token;

typedef struct s_cmd_data
{
	char		*cmd;
	t_list		*token;
	char		**exec_cmd;
	int			n_single;
	int			n_double;
}	t_cmd_data;

typedef struct s_shell
{
	char	*cmdline;
	char	*prompt;
	t_list	*cmdlist;
}	t_shell;

struct s_global
{
	char	**env;
	char	**env_export;
	int		env_len;
	int		exit_status;
	int		fd_stdin;
	int		fd_stdout;
	bool	exec;
	int		signal_status;
	int		whereami;
};

struct s_global	g_global;

char			*build_prompt(void);
int				exec_builtins(char **cmd);
int				save_env(char **envp);
int				throw_error(const char *error);
void			check_args(int argc);
void			parsing(t_shell *shell);
int				execution(t_shell *shell);
int				search_pipes(char *cmdline);
int				len_array(char **array);
int				check_path(char **cmd);
int				dfree(char **array);
void			free_shell(t_shell *shell);
int				quoting(t_shell *shell);
void			test(t_shell shell);
void			signal_handler(void);
void			lexer(t_shell *shell);
void			dividing_by_token(t_shell *shell, int *single, int *doble);
int				validate_token(t_list *cmdlist);
int				ignore_quotes(char *cmd, char type, int *i, int *num);
void			ignore_spaces(char *cmd, int *i);
void			redirections(t_shell *shell);
void			restore_fd(void);
void			exit_ctrld(char *cmdline);
void			loop_pipe(t_list *cmdlist);
void			init_g_global(char **envp, char **argv);
int				count_closed_quotes(char *cmdline, char quote);
char			*expand_word(char *cmd);
void			token_expansion(t_shell *shell);
int				limitor_function(t_token *limit);
void			print(void *content);
int				expand_word2(t_list *cmdlist);
char			**init_env(char **envp);
void			sigint_heredoc(int sig);
void			sigint_handler(int sig);
void			print_msg(void);
int				parsing_errors(t_list *cmdlist);
int				init_shell(char **argv, char **envp);
int				limitor_function_ps(t_token *limit);
void			nothing(int signal);
void			stop_heredoc(int sig);
void			newline(int signal);
void			child_process(int fd_in, t_list *cmdlist, char **cmd, int p[2]);
unsigned int	select_type(t_token *token, int old_type);

//Builtins
int				print_env(char **cmd);
int				exit_cmd(char **cmd);
int				change_directory(char **cmd);
int				echo(char **cmd);
void			exit_shell(void);
int				export(char **cmd);
int				unset(char **cmd);
char			*getvar(char *cmd);
void			change_val(char *var_name, char *cmd);
char			*get_name(char *cmd);
int				builtins_pwd(char **cmd);
char			**create_env_export(void);

//Expansion
void			unsplit(char **matrix, t_token *token);
void			new_token(t_list *token_list);
char			*expand(char *var_value);
void			join_expand_1(char **new_str, char **cmd, int i, int type);
void			join_expand_2(char **new_str, char **cmd, int i);
char			*expand_ident_2(char *cmd, char quotes);
void			add_new(char *new_var);
char			**create_env_export(void);

//Utils
bool			is_filename(char *str);
int				valid_op_arg_aux(t_token *token_data);
int				ft_strcmp(const char *s1, const char *s2);
bool			is_filename(char *str);

#endif
