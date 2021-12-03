# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 10:00:24 by mmateo-t          #+#    #+#              #
#    Updated: 2021/12/03 10:45:41 by mmateo-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#AUTHOR mmateo-t
#USAGE

#make          #compile all binary
#make clean		#remove all binaries
#make fclean		#remove all binaries and executable

SRCS_DIR:= files/srcs/
SRCS := $(wildcard $(SRCS_DIR)*.c)
OBJS := $(SRCS:%.c=%.o)
NAME:= minishell
CC:= gcc
#CFLAGS:= -Wall -Werror -Wextra
SYS_LIB:= -lreadline
LIBFT_PATH:= files/lib/libft
LIBFT_LIB:= -L$(LIBFT_PATH) $(LIBFT_PATH)/libft.a
RM := rm -rvf
DEBUG_FLAG:= -g

all:	libft $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_LIB) $(SYS_LIB)
			
$(%.o): $(%.c)
			$(CC) -c $^ -o $@
					@echo "Creating objects"

libft:
			make -C $(LIBFT_PATH)

clean:
			@echo "Removing objects"
					$(RM) $(OBJS)
fclean:
			make clean
			cd $(LIBFT_PATH) && $(MAKE) fclean
			$(RM) $(NAME)

#msg

re:
		make fclean all
			@echo "All files has been deleted and recompiled"

.PHONY: clean fclean all re objects debug libft msg
