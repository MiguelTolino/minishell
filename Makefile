UTHOR mmateo-t
#USAGE

#make          #compile all binary
#make clean		#remove all binaries
#make fclean		#remove all binaries and executable

SRCS_DIR:= srcs/
SRCS := $(wildcard $(SRCS_DIR)*.c)
OBJS := $(SRCS:%.c=%.o)
NAME:= minishell
CC:= gcc
CFLAGS:= -Wall -Werror -Wextra
LIBFT_PATH:= lib/libft
LIBFT_LIB:= -L$(LIBFT_PATH) $(LIBFT_PATH)/libft.a
RM :=	rm -rvf
DEBUG_FLAG:= -g

all:	libft $(NAME) msg

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(GNL) $(OBJS) -o $(NAME) $(MINILIBX) $(LM) $(LIBFT_LIB)
			
$(%.o): $(%.c)
			$(CC) -c $^ -o $@
					@echo "Creating objects"

libft:
			make -C $(LIBFT_PATH)

clean:
			@echo "Removing objects"
					$(RM) $(OBJS) $(OBJS_BONUS)
fclean:
			make clean
			cd $(LIBFT_PATH) && $(MAKE) fclean
			$(RM) $(NAME)
msg:

re:
		make fclean all
			@echo "All files has been deleted and recompiled"

.PHONY: clean fclean all re objects debug bonus libft msg
