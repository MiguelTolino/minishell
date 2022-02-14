/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:19:52 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/22 17:37:53 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *free_join(char *join, char *str)
{
    char *s;

    s = 0;
    if (join)
    {
        s = ft_strjoin(join, str);
        free(join);
    }
    return (s);
}

char    *getvar(char *cmd, char **vars)
{
    int i;
    char *str;

    i = 0;
    str = 0;
    while (vars[i] && !ft_strnstr(vars[i], cmd, ft_strlen(cmd)))
        i++;
    if (vars[i] && ft_strnstr(vars[i], cmd, ft_strlen(cmd)))
    {
        str = vars[i] + (ft_strlen(cmd) + 1);
    }
    else
        return (NULL);
    return (str);
}

char    *get_name(char *cmd)
{
    int i;
    char *str;

    i = 0;
    str = (char *)malloc(1);
    while (cmd[i] && cmd[i] != '=')
    {
        str[i] = cmd[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

void    add_new(char *new_var, char **envp)
{
    int i;

    i = 0;
    while (envp[i])
        i++;
    envp[i] = ft_strdup(new_var);
    envp[i + 1] = NULL;
}

void    change_val(char *var_name, char *cmd, char **envp)
{
    int i;
    
    i = 0;
    while (!ft_strnstr(envp[i], var_name, ft_strlen(var_name)) && envp[i])
        i++;
    free(envp[i]);
    envp[i] = ft_strdup(cmd);
}

void    export(char *cmd, char **envp)
{
    char *new_var;
    char *var_name;
    int i = 0;

    if (cmd)
    {
        var_name = get_name(cmd);
        new_var = getvar(var_name, envp);
        if (ft_strchr(cmd, '=') && !new_var)
            add_new(cmd, envp);
        else if (ft_strchr(cmd, '=') && new_var)
            change_val(var_name, cmd, envp);
        free(var_name);
    }
}