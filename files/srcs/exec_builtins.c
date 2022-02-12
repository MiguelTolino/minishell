/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:14:58 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/01/24 19:17:45 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int exec_builtins(char **cmd, char **envp)
{
	(void)cmd;
	(void)envp;
/*t_list *list;
	t_list *token_list;
	t_cmd_data *cmd_data;
	char *builtin;

	list = shell.cmdlist;
	cmd_data = ((t_cmd_data *)list->content);
	token_list = NULL;
	token_list = ((t_list *)cmd_data->token);
	builtin = ft_strdup(((t_token *)token_list->content)->word);
	token_list = token_list->next;
	if(!ft_strncmp(builtin, "pwd", ft_strlen(builtin)))
		printf("%s\n", getvar("PWD", envp));
	if(!ft_strncmp(builtin, "env", ft_strlen(builtin)))
		env(envp);
	if(!ft_strncmp(builtin, "exit", ft_strlen(builtin)))
		exit(EXIT_SUCCESS);
	while (token_list)
	{
		if(!ft_strncmp(builtin, "cd", ft_strlen(builtin)))
			change_directory(((t_token *)token_list->content)->word, envp);
		if(!ft_strncmp(builtin, "echo", ft_strlen(builtin)))
			echo(((t_token *)token_list->content)->word);
		if(!ft_strncmp(builtin, "export", ft_strlen(builtin)))
			export(((t_token *)token_list->content)->word, envp);
		if(!ft_strncmp(builtin, "unset", ft_strlen(builtin)))
			unset(((t_token *)token_list->content)->word, envp);
		token_list = token_list->next;
	}
	free(builtin);
	*/
	return (0);
}
