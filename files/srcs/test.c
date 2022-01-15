/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:02:48 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/01/14 18:27:28 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void test(t_shell shell)
{
	t_list *list;
	list = shell.cmdlist;

	while (list)
	{
		printf("|%s|\n", ((t_cmd_data *)list->content)->cmd);
		list = list->next;
	}
}


/* void test(t_shell shell)
{
	t_list *list;
	list = shell.cmdlist;
	t_token *token;

	while (list)
	{
		token = ((t_cmd_data *)list->content)->token;
		printf("%s\n", token->word);
		list = list->next;
	}
} */