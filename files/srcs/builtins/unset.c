/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:20:57 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/01/19 17:35:59 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void unset(char *cmd, char **envp)
{
    int i;
    char *old_var;

    if (cmd)
    {
        i = 0;
        while (envp[i] && !ft_strnstr(envp[i], cmd, ft_strlen(cmd)))
            i++;
        if (envp[i])
        {
            old_var = envp[i];
            while (envp[i])
            {
                envp[i] = envp[i + 1];
                i++;
            }
            free(old_var);
        }
    }
}