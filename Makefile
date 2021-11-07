NAME	=	libftprintf.a

SRCS	=	ft_printf.c ft_hexadecimal.c

HEADER	=	ft_printf.h

%.o : &.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -O $@false

OBJ	=	$(SRCS:%.c=%.o)


CC		=	gcc

FLAGS	=	-Wall -Werror -Wextra

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(MAKE) all -C ./libft
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJ)

clean	:
	@$(MAKE) clean -C ./libft
	@rm -f $(OBJ)

fclean	:	clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME)
re		: fclean all