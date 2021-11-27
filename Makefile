NAME	=	libftprintf.a

SRCS	=	ft_printf.c ft_hexadecimal.c print.c

HEADER	=	ft_printf.h

OBJ		=	$(SRCS:.c=.o)

CC		=	gcc

RM		= @rm -f

FLAGS	= -Wall -Wextra -Werror -I $(HEADER)

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
			$(MAKE) all -C ./libft
			$(MAKE) bonus -C ./libft
			cp libft/libft.a $(NAME)
			@ar rcs $(NAME) $?

%.o:		%.c $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@

clean:
			@$(MAKE) fclean -C ./libft
			$(RM) $(OBJ) $(OBJ_B)

fclean	:	clean
			@$(MAKE) fclean -C ./libft
			@$(RM) $(NAME)

re		: 	fclean all