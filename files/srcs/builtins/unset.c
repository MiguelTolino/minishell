/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:20:57 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/14 20:27:10 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void unset(char *cmd)
{
    int i;
    char *old_var;
    char **envp;

    envp = global.env;
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