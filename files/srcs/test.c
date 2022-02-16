/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:02:48 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/14 14:03:17 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void print(void *content)
{
	t_cmd_data *data;
	data = (t_cmd_data *)content;

	printf("ITER:%s\t", data->cmd);
	printf("\n");
}

void test_token_list(t_cmd_data *cmd_data)
{
	t_list *token_list;
	token_list = ((t_list *)cmd_data->token);
	printf("\nTOKENS\n");
	printf("---------------------\n");
	while (token_list)
	{
		printf("WORD:{%s}\n", ((t_token *)token_list->content)->word);
		printf("TYPE:{%i}\n", ((t_token *)token_list->content)->type);
		printf("QUOTE:{%i}\n", ((t_token *)token_list->content)->quote);
		printf("-----------------------");
		printf("\n");
		token_list = token_list->next;
	}
}

void test_exec_cmd(t_cmd_data *cmd_data)
{
	int i;

	i = 0;
	printf("EXEC_CMD:");
	while (cmd_data->exec_cmd[i])
	{
		printf("[%s]", cmd_data->exec_cmd[i]);
		i++;
	}
	printf("\n\n");
}

void test(t_shell shell)
{
	t_list *token_list;
	t_cmd_data *cmd_data;
	(void)token_list;
	printf("CMDLINE:{%s}\n\n", shell.cmdline);
	while (shell.cmdlist)
	{
		cmd_data = ((t_cmd_data *)shell.cmdlist->content);
		printf("CMD:{%s}\n", cmd_data->cmd);
		test_token_list(cmd_data);
		test_exec_cmd(cmd_data);
		shell.cmdlist = shell.cmdlist->next;
	}
}
