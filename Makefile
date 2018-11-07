
C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_S = sources

DIR_O = temporary

HEADER = include

SOURCES = main.c \
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

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
		@make -C $(LIBFT)
		@cp libft/libft.a ./$(NAME)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
		@mkdir -p temporary
		@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
		@rm -f $(OBJS)
		@rm -rf $(DIR_O)
		@make clean -C $(LIBFT)

fclean: clean
		@rm -f $(NAME)
		@make fclean -C $(LIBFT)

re:	fclean all
