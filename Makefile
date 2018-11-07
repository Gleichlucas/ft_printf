NAME	=	ft_printf.a
OBJECT = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra
LIB = -L libft/ -lft
INC = -I libft/
SRCS = main.c \
	ft_reset_fmt.c \
	ft_set_fmt.c \
	ft_percent.c \
	ft_s.c \
	ft_l_s.c \
	ft_p.c \
	ft_d.c \
	ft_l_d.c \
	ft_i.c \
	ft_o.c \
	ft_l_o.c \
	ft_u.c \
	ft_l_u.c \
	ft_x.c \
	ft_l_x.c \
	ft_c.c \
	ft_w_c.c \
	itoa_21.c \

all: $(NAME)

$(NAME) : $(OBJECT)
	@#make -C libft
	#@gcc $(CFLAGS) -o $(NAME) $(SRCS) $(LIB) $(INC)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)
	$(OBJECT): $(SRC)
	@gcc $(CFLAGS) -c $(SRC) $(LIB) $(INC)

clean:
	@#make -C libft/ clean
	@rm -f *.o

fclean: clean
	@#make -C libft/ fclean
	@rm -f $(NAME)
