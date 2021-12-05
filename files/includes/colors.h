/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:02:29 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/05 18:28:17 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* Colors
Black       0;30     Dark Gray     1;30
Blue        0;34     Light Blue    1;34
Green       0;32     Light Green   1;32
Cyan        0;36     Light Cyan    1;36
Red         0;31     Light Red     1;31
Purple      0;35     Light Purple  1;35
Brown       0;33     Yellow        1;33
Light Gray  0;37     White         1;37

	\033[47;31m string \033[0m
47->color de fondo
31->color del carácter
\033[5m es el código de control
*/

#define NC "\033[0m" //No Color
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BROWN "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"

#define COLOR(x,y) "\033["#x";"#y"m"    // x: fondo, y: primer plano