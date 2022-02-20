/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:38:48 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/18 20:07:18 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//FIXME: Comprobar mejor que el numero es solo digitos y si no exity && laznar error
// Si le paso varios argumentos lanzar error
 
void	exit_cmd(char **cmd)
{	
	int i;
	int is_nbr;

	i = 0;
	is_nbr = 0;
	if(!cmd[1])
		exit(EXIT_SUCCESS);
	else if (!cmd[2])
	{
		while (cmd[1][i])
			is_nbr += ft_isdigit(cmd[1][i++]);
		if (is_nbr == (int)ft_strlen(cmd[1]))
		{
			global.exit_status = ft_atoi(cmd[1]);
			exit(ft_atoi(cmd[1]));
		}
		else
		{
			printf("exit: %s: numeric argument required\n", cmd[1]);
			exit(EXIT_SUCCESS);
		}
	}
	else
		printf("exit: too many arguments\n");
}
