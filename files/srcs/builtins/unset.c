/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:20:57 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/17 18:52:31 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void unset(char **cmd)
{
    int i;
    int j;
    char *old_var;
    char **envp;

    j = 0;
    envp = global.env;
    while (cmd[j])
    {
        if (cmd[j])
        {
            i = 0;
            while (envp[i] && !ft_strnstr(envp[i], cmd[j], ft_strlen(cmd[j])))
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
                global.env_len -= 1;
            }
        }
        j++;
    }
}