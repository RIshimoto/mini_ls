NAME = ft_mini_ls
SRCS =\
	  ft_mini_ls.c\
	  fileinfo_cmp.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(MAKE) -C libft
	cp libft/libft.a .
	$(CC) -o $(NAME) -L. $(OBJS) -lft
			  
all: $(NAME)

clean:
	rm -f *.o
	$(MAKE) clean -C libft
	rm libft.a
	
fclean: clean
	rm -f $(NAME)
	$(MAKE) clean -C libft

re: fclean all
.PHONY: all clean fclean re .c.o
